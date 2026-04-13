# Projeto FPGA Embarcatech - Sistema Embarcado com IoT e Microcontrolador RP2040 | 

## Índice

- [Visão Geral](#visão-geral)
- [Escopo do Projeto](#escopo-do-projeto)
- [Arquitetura do Sistema](#arquitetura-do-sistema)
  - [Hardware](#hardware)
  - [Firmware](#firmware)
- [Requisitos Funcionais](#requisitos-funcionais)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Estrutura do Repositório](#estrutura-do-repositório)
- [Instalação e Execução](#instalação-e-execução)
- [Resultados Esperados](#resultados-esperados)
- [Melhorias Futuras](#melhorias-futuras)
- [Licença](#licença)
- [Créditos](#créditos)

---

## Visão Geral

O Pico IoT Panel é um sistema embarcado desenvolvido para a plataforma BitDogLab (Raspberry Pi Pico W). O projeto integra a aquisição de dados analógicos (sensores de temperatura e joystick), controle de potência via modulação de largura de pulso (PWM) e conectividade Wi-Fi para transmissão de dados via protocolo HTTP. O sistema foi projetado com foco em modularização e eficiência, servindo como uma base sólida para aplicações de telemetria industrial e automação residencial.

---

## Escopo do Projeto

Escopo do Projeto
O projeto abrange o desenvolvimento completo do firmware para o microcontrolador RP2040, utilizando o SDK em C da Raspberry Pi. O sistema opera como uma Estação (STA) na rede Wi-Fi, processando sinais de entrada para controle de atuadores e feedback visual.

Monitoramento: Leitura de temperatura interna e posição de joystick.

Feedback: Interface gráfica em display OLED 128x64.

Controle: Sistema de alternância de modos (Manual/Automático) via botões físicos.

IoT: Envio de pacotes de dados para simulação de servidor em nuvem.  

---

## Arquitetura do Sistema

### Hardware 

| Componente           | Função |
|----------------------|--------|
| Microcontrolador RP2040 | Orquestração de Periféricos; Gestão de Interrupções e Interface; Processamento e Conversão de Dados; Conectividade IoT |
| Sensores             | Diferenciei o sensor "interno" do chip do joystick "externo" |
| Atuadores            | Controle de Potência (PWM); Interface de Saída |
| Interfaces (UART, Display, etc.) | barramento principal que conecta o seu display no código display.c |

---

### Firmware

O firmware foi desenvolvido seguindo o princípio da modularidade para facilitar a manutenção e escalabilidade:

- MMódulo de Hardware (ADC/PWM): Configuração de canais analógicos e frequências de clock para os LEDs. 
- MMódulo de Interface (Display): Driver para o controlador SSD1306, permitindo escrita de strings e buffers gráficos.
- MMódulo de Comunicação (Wi-Fi/HTTP): Implementação da stack TCP/IP (LwIP) para requisições de rede.  


---

## Requisitos Funcionais

- Leitura ADC (joystick)
- Sensor de temperatura interno (ADC 4)  
- Controle de atuadores  
- Botão com interrupção  
- Display SSD1306 (I2C)
- Comunicação Wi-Fi
- Simulação HTTP
- Logs via UART


---

## Tecnologias Utilizadas
- Linguagem: C (ISO C11)

- SDK: Raspberry Pi Pico SDK

- Protocolos: I2C, PWM, HTTP, TCP/IP

- Hardware: BitDogLab v1.2

- Ferramentas: VS Code, CMake, Git

---

## Estrutura do Repositório

```bash
📁 projeto_fpga_embarcatech
 ┣ 📂 src
 ┣ 📜 CMakeLists.txt
 ┣ 📜 README.md
 ┗ 📜 LICENSE
 ```

 ## Instalação e Execução

1. Clonar o repositório
git clone https://github.com/wlissesdalegiao/pico-iot-panel.git

2. Preparar o Ambiente
Abra o VS Code.

Certifique-se de que a extensão Raspberry Pi Pico está instalada.

Abra a pasta do projeto (pico-iot-panel).

3. Compilar o Firmware
Na barra inferior do VS Code, clique no botão Build (ícone de engrenagem) ou pressione F7.

Aguarde a geração da pasta build e do arquivo pico-iot-panel.uf2.

4. Upload para o Dispositivo
Conecte a placa BitDogLab ao USB mantendo o botão BOOTSEL pressionado.

Arraste o arquivo pico-iot-panel.uf2 (dentro da pasta build) para a unidade de disco RPI-RP2 que aparece no seu computador.


## Resultados Esperados

Espera-se que o sistema seja capaz de operar de forma autônoma por períodos extensos, mantendo a precisão das leituras térmicas e respondendo instantaneamente aos comandos do usuário, garantindo uma interface IoT fluida e informativa.

---

## Melhorias Futuras

- Integração com novos sensores  
- OImplementação de DMA: Para transferir dados do buffer para o display sem ocupar a CPU.  
- Dashboard Web: Criação de um servidor web real para visualizar os dados remotamente em gráficos.  

---

## Licença ***

Este projeto está licenciado sob os termos da licença MIT.

---

## Créditos

Desenvolvido como projeto final do programa Embarcatech | Fase 1.  

Autor: Wlisses Carvalho
