<div align="center">

# 🎮 cub3D

**A Wolfenstein-inspired raycasting engine written in C**

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Graphics](https://img.shields.io/badge/Graphics-MiniLibX-orange.svg)](#installation)
[![Technique](https://img.shields.io/badge/Rendering-Raycasting-red.svg)](#how-it-works)
[![Norm](https://img.shields.io/badge/42-Norminette-brightgreen.svg)](#)

[Leia em Português](README.pt.md)

*Built by [andrade950](https://github.com/andrade950) & [g0nca](https://github.com/g0nca)*

</div>

---

## 📌 Overview

`cub3D` renders a navigable 3D maze from a first-person perspective using the **raycasting** technique — the same foundational method behind Wolfenstein 3D (1992). A 2D grid map is cast into a textured 3D world entirely in real time, using only the **MiniLibX** library in C.

---

## 🎬 Demonstration

### Base version
![Base version](https://github.com/user-attachments/assets/458f38c8-28ba-4d6c-9c3e-b4c967e8ac99)

### Bonus version
![Bonus version](https://github.com/user-attachments/assets/e24f80b1-c9ee-4f0d-aa48-575c04700e3b)

---

## ⚙️ Features

### Base
- Raycasting 3D renderer
- Textured walls — North, South, East, West faces
- Configurable floor and ceiling colors
- Player movement and camera rotation
- Map parsing and validation from `.cub` files

### Bonus
- ✅ Wall collisions
- ✅ Minimap
- ✅ Animated sprites
- ✅ Doors (open and close with **E**)
- ✅ Mouse camera rotation
- ✅ Weapon with shoot animation (**Space**)
- ✅ Enemy system with dynamic spawning

---

## 🕹️ Controls

| Key | Action |
|-----|--------|
| `W` `A` `S` `D` | Move |
| `←` `→` | Rotate camera |
| `Mouse` *(bonus)* | Rotate camera |
| `E` *(bonus)* | Open / Close door |
| `Space` *(bonus)* | Shoot |
| `ESC` | Quit |

---

## 🔩 Bonus Systems

### Enemy spawning

Enemies are distributed proportionally across the map — the algorithm counts all walkable tiles (`0`) and assigns a random valid spawn position to each enemy. Larger maps get more enemies, keeping difficulty balanced regardless of map size.

### Door placement

Doors replace wall tiles (`1`) and are validated against two patterns to ensure they are always accessible:

```
# Horizontal corridor    # Vertical corridor
  1 0 1                    1 1 1
  1 D 1                    0 D 0
  1 0 1                    1 1 1
```

No two doors can be placed adjacent to each other, and every door must connect two walkable spaces.

---

## 📁 Project Structure

<details>
<summary><strong>Base version</strong></summary>

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
│   ├── events/       # Key handling and player movement
│   ├── init/         # Game and texture initialisation
│   ├── parse/        # Map parsing and validation
│   ├── render/       # Raycasting engine and wall rendering
│   ├── utils/        # Helpers and error handling
│   └── main.c
└── Makefile
```

</details>

<details>
<summary><strong>Bonus version</strong></summary>

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
│   ├── door_system/  # Door init, placement, and interaction
│   ├── enemy_system/ # AI, collision, line of sight, rendering
│   ├── events/       # Mouse/keyboard input and weapon animations
│   ├── init/         # Game state and texture loading
│   ├── parse/        # Deep .cub file and map validation
│   ├── render/       # Raycasting, minimap, and weapon rendering
│   ├── utils/        # Memory, colors, and pixel helpers
│   ├── main.c
│   └── main_aux.c
└── Makefile
```

</details>

---

## 🚀 Installation & Usage

### 1. Install MiniLibX

```bash
git clone https://github.com/42Paris/minilibx-linux.git
mv minilibx-linux 42cub3d/
```

### 2. Compile & Run

```bash
cd 42cub3d

# Base version
make
./cub3D maps/example.cub

# Bonus version
make bonus
./cub3D maps_bonus/example_bonus.cub
```

### 3. Memory check

```bash
valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/example.cub
```

---

## 📚 References

- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) — comprehensive raycasting guide
- [Permadi's Ray-Casting Tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/) — mathematical foundations
- [MiniLibX Docs](https://harm-smits.github.io/42docs/libs/minilibx) — MiniLibX usage guide
- [Wolfenstein 3D Source](https://github.com/id-Software/wolf3d) — original game reference

---
