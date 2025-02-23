<h1 align="center">
  FdF (Fil de Fer) 🗺️
  <br>
  <img src="https://img.shields.io/badge/42-Project-lightgrey"/>
  <img src="https://img.shields.io/badge/Language-C-blue"/>
  <img src="https://img.shields.io/badge/Graphics-MinilibX-orange"/>
</h1>

<p align="center">
  <i>A 3D wireframe renderer that brings height maps to life</i>
</p>

---

## 🎯 About

FdF (*fil de fer* - French for "wireframe") is a graphics project that renders 3D wireframe models from height maps. It serves as an introduction to graphics programming, implementing concepts like:

- 3D projection
- Coordinate transformations
- Event handling
- Window management

## ✨ Features

🗺️ **Height Map Processing**
- Parses map files into 3D coordinates
- Supports variable map sizes
- Handles different elevation values

🎨 **Visualization**
- Isometric projection rendering
- Dynamic color gradients based on altitude
- Smooth wireframe connections

🎮 **Interactive Controls**
- Model rotation with arrow keys
- Zoom functionality
- Smooth user interaction

## 🚀 Usage

```bash
# Build the project
make

# Run with a map file
./fdf maps/42.fdf
```

### 🎮 Controls

| Key | Action |
|-----|--------|
| ↑→↓← | Rotate model |
| + / - | Zoom in/out |
| ESC | Exit program |

## 📝 Map Format

Maps must use the following format (rectangular grid of numbers):

```
0  0  0  0  0
0  2  2  2  0
0  2  3  2  0
0  2  2  2  0
0  0  0  0  0
```

Each number represents:
- X, Y: Position in the grid
- Value: Height (Z coordinate)

## 🛠️ Requirements

- MinilibX graphics library
- C compiler (gcc/clang)
- Make

## 📚 Resources

- [MinilibX Documentation](https://qst0.github.io/ft_libgfx/man_mlx.html)
- [42 School Project Page](https://42.fr)

---
<p align="center">
  Made with ❤️ by a 42 Student
</p>
