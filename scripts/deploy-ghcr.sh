#!/usr/bin/env bash
# ==============================================================================
# Скрипт сборки и деплоя Docker-образов в GitHub Container Registry (ghcr.io)
# ==============================================================================
set -euo pipefail

REGISTRY="ghcr.io/foxstudiosteam/ldt-2026"
TARGET="${1:-all}"
TAG="${2:-latest}"

echo "=========================================================="
echo "📦 GHCR Image Deployer: ${REGISTRY}"
echo "Target: ${TARGET} | Tag: ${TAG}"
echo "=========================================================="

services=(
  "rust_viewer:./rust_listener/Dockerfile:."
  "rail_tuner_2d:./rail_tuner_2d/Dockerfile:."
  "rust_error_listener:./test_error_listener/Dockerfile:."
  "ros2_stream_player:./bag_player/Dockerfile:."
  "ros2_dataset_player:./dataset/Dockerfile:."
)

for item in "${services[@]}"; do
  IFS=":" read -r name dockerfile context <<< "${item}"

  if [ "${TARGET}" != "all" ] && [ "${TARGET}" != "${name}" ]; then
    continue
  fi

  full_tag="${REGISTRY}/${name}:${TAG}"
  latest_tag="${REGISTRY}/${name}:latest"

  echo ""
  echo "🚀 [1/2] Сборка ${name} (${dockerfile})..."
  docker build -f "${dockerfile}" -t "${full_tag}" -t "${latest_tag}" "${context}"

  echo "📤 [2/2] Пуш ${full_tag} в ghcr.io..."
  docker push "${full_tag}"
  if [ "${TAG}" != "latest" ]; then
    docker push "${latest_tag}"
  fi

  echo "✅ ${name} успешно опубликован в GHCR!"
done

echo ""
echo "🎉 Готово! Все выбранные контейнеры загружены в ghcr.io."
