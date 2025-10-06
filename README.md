# 42 - CUB3D

### SUMMARY
Cub3D is a 3D graphics project inspired by Wolfenstein 3D, developed using the MiniLibX graphics library.

It introduces the fundamentals of computer graphics and real-time rendering through the [raycasting technique](https://lodev.org/cgtutor/raycasting.html) — a simplified yet powerful way to simulate 3D perspectives in a 2D world.

Built entirely from scratch in C, this project bridges the gap between mathematical theory and practical graphical application.

This project was developed collaboratively by me and [Daniela Padilha](https://github.com/Daniela-Padilha) as part of the 42 School curriculum.

<p align="center">
  <img src="https://github.com/ricvrdv/cub3d/blob/main/cub3d.gif" alt="Game snippet"
</p>

### OBJECTIVE
Build a first-person 3D engine capable of:
- Rendering a 3D environment based on a 2D map using raycasting.
- Displaying textured walls, floors, and ceilings.
- Handling player movement (forward, backward, strafe) and rotation.
- Supporting collision detection with walls and interactive elements (like doors).
- Parsing a configuration file (.cub) that defines:
  - Map layout
  - Wall textures (North, South, East, West)
  - Floor and ceiling colors

### KEY FEATURES
🧭 Raycasting engine using DDA (Digital Differential Analyzer) algorithm

🧍 Player controls: move (W, A, S, D), rotate (←, →)

🗺️ Custom map parser from .cub files

🧱 Textured walls (North, South, East, West)

🚪 Interactive doors — toggle open/close with a keypress (K)

🎨 Floor & ceiling color rendering

🪟 MiniLibX window rendering with pixel-perfect drawing

### REPOSITORY STRUCTURE
- `src`: Contains the source files for the program.
- `inc`: Contains the header file `cub3d.h` and the `libft` custom library.
- `maps`: Contains maps to pass as argument when running the program and a `test/` directory with valid and invalid maps to test.
- `textures`: Contains `.xpm` files to be used by the program to render the map walls.
- `Makefile`: Tells `make` how to compile and link the program.
- `README.md`: Project overview and usage instructions.

### USAGE
1. **Compile the program**
```bash
make
```

2. **Run the program with a map file (with an extension `.cub`):**
```bash
./cub3d /test/valid/<valid map file>
```

3. **You can test the program with invalid maps to see the error messages:**
```bash
./cub3d /test/invalid/<invalid map file>
```

### TEXTURES ATTRIBUTION
Wall textures: Torment Textures by Bradley D. (https://strideh.itch.io)

Door texture: Delven Textures by Bradley D. (https://strideh.itch.io)

----
🐸 Feel free to fork, clone, or contact me for questions or feedback. 
