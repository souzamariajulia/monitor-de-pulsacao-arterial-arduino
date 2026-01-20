# Jogo de Pokémon para Arduino

Um jogo completo de captura de Pokémon inspirado nos clássicos da Game Boy, desenvolvido para Arduino Mega 2560. O jogo utiliza um kernel em tempo real para gerenciar múltiplos processos e implementa uma máquina de estados para controlar o fluxo do jogo.

## 🎮 Características

- **151 Pokémon** da primeira geração disponíveis para captura
- **Sistema de rotas** com diferentes Pokémon em cada rota
- **Pokedex completo** para rastrear Pokémon capturados
- **Sistema de captura** com probabilidade de sucesso
- **Interface LCD 16x2** para exibição de informações
- **Feedback visual** com LEDs (verde para sucesso, vermelho para falha)
- **Máquina de estados** para gerenciar o fluxo do jogo
- **Kernel em tempo real** com sistema de processos e interrupções

## 🎯 Estados do Jogo

O jogo possui os seguintes estados:

- **STATE_START** - Tela inicial
- **STATE_SELECT_POKEMON** - Seleção do Pokémon inicial
- **STATE_EXPLORING** - Exploração de rotas
- **STATE_POKEMON_FOUND** - Pokémon encontrado
- **STATE_CAPTURING** - Tentativa de captura
- **STATE_CAPTURE_SUCCESS** - Captura bem-sucedida
- **STATE_CAPTURE_FAILED** - Captura falhou
- **STATE_ROUTE_COMPLETE** - Rota completada
- **STATE_POKEDEX** - Visualização da Pokedex
- **STATE_VICTORY** - Vitória (todos os 151 capturados)

## 🕹️ Controles

- **Botão A** - Andar / Confirmar / Tentar capturar
- **Botão B** - Cancelar / Voltar
- **Botão SELECT** - Abrir Pokedex
- **Botão UP** - Navegar para cima
- **Botão DOWN** - Navegar para baixo

## 🏗️ Arquitetura

O projeto utiliza uma arquitetura modular com os seguintes componentes:

### Drivers (drv_*.cpp/h)
- `drv_button` - Gerenciamento de botões
- `drv_lcd` - Controle do display LCD
- `drv_led` - Controle dos LEDs
- `drv_sensor` - Gerenciamento de sensores

### Módulos Principais
- `kernel` - Kernel em tempo real com sistema de processos
- `state_machine` - Máquina de estados do jogo
- `display` - Gerenciamento de exibição no LCD
- `pokedex` - Sistema de Pokedex (bitfield para 151 Pokémon)
- `pokemon_db` - Banco de dados com informações dos Pokémon
- `ctrDrv` - Controlador de drivers

### Hardware

- **Arduino Mega 2560**
- **LCD 16x2** (conexão 4-bit)
- **5 Botões** (UP, DOWN, SELECT, A, B)
- **2 LEDs** (verde e vermelho com resistores de 1kΩ)

## 📦 Pré-requisitos

1. **Instalar a extensão Wokwi** no VS Code/Cursor
2. **Instalar Arduino CLI** (necessário para compilar):
   ```bash
   # macOS
   brew install arduino-cli
   
   # Linux
   sudo apt-get install arduino-cli
   
   # Windows
   # Baixe de: https://arduino.github.io/arduino-cli/
   ```

## 🔨 Compilação e Simulação

### Opção 1: Usar o script de build (Recomendado)

```bash
./build.sh
```

O script irá:
- Criar a pasta `build/`
- Instalar as bibliotecas necessárias (TimerOne, LiquidCrystal)
- Compilar o projeto para Arduino Mega 2560
- Gerar o arquivo `build/sketch.ino.hex`

### Opção 2: Compilar manualmente com Arduino CLI

```bash
# Criar diretório build
mkdir -p build

# Atualizar índices e instalar core
arduino-cli core update-index
arduino-cli core install arduino:avr

# Instalar bibliotecas
arduino-cli lib install "TimerOne"
arduino-cli lib install "LiquidCrystal"

# Compilar
arduino-cli compile --fqbn arduino:avr:mega sketch.ino --output-dir build
```

### Opção 3: Usar Arduino IDE

1. Abra o `sketch.ino` no Arduino IDE
2. Selecione a placa: **Arduino Mega 2560**
3. Instale as bibliotecas: **TimerOne** e **LiquidCrystal**
4. Compile o projeto (Ctrl+R / Cmd+R)
5. Copie o arquivo `.hex` gerado para `build/sketch.ino.hex`

## 🚀 Iniciar a Simulação

Após compilar com sucesso:

1. Pressione `F1` (ou `Cmd+Shift+P` no Mac)
2. Digite: **"Wokwi: Start Simulator"**
3. O simulador abrirá com:
   - Arduino Mega 2560
   - LCD 16x2
   - 5 botões (UP, DOWN, SELECT, A, B)
   - 2 LEDs (verde e vermelho)

## 📁 Estrutura de Arquivos

```
.
├── sketch.ino              # Arquivo principal do jogo
├── kernel.h/cpp           # Kernel em tempo real
├── state_machine.h/cpp    # Máquina de estados
├── display.h/cpp          # Gerenciamento de display
├── pokedex.h/cpp          # Sistema de Pokedex
├── pokemon_db.h/cpp       # Banco de dados de Pokémon
├── pokemon_types.h        # Tipos e estruturas de Pokémon
├── game_types.h           # Tipos e estruturas do jogo
├── ctrDrv.h/cpp           # Controlador de drivers
├── drv_*.h/cpp            # Drivers de hardware
├── wokwi.toml             # Configuração do simulador
├── diagram.json           # Definição do hardware e conexões
├── build.sh               # Script de compilação
└── libraries.txt          # Lista de bibliotecas necessárias
```

## ⚙️ Configuração do Hardware

### Conexões LCD (16x2)
- RS → Pino 12
- E → Pino 11
- D4 → Pino 5
- D5 → Pino 4
- D6 → Pino 3
- D7 → Pino 2
- VDD → 5V
- VSS → GND
- A → 5V (backlight)
- K → GND

### Botões
- UP → Pino 22
- DOWN → Pino 23
- SELECT → Pino 24
- A → Pino 25
- B → Pino 26
- Todos conectados ao GND quando pressionados

### LEDs
- LED Verde → Pino 20 (com resistor 1kΩ)
- LED Vermelho → Pino 21 (com resistor 1kΩ)

## 🐛 Troubleshooting

**Erro: "firmware binary not found"**
- Certifique-se de que compilou o projeto primeiro
- Verifique se o arquivo `build/sketch.ino.hex` existe

**Erro: "Firmware path must be a string"**
- Verifique se o arquivo `wokwi.toml` está correto
- Use aspas simples ou duplas nos caminhos

**Bibliotecas não encontradas**
- Execute: `arduino-cli lib install "TimerOne"` e `arduino-cli lib install "LiquidCrystal"`

**Problemas de compilação**
- Certifique-se de que está usando Arduino Mega 2560 como placa alvo
- Verifique se todas as bibliotecas estão instaladas corretamente

## 📝 Notas Técnicas

- O kernel utiliza um tick de 10ms (Timer1)
- O sistema de Pokedex utiliza um bitfield para economizar memória (19 bytes para 151 Pokémon)
- A máquina de estados gerencia todas as transições do jogo
- O sistema de rotas permite diferentes Pokémon em cada rota
- A probabilidade de captura é de 50% por padrão

## 🎮 Como Jogar

1. **Início**: O jogo começa na tela de seleção de Pokémon inicial
2. **Exploração**: Use o botão A para andar pelas rotas
3. **Encontros**: Após alguns passos, você pode encontrar um Pokémon
4. **Captura**: Pressione A para tentar capturar (50% de chance)
5. **Pokedex**: Pressione SELECT para ver seus Pokémon capturados
6. **Objetivo**: Capture todos os 151 Pokémon para vencer!

## 📄 Licença

Este projeto é um exemplo educacional de desenvolvimento de jogos para Arduino.
