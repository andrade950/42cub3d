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
| **E** (bonus) | Open/Close door |
| **Space** (bonus) | Shoot weapon |

---

## Demonstration

### Base Version (Mandatory Part)

![Image](https://github.com/user-attachments/assets/458f38c8-28ba-4d6c-9c3e-b4c967e8ac99)

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

### Enemy Placement System

The enemy placement algorithm analyzes the map structure to determine valid spawn locations:

- **Dynamic Spawning**: The system counts all walkable spaces (represented by `0`) in the map
- **Proportional Distribution**: Enemies are randomly placed based on the total number of walkable tiles
- **Random Positioning**: Each enemy is assigned to a random valid position to ensure varied gameplay experiences

This approach ensures that larger maps have more enemies while maintaining balanced difficulty across different map sizes.

### Door Placement System

Doors are strategically placed using a sophisticated validation algorithm:

- **Wall-Based Placement**: Doors can only replace wall tiles (represented by `1`)
- **Adjacency Validation**: The system prevents two doors from being placed next to each other
- **Accessibility Check**: Each door must have a valid configuration where it connects walkable spaces

Valid door configurations must follow this pattern:
```
1 0 1
1 D 1
1 0 1
```
or
```
1 1 1
0 D 0
1 1 1
```

Where `D` represents the door, `1` represents walls, and `0` represents walkable space. This ensures that all doors are accessible and serve a functional purpose in the maze layout.

---

## Project Structure

Base Version (Mandatory Part)
```
cub3d/
├── assets/               # Textures
│   └── textures/
│
├── include/              # Header file (.h)
│   └── cub3d.h
│
├── libs/                 # Libraries used
|   ├── get_next_line/
│   └── libft/
│
├── maps/                 # Maps
|
├── minilibx-linux/       # MiniLibX library
|
├── src/                  # Source files (.c)
│   ├── events/           # Key handling and player movement
│   ├── init/             # Game and texture initialization
│   ├── parse/            # Map parsing and validation logic
│   ├── render/           # Raycasting engine and wall drawing
│   ├── utils/            # Helper functions and error handling
│   └── main.c            # Program entry point
│
└── Makefile
```

Bonus Version
```
cub3d/
├── assets/               # Textures
│   ├── door_textures/
│   ├── enemies/
│   ├── gun_textures/
│   └── textures/
│
├── include/              # Header file (.h)
│   └── cub3d_bonus.h
│
├── libs/                 # Libraries used
|   ├── get_next_line/
│   └── libft/
│
├── maps/                 # Maps
|
├── minilibx-linux/       # MiniLibX library
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
└── Makefile
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

## Authors

- [**andrade950**](https://github.com/andrade950)
- [**g0nca**](https://github.com/g0nca)

---
