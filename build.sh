#!/bin/bash
# Script para compilar o projeto Arduino para Wokwi

# Criar diretório build se não existir
mkdir -p build

# Verificar se Arduino CLI está instalado
if ! command -v arduino-cli &> /dev/null; then
    echo "⚠️  Arduino CLI não encontrado!"
    echo ""
    echo "Opções para instalar:"
    echo ""
    echo "1. Com Homebrew (macOS):"
    echo "   /bin/bash -c \"\$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)\""
    echo "   brew install arduino-cli"
    echo ""
    echo "2. Download manual:"
    echo "   Visite: https://arduino.github.io/arduino-cli/"
    echo "   Baixe para macOS e adicione ao PATH"
    echo ""
    echo "3. Usar Arduino IDE:"
    echo "   - Abra sketch.ino no Arduino IDE"
    echo "   - Compile (Cmd+R)"
    echo "   - Copie o .hex gerado para build/sketch.ino.hex"
    echo ""
    echo "4. Instalação rápida (tentará baixar automaticamente):"
    read -p "Deseja tentar instalar automaticamente? (s/n) " -n 1 -r
    echo
    if [[ $REPLY =~ ^[SsYy]$ ]]; then
        echo "Baixando Arduino CLI..."
        ARDUINO_CLI_URL="https://downloads.arduino.cc/arduino-cli/arduino-cli_latest_macOS_64bit.tar.gz"
        curl -L -o /tmp/arduino-cli.tar.gz "$ARDUINO_CLI_URL"
        tar -xzf /tmp/arduino-cli.tar.gz -C /tmp
        mkdir -p ~/bin
        mv /tmp/arduino-cli ~/bin/
        export PATH="$HOME/bin:$PATH"
        echo "✓ Arduino CLI instalado em ~/bin/arduino-cli"
        echo "  Adicione ao seu ~/.zshrc: export PATH=\"\$HOME/bin:\$PATH\""
    else
        exit 1
    fi
fi

# Configurar Arduino CLI (se necessário)
arduino-cli core update-index
arduino-cli core install arduino:avr

# Instalar bibliotecas necessárias
arduino-cli lib install "TimerOne"
arduino-cli lib install "LiquidCrystal"

# Compilar o sketch para Arduino Mega 2560
# O Arduino CLI precisa que o arquivo .ino esteja em uma pasta com o mesmo nome
# Criamos uma pasta temporária chamada "sketch" e copiamos os arquivos
TEMP_SKETCH_DIR=$(mktemp -d)/sketch
mkdir -p "$TEMP_SKETCH_DIR"
cp sketch.ino "$TEMP_SKETCH_DIR/sketch.ino"
cp *.cpp *.h 2>/dev/null "$TEMP_SKETCH_DIR/" || true

# Compilar
arduino-cli compile --fqbn arduino:avr:mega "$TEMP_SKETCH_DIR" --output-dir build

# Mover o arquivo gerado para o nome esperado
if [ -f "build/sketch.ino.hex" ]; then
    # Arquivo já está com o nome correto
    :
elif [ -f "build/sketch.hex" ]; then
    mv build/sketch.hex build/sketch.ino.hex
fi

# Limpar pasta temporária
rm -rf "$(dirname $TEMP_SKETCH_DIR)"

# Verificar se a compilação foi bem-sucedida
if [ -f "build/sketch.ino.hex" ]; then
    echo "✓ Compilação bem-sucedida! Arquivo: build/sketch.ino.hex"
    echo "Agora você pode iniciar o simulador Wokwi."
else
    echo "✗ Erro na compilação. Verifique as mensagens acima."
    exit 1
fi
