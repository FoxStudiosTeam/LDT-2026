#!/bin/bash
set -e

# Configuration
export DISPLAY=:99
export SCREEN_WIDTH=${SCREEN_WIDTH:-1600}
export SCREEN_HEIGHT=${SCREEN_HEIGHT:-900}
export SCREEN_DEPTH=${SCREEN_DEPTH:-24}

# XDG & Winit configuration for headless X11
export XDG_RUNTIME_DIR=${XDG_RUNTIME_DIR:-/tmp/runtime-root}
mkdir -p "$XDG_RUNTIME_DIR"
chmod 0700 "$XDG_RUNTIME_DIR"

export WINIT_UNIX_BACKEND=x11
export LIBGL_ALWAYS_SOFTWARE=${LIBGL_ALWAYS_SOFTWARE:-1}


echo "=========================================================="
echo "🚀 Starting Rail Tuner 2D Container Environment"
echo "=========================================================="

# 1. Start Xvfb (Virtual Framebuffer for X11)
echo "► Starting Xvfb on display ${DISPLAY} (${SCREEN_WIDTH}x${SCREEN_HEIGHT}x${SCREEN_DEPTH})..."
Xvfb ${DISPLAY} -screen 0 ${SCREEN_WIDTH}x${SCREEN_HEIGHT}x${SCREEN_DEPTH} +extension GLX +render -noreset &
XVFB_PID=$!

# Wait for Xvfb socket
for i in $(seq 1 50); do
    if xdpyinfo -display ${DISPLAY} >/dev/null 2>&1; then
        echo "✓ Xvfb is ready."
        break
    fi
    sleep 0.1
done

# 2. Start x11vnc
echo "► Starting x11vnc server on port 5900..."
x11vnc -display ${DISPLAY} -forever -nopw -shared -rfbport 5900 -quiet &
VNC_PID=$!

# 3. Setup noVNC and start websockify
echo "► Starting noVNC HTML5 Web Panel on port 6080..."

# Create convenient index.html redirect to vnc.html with autoconnect and remote resizing
cat << 'EOF' > /usr/share/novnc/index.html
<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="refresh" content="0; url=vnc.html?autoconnect=true&resize=remote&reconnect=true">
    <title>Rail Tuner 2D — Web Panel</title>
</head>
<body>
    <p>Redirecting to <a href="vnc.html?autoconnect=true&resize=remote&reconnect=true">Rail Tuner 2D Web Panel</a>...</p>
</body>
</html>
EOF

websockify --web /usr/share/novnc 6080 localhost:5900 &
WEBSOCKIFY_PID=$!

echo "=========================================================="
echo "🌐 Web panel is LIVE! Open your browser at:"
echo "   http://localhost:6080"
echo "=========================================================="

# Cleanup handler on container shutdown
cleanup() {
    echo "Stopping background services..."
    kill $WEBSOCKIFY_PID 2>/dev/null || true
    kill $VNC_PID 2>/dev/null || true
    kill $XVFB_PID 2>/dev/null || true
}
trap cleanup EXIT INT TERM

# 4. Launch rail_tuner_2d native GUI
echo "► Launching rail_tuner_2d..."
/app/rail_tuner_2d "$@"
