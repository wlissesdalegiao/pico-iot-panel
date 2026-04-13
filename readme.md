# 📡 Painel IoT Multifuncional com Raspberry Pi Pico W

## 🎯 Objetivo
Desenvolver um sistema embarcado completo utilizando múltiplos periféricos do Pico W.

## ⚙️ Funcionalidades
- Leitura ADC (joystick)
- Sensor de temperatura interno (ADC 4)
- Controle PWM de LED
- Botão com interrupção
- Display SSD1306 (I2C)
- Comunicação Wi-Fi
- Simulação HTTP
- Logs via UART

## 🛠️ Dependências
- Pico SDK
- CMake
- VS Code

## 🚀 Instalação
```bash
git clone https://github.com/seuusuario/pico-iot-panel
cd pico-iot-panel
mkdir build
cd build
cmake ..
make