<link rel="stylesheet" href="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/devicon.min.css">

# `point-plane-cpp`

A minimal, lightweight, terminal-based `C++` utility for performing fundamental `2D` and `3D` coordinate geometry operations on points, vectors, planes and triangles

## 🐙 About

`point-plane-cpp` is a `terminal` based project written in `C++` that focuses on
implementing core concepts of `2D` and `3D` coordinate geometry.

The project provides a guided `command-line interface (CLI)` that walks users
through available geometric operations, making it suitable both as a learning
tool and as a practical reference for translating mathematical geometry concepts
into clean, reusable `C++` code.

## 🛸 Features

- works with `2D` and `3D` points
- vector operations (`arithmetic`, `dot product` and `cross product`)
- plane representation in `2D` and `3D` space
- `distance`, `area of triangle` and `collinear` calculations
- modular and object-oriented `C++` design
- `terminal` based

> **NOTE :**  
> The current `CLI` is fully functional and instructional, guiding users through
> all supported operations. Improvements such as enhanced formatting,
> terminal colors, and richer inline documentation may be introduced in
> future iterations.

## 🏗️ Tools & Tech Used

<p align="left">
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/cplusplus/cplusplus-original.svg" width="60" alt="C++" /><img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/gcc/gcc-original.svg" width="60" alt="gcc" />
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/bash/bash-original.svg" width="60" alt="Bash" />
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/vscode/vscode-original.svg" width="60" alt="VS Code" /><img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/git/git-original.svg" width="60" alt="Git" /><img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/github/github-original.svg" width="60" alt="GitHub" /></p>

## ⚙️ Project Requirements

- `C++17+`
- Any standard `C++` compiler (`gcc` / `clang` / `MSVC`)
- `terminal` or `command line interface`

## 🛠️ Project Setup

### 1. Navigate To The Directory Where You Want To Clone The Project Repository (example: `Desktop`)

```bash
cd ~/Desktop
```

### 2. Clone the Project Repository

```bash
git clone https://github.com/manakcodes/point-plane-cpp.git
```

### 3. Navigate To The Project Repository

```bash
cd path-to/point-plane-cpp/
```

### 4. Run the following command (to build the project)

```bash
make
```

### 5. Run the following command (to run the project)

```bash
make run
```

### 6. After Using The Project Run The Following Command (to remove build artifacts)

```bash
make clean
```

## 🌲 Project Tree

.
├── cli
│ ├── cli.hpp
│ ├── io_2d.hpp
│ ├── io_3d.hpp
│ └── io_utility.hpp
├── include
│ ├── point2d.hpp
│ ├── point2dcore.hpp
│ ├── point3d.hpp
│ ├── point3dcore.hpp
│ ├── pointplanecpp.hpp
│ └── utility.hpp
├── Main.cpp
├── README.md <- you are here :)
└── tests
├── test2d.hpp
├── test3d.hpp
└── tests.cpp

4 directories, 15 files

```

```

## 🪪 LICENSE

This project is licensed under [MIT License](https://github.com/manakcodes/point-plane-cpp/blob/d7a594c7097ad94353235e18dc8d53f57d77a060/LICENSE).
