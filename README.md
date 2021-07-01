# StackAttack
Game Stack Attack from Siemens A50 for Data Structures 1 of UFSCar Computer Engineering course

![Screenshot1](https://user-images.githubusercontent.com/68340334/124038901-4e9ce300-d9d8-11eb-9ec8-81c691d7e3e3.png)
![Screenshot2](https://user-images.githubusercontent.com/68340334/124038932-59577800-d9d8-11eb-81f7-1d630d821791.png)


# Game infrastructure
Released under BSD 2-Clause "Simplified" License

# Dependends on:
- C++ Development Kit
- Allegro5 [Game Library] (Development Files)
- CMake (3.15 or later)

# Process of compilation on:
- Unix/Posix:
0. Fix dependencies
```bash
$ pkg install devel/allegro5
$ pkg install allegro5
```
1. Clone repository and enter folder
```bash
$ git clone https://github.com/thursilverio/StackAttack.git
$ cd StackAttack
```
2. Create build directory and cmake
```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
```
3. Copy to source folder, delete build directory and enjoy
```bash
$ cp StackAttack ..
$ cd ..
$ rm -rf build
```

- Windows:
1. Download zip source code
2. Open with Visual Studio
3. Right click in the project
4. Manage NuGet Packages
5. Find and install Allegro5
6. Link library and addons
7. Compile and Enjoy
