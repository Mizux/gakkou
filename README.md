![Docker](https://github.com/Mizux/gakkou/workflows/Docker/badge.svg)
![Linux](https://github.com/Mizux/gakkou/workflows/Linux/badge.svg)
![MacOS](https://github.com/Mizux/gakkou/workflows/MacOS/badge.svg)
![Windows](https://github.com/Mizux/gakkou/workflows/Windows/badge.svg)

# Introduction
A simple app using CMake/C++/Qt.

# Project directory layout
Thus the project layout is as follow:

* [Makefile](Makefile) Script used to run CI/local test.

# Project Step

## Step 1: Environment Setup
First, setup a native development environment on various GNU/Linux distro
or using the official [alpine:edge](https://hub.docker.com/_/alpine/) docker image.  

You'll need:
- **cmake >= 3.14**,
- **gcc** or **clang** (with C++14 support) and
- **Qt >= 5**.

## Step 2: Configure

Simply run the following command and fill the form:
```sh
cmake -S. -Bbuild
```

note: need cmake >= 3.13.5 to use `-S` otherwise use the hidden option `-H` instead.

You should have something like this
```sh
$ cmake -S. -Bbuild
-- The CXX compiler identification is GNU 9.2.0
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /.../build
```

## Step 3: Build
Simply use:
```sh
cmake --build build -v
```

## Step 4: Launch the app
To run this app, you can use:
```sh
./build/bin/sumApp
```

# CI: Makefile/Docker testing
To test the build, there is a [Makefile](ci/Makefile) using the [alpine:edge](https://hub.docker.com/_/alpine/) docker image to test.

To get the help simply type:
```sh
make --directory=ci
```

For example to build the app:
```sh
make --directory=ci alpine_build
```

note: you can even run the app from alpine provided you have an `${HOME}/.Xauthority` file using the Make target `alpine_run`
