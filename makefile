.PHONY: help setup up up-50m up-58m up-quiet up-quietplus rerun down logs play interactive tuner listen listen-raw stream

# Пресет детекции: Quiet (50m, высокая стабильность) или QuietPlus (58m, расширенная перспектива)
PRESET ?= Quiet

# Значения по умолчанию для плеера датасетов
BAG ?=
LOOP ?= --loop
RATE ?= 1.0
ARGS ?=

help:
	@echo "=================================================================="
	@echo "🛤️  LDT-2026 — Hesai Pandar128 Rail & Obstacle Detection Pipeline"
	@echo "=================================================================="
	@echo "Основные команды:"
	@echo "  make setup         — Подготовить окружение (.env и папку dataset)"
	@echo "  make tuner         — Запустить веб-панель тюнера (http://localhost:6080)"
	@echo "  make up            — Запустить детектор + Rerun Web (пресет Quiet 50m)"
	@echo "  make up-50m        — Запустить детектор с пресетом Quiet (50m)"
	@echo "  make up-58m        — Запустить детектор с пресетом QuietPlus (58m)"
	@echo "  make rerun         — Запустить Rerun Web Viewer (http://localhost:9090)"
	@echo "  make play          — Запустить воспроизведение датасета (auto/loop)"
	@echo "  make listen        — Слушать топик ошибок /rail/error (Rust CLI)"
	@echo "  make down          — Остановить все контейнеры"
	@echo ""
	@echo "Выбор пресета дальности и чувствительности:"
	@echo "  make up PRESET=Quiet        # Стабильный режим (дальность до 50м)"
	@echo "  make up PRESET=QuietPlus    # Расширенный режим (дальность до 58м, дефолт)"
	@echo ""
	@echo "Примеры воспроизведения датасетов:"
	@echo "  make play                             # Автовыбор датасета в цикле"
	@echo "  make play BAG=doubleT_obstacle        # Конкретный баг в цикле"
	@echo "  make play BAG=doubleT_obstacle LOOP=  # Однократный прогон (для тестов)"
	@echo "  make play RATE=2.0                    # На удвоенной скорости"
	@echo "=================================================================="

setup:
	@if [ ! -f .env ]; then cp .env.example .env && echo "✓ Created .env from .env.example"; else echo "✓ .env already exists"; fi

# 1. Интерактивная веб-панель (egui noVNC) — видит все датасеты в папке ./dataset
tuner: interactive
interactive:
	docker compose up -d rail_tuner_2d
	@echo "🌐 Web panel is LIVE! Open browser at: http://localhost:6080"

# 2. Основной детектор рельсов и препятствий + Rerun Web Viewer
up:
	DETECTION_PRESET="$(PRESET)" docker compose up -d rust_viewer rerun_viewer
	@echo "✓ Detector (rust_viewer) is running with preset [$(PRESET)]."
	@echo "🌐 Rerun Web Viewer is LIVE! Open browser at: http://localhost:9090"

up-50m: up-quiet
up-quiet:
	@$(MAKE) up PRESET=Quiet

up-58m: up-quietplus
up-quietplus:
	@$(MAKE) up PRESET=QuietPlus

# 2.1 Rerun Web Viewer отдельно
rerun:
	docker compose up -d rerun_viewer
	@echo "🌐 Rerun Web Viewer is LIVE! Open browser at: http://localhost:9090"

# 3. Плеер датасетов с умным автовыбором и кастомными флагами
play:
	BAG_NAME="$(BAG)" BAG_ARGS="$(LOOP) --rate $(RATE) $(ARGS)" docker compose run --rm ros2_dataset_player

# 4. Слушатель диагностических ошибок и телеметрии (/rail/error)
listen:
	docker compose run --rm rust_error_listener

listen-raw:
	docker compose run --rm rust_error_listener --raw

# 5. Стриминговый режим (Python player + Rust viewer + Error listener)
stream:
	DETECTION_PRESET="$(PRESET)" docker compose up -d ros2_stream_player rust_viewer rerun_viewer
	docker compose run --rm rust_error_listener

# 6. Остановка
down:
	docker compose down --remove-orphans

# 7. Логи
logs:
	docker compose logs -f