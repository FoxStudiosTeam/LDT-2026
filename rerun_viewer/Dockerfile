FROM python:3.10-slim

# Установка rerun-sdk с CLI версии 0.37.2 (соответствует версии rerun в rust_listener)
RUN pip install --no-cache-dir rerun-sdk==0.37.2

# Порт приема данных логгера (gRPC) и порт веб-сервера (HTTP)
EXPOSE 9876
EXPOSE 9090

# Запуск Web Viewer сервера:
# --serve-web хостит веб-клиент на порту 9090 и gRPC сервер на порту 9876
# --bind 0.0.0.0 делает интерфейсы доступными на всех сетевых адресах
ENTRYPOINT ["rerun"]
CMD ["--serve-web", "--bind", "0.0.0.0", "--port", "9876", "--web-viewer-port", "9090"]
