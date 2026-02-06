# cub3D

[Read in English](README.md)

## Descrição

**cub3D** é um projeto gráfico 3D inspirado no lendário **Wolfenstein 3D**, o primeiro First Person Shooter (FPS) da história. Usando a técnica de **raycasting**, este projeto renderiza um labirinto 3D realista a partir de uma perspetiva em primeira pessoa baseado num mapa 2D.

O objetivo é explorar os fundamentos de computação gráfica, compreender algoritmos de raycasting e criar um ambiente 3D interativo usando a biblioteca **MiniLibX** em C.

### Funcionalidades Principais

- **Renderização 3D** usando princípios de raycasting
- **Mapeamento de texturas** para paredes (Norte, Sul, Este, Oeste)
- **Cores personalizáveis** para chão e teto
- **Movimento do jogador** e rotação da câmara
- **Análise e validação de mapas** a partir de ficheiros `.cub`
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

# Compilar com funcionalidades bónus
make bonus

# Executar a versão bónus
./cub3D maps_bonus/example_bonus.cub
```

### Controlos

| Tecla | Ação |
|-------|------|
| **W** | Mover para frente |
| **A** | Mover para a esquerda |
| **S** | Mover para trás |
| **D** | Mover para a direita |
| **Seta Esquerda** | Rodar câmara para a esquerda |
| **Seta Direita** | Rodar câmara para a direita |
| **ESC** | Sair do jogo |
| **Rato** (bónus) | Rodar câmara |

---

## Demonstração

### Versão Base (Parte Obrigatória)

![Demo Versão Base](assets/demo_base.gif)

*Raycasting clássico com paredes texturizadas, cores de chão/teto e movimento suave.*

### Versão Bónus

![Demo Versão Bónus](assets/demo_bonus.gif)

*Melhorado com colisões de parede, minimapa, sprites animados, portas e rotação com rato.*

---

## Funcionalidades Bónus

Todas as funcionalidades bónus foram implementadas:

- ✅ **Colisões com paredes**
- ✅ **Sistema de minimapa**
- ✅ **Portas** (podem abrir e fechar)
- ✅ **Sprites animados**
- ✅ **Rotação com rato**

### Sistema de Colocação de Inimigos

O algoritmo de colocação de inimigos analisa a estrutura do mapa para determinar localizações válidas de spawn:

- **Spawn Dinâmico**: O sistema conta todos os espaços transitáveis (representados por `0`) no mapa
- **Distribuição Proporcional**: Os inimigos são colocados aleatoriamente com base no número total de espaços transitáveis
- **Posicionamento Aleatório**: Cada inimigo é atribuído a uma posição válida aleatória para garantir experiências de jogo variadas

Esta abordagem garante que mapas maiores têm mais inimigos, mantendo a dificuldade equilibrada em diferentes tamanhos de mapa.

### Sistema de Colocação de Portas

As portas são estrategicamente colocadas usando um algoritmo sofisticado de validação:

- **Colocação Baseada em Paredes**: As portas só podem substituir blocos de parede (representados por `1`)
- **Validação de Adjacência**: O sistema previne que duas portas sejam colocadas uma ao lado da outra
- **Verificação de Acessibilidade**: Cada porta deve ter uma configuração válida onde conecta espaços transitáveis

Configurações válidas de portas devem seguir este padrão:
```
1 0 1
1 P 1
1 0 1
```
ou
```
1 1 1
0 P 0
1 1 1
```

Onde `P` representa a porta, `1` representa paredes e `0` representa espaço transitável. Isto garante que todas as portas são acessíveis e servem um propósito funcional no layout do labirinto.

---

## Estrutura do Projeto

Versão Base (Parte Obrigatória)
```
cub3d/
├── assets/               # Texturas e mapas
│   ├── textures/
│   └── maps/
│
├── include/              # Ficheiros de cabeçalho (.h)
│   ├── cub3d.h
│   ├── render.h
│   ├── map.h
│   └── raycast.h
│
├── libs/                 # Biblioteca MiniLibX
│
├── src/                  # Ficheiros fonte (.c)
│   ├── events/           # Tratamento de teclas e movimento do jogador
│   ├── init/             # Inicialização do jogo e texturas
│   ├── parse/            # Lógica de análise e validação de mapas
│   ├── render/           # Motor de raycasting e desenho de paredes
│   ├── utils/            # Funções auxiliares e tratamento de erros
│   └── main.c            # Ponto de entrada do programa
│
├── Makefile
└── README.md
```

Versão Bónus
```
cub3d/
├── assets/               # Texturas e mapas
│   ├── textures/
│   └── maps/
│
├── include/              # Ficheiros de cabeçalho (.h)
│
├── libs/                 # Biblioteca MiniLibX
│
├── src_bonus/            # Ficheiros fonte bónus (.c)
│   ├── door_system/      # Inicialização, colocação e lógica de interação de portas
│   ├── enemy_system/     # Lógica de IA, colisão, linha de visão e renderização de inimigos
│   ├── events/           # Inputs (Rato/Teclado), movimento e animações de armas
│   ├── init/             # Estado do jogo e carregamento de texturas
│   ├── parse/            # Validação profunda de ficheiros .cub e layouts de mapas
│   ├── render/           # Motor de raycasting, paredes, minimapa e renderização de armas
│   ├── utils/            # Gestão de memória (free), cores e manipulação de pixels
│   ├── main.c            # Loop principal do programa
│   └── main_aux.c        # Funções auxiliares principais
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
