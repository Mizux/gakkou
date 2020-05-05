Github-CI:
[![Build Status][github_docker_status]][github_docker_link]
[![Build Status][github_linux_status]][github_linux_link]
[![Build Status][github_macos_status]][github_macos_link]
[![Build Status][github_windows_status]][github_windows_link]

[github_docker_status]: https://github.com/Mizux/gakkou/workflows/Docker/badge.svg
[github_docker_link]: https://github.com/Mizux/gakkou/actions?query=workflow%3ADocker

[github_linux_status]: https://github.com/Mizux/gakkou/workflows/Linux/badge.svg
[github_linux_link]: https://github.com/Mizux/gakkou/actions?query=workflow%3ALinux

[github_macos_status]: https://github.com/Mizux/gakkou/workflows/MacOS/badge.svg
[github_macos_link]: https://github.com/Mizux/gakkou/actions?query=workflow%3AMacOS

[github_windows_status]: https://github.com/Mizux/gakkou/workflows/Windows/badge.svg
[github_windows_link]: https://github.com/Mizux/gakkou/actions?query=workflow%3AWindows

# Introduction
<nav for="project"> |
<a href="#codemap">Codemap</a> |
<a href="#build-project">Build</a> |
<a href="#test-project">Test</a> |
<a href="#install-project">Install</a> |
<a href="ci/README.md">CI</a> |
<a href="#license">License</a> |
</nav>

A simple app using [CMake](https://cmake.org/), C++ and Qt5.

# Codemap
Thus the project layout is as follow:

* [CMakeLists.txt](CMakeLists.txt) Top-level for [CMake](https://cmake.org/cmake/help/latest/) based build.
* [cmake](cmake) Subsidiary CMake files.

* [ci](ci) Root directory for continuous integration.

* [src](src) Source directory of the Application.

# Build Project
To build the C++ project, as usual:
```sh
cmake -S. -Bbuild -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release --target all -v
```

note: replace `all` by `ALL_BUILD` for non makefile generators

# Test Project
To test the C++ project, as usual:
```sh
cmake --build build --config Release --target test -v
```

note: replace `test` by `RUN_TESTS` for non makefile generators

# Install Project
To install the C++ project, as usual:
```sh
cmake --build build --config Release --target install -v
```

note: replace `install` by `INSTALL` for non makefile/xcode generators.
# License

Apache 2. See the LICENSE file for details.
