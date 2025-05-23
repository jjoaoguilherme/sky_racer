# ✈️ Sky^Racer

**Sky^Racer** é um jogo de terminal desenvolvido em linguagem C como projeto final da disciplina de **Programação Imperativa e Funcional**. O jogador controla uma aeronave que deve desviar e atirar em meteoros, buscando sobreviver o maior tempo possível e alcançar a melhor pontuação.

## 🎮 Sobre o Jogo

O objetivo é **sobreviver o maior tempo possível**, desviando ou destruindo meteoros que surgem na tela.  
A pontuação aumenta conforme o tempo de sobrevivência e a destruição dos obstáculos.  
Ao final da partida, o nome e a pontuação do jogador são salvos em um **ranking**, incentivando a competição entre participantes.

## 🤝 Equipe

<table>
  <tr>
    <td align="center">
      <sub><b>João Guilherme Omena</b></sub><br/>
      jgbof@cesar.school
    </td>
    <td align="center">
      <sub><b>Lucas Samuel Pereira Alves</b></sub><br/>
      lspa@cesar.school
    </td>
    <td align="center">
      <sub><b>Rafael Lyra Costa</b></sub><br/>
      rlc3@cesar.school
    </td>
  </tr>
</table>

## 🔨 Ferramentas

[![Apresentação](https://img.shields.io/badge/Apresentação-084ea3?style=for-the-badge&logo=canva&logoColor=white)](https://docs.google.com/document/d/1qxWeY8sgxpPxejGPDY0ZJitrgwIRGgKHSkECFL7OSgg/edit?usp=sharing)
[![YouTube](https://img.shields.io/badge/YouTube-b50404?style=for-the-badge&logo=youtube&logoColor=white)](https://youtube.com/playlist?list=PLql-8xGSZOnC54kFiA03umnxNXTRMA4z9&si=_I32WK-SXjsJZ-Jb)


## 🧠 Funcionalidades

- Controle da nave com as setas ⬅️ ➡️ ⬆️  
- Disparo com a barra de espaço (SPACE)  
- Meteoros dinâmicos com diferentes tamanhos (ASCII Art)  
- Detecção de colisões entre tiros, meteoros e nave  
- Sistema de pontuação com **ranking persistente** em `.txt`  
- Interface em terminal usando **ncurses**

## ⚙️ Compilação e Execução

### ✅ Pré-requisitos

- Linux ou WSL (Windows Subsystem for Linux)
- Biblioteca **ncurses** instalada:

```bash
sudo apt-get update
sudo apt-get install libncurses5-dev libncursesw5-dev
🔧 Passos para rodar o jogo
bash
Copiar
Editar
cd ~/sky_racer            # Acesse a pasta do projeto
make clean                # Remove arquivos antigos
make                      # Compila o jogo
chmod +x abrir_terminal.sh  # Dá permissão ao script
make run                  # Executa o jogo em nova janela
⚠️ Importante: Ao rodar, duas janelas serão abertas. Use a segunda janela (a do jogo) para acessar o menu.

📁 Estrutura do Projeto
bash
Copiar
Editar
sky_racer/
├── src/                # Código-fonte principal (.c e .h)
├── cli-lib/            # Biblioteca CLI (ncurses)
├── assets/             # Arquivo de ranking (ranking.txt)
├── abrir_terminal.sh   # Script de execução
├── Makefile            # Automação de compilação
└── README.md           # Este arquivo
