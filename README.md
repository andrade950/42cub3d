# cub3D

[Leia em Português](README.pt.md)

## Description

**cub3D** is a 3D graphical project inspired by the legendary **Wolfenstein 3D**, the first-ever First Person Shooter (FPS). Using the **raycasting** technique, this project renders a realistic 3D maze from a first-person perspective based on a 2D map.

The goal is to explore the fundamentals of computer graphics, understand raycasting algorithms, and create an interactive 3D environment using the **MiniLibX** library in C.

### Key Features

- **3D rendering** using raycasting principles
- **Texture mapping** for walls (North, South, East, West)
- **Customizable floor and ceiling colors**
- **Player movement** and camera rotation
- **Map parsing and validation** from `.cub` files
- **Smooth window management** and event handling

---

## Instructions

### Prerequisites

Before compiling the project, you need to install the **MiniLibX** library:
```bash
# Clone the MiniLibX repository
git clone https://github.com/42Paris/minilibx-linux.git minilibx-linux

# Move it to the main folder
mv minilibx-linux 42cub3d/
```

### Compilation
```bash
# Navigate to the project folder
cd 42cub3d

# Compile the base game
make

# Run the game with a map
./cub3D maps/example.cub

# Compile with bonus features
make bonus

# Run the bonus version
./cub3D maps_bonus/example_bonus.cub
```

### Controls

| Key | Action |
|-----|--------|
| **W** | Move forward |
| **A** | Move left |
| **S** | Move backward |
| **D** | Move right |
| **Left Arrow** | Rotate camera left |
| **Right Arrow** | Rotate camera right |
| **ESC** | Exit game |
| **Mouse** (bonus) | Rotate camera |

---

## Demonstration

### Base Version (Mandatory Part)

![Base Version Demo](assets/demo_base.gif)

*Classic raycasting with textured walls, floor/ceiling colors, and smooth movement.*

### Bonus Version

![Bonus Version Demo](assets/demo_bonus.gif)

*Enhanced with wall collisions, minimap, animated sprites, doors, and mouse rotation.*

---

## Bonus Features

All bonus features have been implemented:

- ✅ **Wall collisions**
- ✅ **Minimap system**
- ✅ **Doors** (can open and close)
- ✅ **Animated sprites**
- ✅ **Mouse rotation**

---

## Assets

Sample textures and sprites used in the project:

<div align="center">

| North Wall | South Wall | East Wall | West Wall |
|------------|------------|-----------|-----------|
| ![North](assets/textures/north.png) | ![South](assets/textures/south.png) | ![East](assets/textures/east.png) | ![West](assets/textures/west.png) |

| Door Closed | Door Open | Animated Sprite |
|-------------|-----------|-----------------|
| ![Door Closed](assets/textures/door_closed.png) | ![Door Open](assets/textures/door_open.png) | ![Sprite](assets/textures/sprite_anim.gif) |

</div>

---

## Project Structure

Base Version (Mandatory Part)
```
cub3d/
├── assets/               # Textures and maps
│   ├── textures/
│   └── maps/
│
├── include/              # Header files (.h)
│   ├── cub3d.h
│   ├── render.h
│   ├── map.h
│   └── raycast.h
│
├── libs/                 # MiniLibX library
│
├── src/                  # Source files (.c)
│   ├── events/           # Key handling and player movement
│   ├── init/             # Game and texture initialization
│   ├── parse/            # Map parsing and validation logic
│   ├── render/           # Raycasting engine and wall drawing
│   ├── utils/            # Helper functions and error handling
│   └── main.c            # Program entry point
│
├── Makefile
└── README.md
```

Bonus Version
```
cub3d/
├── assets/               # Textures and maps
│   ├── textures/
│   └── maps/
│
├── include/              # Header files (.h)
│
├── libs/                 # MiniLibX library
│
├── src_bonus/            # Bonus source files (.c)
│   ├── door_system/      # Door initialization, placement, and interaction logic
│   ├── enemy_system/     # AI logic, collision, line of sight, and enemy rendering
│   ├── events/           # Inputs (Mouse/Keyboard), movement, and weapon animations
│   ├── init/             # Game state and texture loading
│   ├── parse/            # Deep validation of .cub files and map layouts
│   ├── render/           # Raycasting engine, walls, minimap, and weapon rendering
│   ├── utils/            # Memory management (free), colors, and pixel manipulation
│   ├── main.c            # Main program loop
│   └── main_aux.c        # Auxiliary main functions
│
├── Makefile
└── README.md
```

---

## Resources

### Documentation & References

- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) - Comprehensive guide to raycasting
- [Wolfenstein 3D Source Code](https://github.com/id-Software/wolf3d) - Original game source
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx) - MiniLibX usage guide
- [Ray-Casting Tutorial by Permadi](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/) - Mathematical foundations

---

## Memory Management

The project has been tested with **Valgrind** to ensure no memory leaks:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/example.cub
```

---

## Norminette Compliance

All code follows the **42 Norminette** coding standards:
```bash
norminette src include
```

---

## Autores

- [**andrade950**](https://github.com/andrade950)
- [**g0nca**](https://github.com/g0nca)

---
