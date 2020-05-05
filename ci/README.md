# CI: Makefile/Docker testing
To test the build on various distro, I'm using docker containers and a Makefile for orchestration.

pros:
* You are independent of third party CI runner config (e.g. github actions runners or Travis-CI VM images).
* You can run it locally on your linux system.
* Most CI provide runner with docker and Makefile installed (e.g. Travis-CI [minimal images](https://docs.travis-ci.com/user/languages/minimal-and-generic/).

cons:
* Only GNU/Linux distro supported.
* Could take few GiB (~10 GiB for all distros)
  * ~500MiB OS + C++/CMake tools

# Usage
To get the help simply type:
```sh
make
```

note: you can also use from top directory
```sh
make --directory=ci
```

## Run
Then you can test the image using:
```sh
make <distro>_run
```

# Alpine Image

From [alpine:latest](https://hub.docker.com/r/alpine/)
* [cmake](https://pkgs.alpinelinux.org/package/edge/main/x86_64/cmake)
* [make](https://pkgs.alpinelinux.org/package/edge/main/x86_64/make)
* [gcc](https://pkgs.alpinelinux.org/package/edge/main/x86_64/gcc)
* [clang](https://pkgs.alpinelinux.org/package/edge/main/x86_64/clang)
* [doxygen](https://pkgs.alpinelinux.org/package/edge/main/x86_64/doxygen)
* [graphviz](https://pkgs.alpinelinux.org/package/edge/main/x86_64/graphviz)
* [qt5-qtbase-dev](https://pkgs.alpinelinux.org/package/edge/community/x86_64/qt5-qtbase-dev)

