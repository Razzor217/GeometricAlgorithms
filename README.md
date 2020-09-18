# Geometric Algorithms

This library provides data structures and algorithms for geometric problems. 
These include problems such as finding intersections between a set of two-dimensional line segments.

## Plane Sweep

Plane Sweep algorithms move a horizontal sweep line from top to bottom 
by storing line segments which intersect the sweep line. Only those segments 
are considered when checking for line-line intersections.

# Build

This project depends on the [Eigen Library](http://eigen.tuxfamily.org/) and 
the [Boost Unit Test Framework](https://www.boost.org). 
You can build the project by running `cmake` and `make` in the build directory:

```
cd <GeometricAlgorithms-DIR>
mkdir build
cd build
cmake ..
make
```

You can run the provided test modules by running `ctest` in the build directory:

```
cd build
ctest
```
