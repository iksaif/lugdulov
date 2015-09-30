# Lugdulo'V

Find stations and bikes in various bike sharing networks accross the world.
Most plugins are now broken but could easilly be fixed by anybody with some time.

## Build

### Qt Creator

Just open the project (with Lugdulov.pro or CMakeLists.txt) and it should works.

### qmake

At the moment, qmake does not handle Qt Mobility dependencies, you should really use
cmake instead.

$ lrelease
$ qmake
$ make

### cmake

$ mkdir build
$ cd build
$ cmake .. -DCMAKE_INSTALL_PREFIX=../
$ make
$ make install

## Maemo package

$ ln -s pkg/maemo5/debian
$ fakeroot dpkg-buildpackage