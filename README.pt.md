<div align="center">

# 🎮 cub3D

**Um motor de raycasting inspirado no Wolfenstein, escrito em C**

[![Linguagem](https://img.shields.io/badge/Linguagem-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Gráficos](https://img.shields.io/badge/Gráficos-MiniLibX-orange.svg)](#instalação)
[![Técnica](https://img.shields.io/badge/Renderização-Raycasting-red.svg)](#como-funciona)
[![Norm](https://img.shields.io/badge/42-Norminette-brightgreen.svg)](#)

[Read in English](README.md)

*Desenvolvido por [andrade950](https://github.com/andrade950) & [g0nca](https://github.com/g0nca)*

</div>

---

## 📌 Visão Geral

`cub3D` renderiza um labirinto 3D navegável em primeira pessoa usando a técnica de **raycasting** — o mesmo método por trás do Wolfenstein 3D (1992). Um mapa 2D em grelha é projetado num mundo 3D com texturas em tempo real, usando apenas a biblioteca **MiniLibX** em C.

---

## 🎬 Demonstração

### Versão base
![Versão base](https://github.com/user-attachments/assets/458f38c8-28ba-4d6c-9c3e-b4c967e8ac99)

### Versão bónus
![Versão bónus](https://github.com/user-attachments/assets/e24f80b1-c9ee-4f0d-aa48-575c04700e3b)

---

## ⚙️ Funcionalidades

### Base
- Motor 3D de raycasting
- Paredes texturizadas — faces Norte, Sul, Este, Oeste
- Cores configuráveis de chão e teto
- Movimento do jogador e rotação de câmara
- Parsing e validação de mapas a partir de ficheiros `.cub`

### Bónus
- ✅ Colisões com paredes
- ✅ Minimapa
- ✅ Sprites animados
- ✅ Portas (abrem e fecham com **E**)
- ✅ Rotação de câmara com rato
- ✅ Arma com animação de disparo (**Espaço**)
- ✅ Sistema de inimigos com spawn dinâmico

---

## 🕹️ Controlos

| Tecla | Ação |
|-------|------|
| `W` `A` `S` `D` | Mover |
| `←` `→` | Rodar câmara |
| `Rato` *(bónus)* | Rodar câmara |
| `E` *(bónus)* | Abrir / Fechar porta |
| `Espaço` *(bónus)* | Disparar |
| `ESC` | Sair |

---

## 🔩 Sistemas Bónus

### Spawn de inimigos

Os inimigos são distribuídos proporcionalmente pelo mapa — o algoritmo conta todos os tiles transitáveis (`0`) e atribui uma posição válida aleatória a cada inimigo. Mapas maiores recebem mais inimigos, mantendo a dificuldade equilibrada independentemente do tamanho.

### Colocação de portas

As portas substituem blocos de parede (`1`) e são validadas contra dois padrões para garantir que estão sempre acessíveis:

```
# Corredor horizontal    # Corredor vertical
  1 0 1                    1 1 1
  1 P 1                    0 P 0
  1 0 1                    1 1 1
```

Nenhuma porta pode ser colocada adjacente a outra, e cada porta tem de conectar dois espaços transitáveis.

---

## 📁 Estrutura do Projeto

<details>
<summary><strong>Versão base</strong></summary>

```
cub3d/
├── assets/
│   └── textures/
├── include/
│   └── cub3d.h
├── libs/
│   ├── get_next_line/
│   └── libft/
├── maps/
├── minilibx-linux/
├── src/
│   ├── events/       # Gestão de teclas e movimento do jogador
│   ├── init/         # Inicialização do jogo e texturas
│   ├── parse/        # Parsing e validação do mapa
│   ├── render/       # Motor de raycasting e renderização de paredes
│   ├── utils/        # Funções auxiliares e gestão de erros
│   └── main.c
└── Makefile
```

</details>

<details>
<summary><strong>Versão bónus</strong></summary>

```
cub3d/
├── assets/
│   ├── door_textures/
│   ├── enemies/
│   ├── gun_textures/
│   └── textures/
├── include/
│   └── cub3d_bonus.h
├── libs/
│   ├── get_next_line/
│   └── libft/
├── maps_bonus/
├── minilibx-linux/
├── src_bonus/
│   ├── door_system/  # Inicialização, colocação e interação de portas
│   ├── enemy_system/ # IA, colisão, linha de visão e renderização
│   ├── events/       # Input rato/teclado e animações de arma
│   ├── init/         # Estado do jogo e carregamento de texturas
│   ├── parse/        # Validação profunda de ficheiros .cub e mapas
│   ├── render/       # Raycasting, minimapa e renderização de arma
│   ├── utils/        # Memória, cores e manipulação de píxeis
│   ├── main.c
│   └── main_aux.c
└── Makefile
```

</details>

---

## 🚀 Instalação e Utilização

### 1. Instalar MiniLibX

```bash
git clone https://github.com/42Paris/minilibx-linux.git
mv minilibx-linux 42cub3d/
```

### 2. Compilar e Executar

```bash
cd 42cub3d

# Versão base
make
./cub3D maps/example.cub

# Versão bónus
make bonus
./cub3D maps_bonus/example_bonus.cub
```

### 3. Verificação de memória

```bash
valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/example.cub
```

---

## 📚 Referências

- [Tutorial de Raycasting do Lode](https://lodev.org/cgtutor/raycasting.html) — guia completo de raycasting
- [Tutorial de Ray-Casting por Permadi](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/) — fundamentos matemáticos
- [Documentação MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx) — guia de uso da MiniLibX
- [Código Fonte do Wolfenstein 3D](https://github.com/id-Software/wolf3d) — referência do jogo original

---
