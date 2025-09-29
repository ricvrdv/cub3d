# 42 - CUB3D

### REPOSITORY STRUCTURE
- `src`: Contains the source files for the program.
- `inc`: Contains the header file `cub3d.h` and the `libft` custom library.
- `test`: Contains valid and invalid maps to pass as argument when running the program.
- `textures`: Contains `.xpm` files to be used by the program to render the map walls.
- `Makefile`: Tells `make` how to compile and link a program.
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

----
🐸 Feel free to fork, clone, or contact me for questions or feedback. 
