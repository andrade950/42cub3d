# cub3D

[Read in English](README.md)

## Descrição

**cub3D** é um projeto gráfico 3D inspirado no lendário **Wolfenstein 3D**, o primeiro First Person Shooter (FPS) da história. Utilizando a técnica de **raycasting**, este projeto renderiza um labirinto 3D realista a partir de uma perspetiva de primeira pessoa baseada num mapa 2D.

O objetivo é explorar os fundamentos de computação gráfica, compreender algoritmos de raycasting e criar um ambiente 3D interativo usando a biblioteca **MiniLibX** em C.

### Funcionalidades Principais

- **Renderização 3D** usando princípios de raycasting
- **Mapeamento de texturas** para paredes (Norte, Sul, Este, Oeste)
- **Cores personalizáveis** para chão e teto
- **Movimento do jogador** e rotação da câmera
- **Parsing e validação de mapas** a partir de ficheiros `.cub`
- **Gestão suave de janelas** e tratamento de eventos

---

## Instruções

### Pré-requisitos

Antes de compilar o projeto, é necessário instalar a biblioteca **MiniLibX**:
```bash
# Clonar o repositório MiniLibX
git clone https://github.com/42Paris/minilibx-linux.git minilibx-linux

# Mover para a pasta principal
mv minilibx-linux 42cub3d/
```

### Compilação
```bash
# Navegar para a pasta do projeto
cd 42cub3d

# Compilar o jogo base
make

# Executar o jogo com um mapa
./cub3D maps/example.cub

# Compilar com funcionalidades bonus
make bonus

# Executar a versão bonus
./cub3D maps_bonus/example_bonus.cub
```

### Controlos

| Tecla | Ação |
|-------|------|
| **W** | Mover para a frente |
| **A** | Mover para a esquerda |
| **S** | Mover para trás |
| **D** | Mover para a direita |
| **Seta Esquerda** | Rodar câmera para a esquerda |
| **Seta Direita** | Rodar câmera para a direita |
| **ESC** | Sair do jogo |
| **Rato** (bonus) | Rodar câmera |

---

## Demonstração

### Versão Base (Parte Obrigatória)

![Demo Versão Base](assets/demo_base.gif)

*Raycasting clássico com paredes texturizadas, cores de chão/teto e movimento suave.*

### Versão Bonus

![Demo Versão Bonus](assets/demo_bonus.gif)

*Melhorada com colisões de paredes, minimapa, sprites animados, portas e rotação com rato.*

---

## Funcionalidades Bonus

Todas as funcionalidades bonus foram implementadas:

- ✅ **Colisões com paredes**
- ✅ **Sistema de minimapa**
- ✅ **Portas** (podem abrir e fechar)
- ✅ **Sprites animados**
- ✅ **Rotação com rato**

---

## Assets

Exemplos de texturas e sprites usados no projeto:

<div align="center">

| Parede Norte | Parede Sul | Parede Este | Parede Oeste |
|--------------|------------|-------------|--------------|
| ![Norte](assets/textures/north.png) | ![Sul](assets/textures/south.png) | ![Este](assets/textures/east.png) | ![Oeste](assets/textures/west.png) |

| Porta Fechada | Porta Aberta | Sprite Animado |
|---------------|--------------|----------------|
| ![Porta Fechada](assets/textures/door_closed.png) | ![Porta Aberta](assets/textures/door_open.png) | ![Sprite](assets/textures/sprite_anim.gif) |

</div>

---

## Estrutura do Projeto
```
cub3d/
├── include/              # Ficheiros de cabeçalho
│   ├── cub3d.h
│   ├── render.h
│   ├── map.h
│   └── raycast.h
│
├── src/                  # Ficheiros fonte
│   ├── main.c
│   ├── init/             # Inicialização
│   ├── render/           # Raycasting e renderização
│   ├── events/           # Gestão de teclado/rato
│   ├── map/              # Parsing e validação de mapas
│   └── utils/            # Funções utilitárias
│
├── assets/               # Texturas e mapas
│   ├── textures/
│   └── maps/
│
├── libs/                 # Biblioteca MiniLibX
│
├── Makefile
└── README.md
```

---

## Recursos

### Documentação e Referências

- [Tutorial de Raycasting do Lode](https://lodev.org/cgtutor/raycasting.html) - Guia completo sobre raycasting
- [Código Fonte do Wolfenstein 3D](https://github.com/id-Software/wolf3d) - Código fonte do jogo original
- [Documentação MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx) - Guia de uso da MiniLibX
- [Tutorial de Ray-Casting por Permadi](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/) - Fundamentos matemáticos

---

## Gestão de Memória

O projeto foi testado com **Valgrind** para garantir que não há fugas de memória:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/example.cub
```

---

## Conformidade com Norminette

Todo o código segue os padrões de codificação da **42 Norminette**:
```bash
norminette src include
```

---

## Autores

- [**andrade950**](https://github.com/andrade950)
- [**g0nca**](https://github.com/g0nca)

---
