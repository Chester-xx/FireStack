# FireStack
- New Cpp Codebase Project

# Build Commands
- mingw32-make within .\build

# Removing source files
- Powershell:
- cd C:\FireStack
- Remove-Item -Recurse -Force .\build
- cmake -G "MinGW Makefiles" -S . -B build
- Terminal:
- cd .\build
- mingw32-make

# Removing current build
- Powershell:
- cd C:\FireStack
- Remove-Item -Recurse -Force .\build
- cmake -G "MinGW Makefiles" -S . -B build
