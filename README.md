# FireStack
- Personal Cpp Codebase Project

# Build Commands
- mingw32-make within .\build

# Removing source files
- Powershell:
- cd C:\Developer\Projects\FireStack
- Remove-Item -Recurse -Force .\build
- cmake -G "MinGW Makefiles" -S . -B build
- Terminal:
- cd .\build
- mingw32-make

# Removing current build
- Powershell:
- cd C:\Developer\Projects\FireStack
- Remove-Item -Recurse -Force .\build
- cmake -G "MinGW Makefiles" -S . -B build

# Documentation
### Doxygen Formatting
<img width="508" height="280" alt="image" src="https://github.com/user-attachments/assets/95e9106e-a463-47a9-93c7-75bc6944343f" />

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