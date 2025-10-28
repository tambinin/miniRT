# miniRT
![42 School Project](https://img.shields.io/badge/42-Project-white?style=flat&logo=42&color=000)

## Description
A basic Ray Tracing engine implementation in C.

### Requirements
- Unix-like operating system
- GCC compiler
- GNU Make
- MinilibX library

### Features
#### Mandatory
- Parse scene description files (.rt)
- Handle geometric primitives:
  - Sphere
  - Plane
  - Cylinder
- Light management:
  - Point light
  - Ambient light
- Camera positioning
- Basic materials and colors
- Window display using MinilibX

### Scene File Format (.rt)
```
# Resolution
R 1920 1080

# Ambient light
A 0.2 255,255,255

# Camera
C -50,0,20 0,0,1 70

# Light
L -40,0,30 0.7 255,255,255

# Sphere
sp 0,0,20 20 255,0,0

# Plane
pl 0,0,0 0,1.0,0 255,0,225

# Cylinder
cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
```

### Building
```bash
make        # Compile project
make clean  # Remove objects
make fclean # Remove objects and binary
make re     # fclean + all
```

### Usage
```bash
./miniRT scene.rt
```

### Controls
- ESC: Exit program
- WASD: Move camera
- Arrow keys: Rotate camera
- Space/Ctrl: Move up/down

### Resources
- The Ray Tracer Challenge. Jamis Buck

### Authors
- @tambinin (42 login)
