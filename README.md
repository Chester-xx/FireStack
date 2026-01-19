# FireStack
- Personal C++ Codebase.
- Data structures, core functions and other tools integrated to help me build C++ applications.

# New Project
### Qt Application rendering & displaying glTF files (from .blend)
- Recently started exploring the use of blender for modelling
- Thought it would be a cool idea to make a c++ app that can display a 3d view of an exported .blend file in glTF format
- Either Qt 3D or Qt + OpenGL
- Main Focal Areas:
    - Qt Signals & Slots + QML
    - OpenGL + glTF pipeline
    - [VBOs & VAOs](https://medium.com/@deyan.sirakov2006/the-definitive-guide-to-opengl-vbos-vaos-and-ebos-6193ab13ccc5)
    - [Camera Matrices](https://en.wikipedia.org/wiki/Camera_matrix)

# Build Outline
- Open **FireStack** folder in Visual Studio 2022
- Active C++ toolchain is **MSVC x64** (Migrated from mingw32)
- **Qt 6.10.1 msvc_x64** Required and linked with CMake for BlendViewer
- Build Output to `out/build/x64-(Debug/Release)`

# Removing Build Files
- Powershell:
- cd C:\Developer\Projects\FireStack
- Remove-Item -Recurse -Force .\out\build

# Git Ignore
- `.vs/` & `out/` have been removed from tracking

# Documentation
### Doxygen Formatting
<img width="508" height="280" alt="image" src="https://github.com/user-attachments/assets/95e9106e-a463-47a9-93c7-75bc6944343f" />
