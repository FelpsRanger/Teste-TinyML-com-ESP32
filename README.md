# Projeto ESP32 com PlatformIO

Este projeto é baseado no ESP32, utilizando o framework Arduino e a plataforma PlatformIO. Ele está configurado para desenvolvimento avançado com suporte a PSRAM, debug detalhado, e preparado para bibliotecas como TensorFlow Lite e periféricos de áudio (I2S).

## 📦 Estrutura do Projeto

- `main.cpp`: Código principal do projeto.
- `platformio.ini`: Arquivo de configuração com suporte a múltiplas placas (ESP32, ESP32-S3, ESP32-C3), modos de compilação (debug/release), uso de PSRAM e opções avançadas de build.
- `lib/`: Diretório onde você pode adicionar bibliotecas locais, se necessário.

## 🚀 Requisitos

- [PlatformIO IDE](https://platformio.org/install)
- Placa ESP32 DevKit (ou compatível)
- Cabo USB para programação
- (Opcional) Debugger como o ESP-Prog, se for usar o modo debug avançado

## ⚙️ Configuração Suportada

- **CPU**: 240 MHz
- **Memória Flash**: QIO, 80 MHz
- **PSRAM**: Ativada (se suportada pela placa)
- **Velocidade de Upload**: 921600 bps
- **Velocidade do Monitor Serial**: 115200 bps
- **Modo Debug**: Habilitado via `esp-prog` (pino `EN`, `IO0`, `TX`, `RX`, etc.)

## 🛠️ Como Compilar e Carregar

```bash
# Compilar para ESP32 padrão
pio run

# Compilar e carregar
pio run -t upload

# Monitorar porta serial
pio device monitor

# Compilar no modo debug
pio run -e esp32dev-debug

# Compilar no modo release
pio run -e esp32dev-release
