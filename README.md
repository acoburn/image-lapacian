#Image Processing Toolkit

[![Build Status](https://travis-ci.org/acoburn/image-laplacian.png?branch=master)](https://travis-ci.org/acoburn/image-laplacian)

This project computes a laplacian of the gaussian (LoG) image convolution. This may be useful for identifying image similarities
that are scale- and rotation-invariant.

##Prerequisites

 This project requires:
  * Cross-platform Make (CMake) v2.6.2+
  * GNU Make or equivalent.
  * clang, gcc or an alternative, reasonably conformant C++11 compiler.
  * Boost C++ Libraries v1.46+
  * OpenCV Libraries
  * libjpeg 8

##Building

 This project uses the Cross-platform Make (`CMake`) build system. However, we
 have conveniently provided a wrapper configure script and Makefile so that
 the typical build invocation of `./configure` followed by `make` will work.
 For a list of all possible build targets, use the command `make help`.

##Installing

 Once the project has been built, execute `sudo make install`.

