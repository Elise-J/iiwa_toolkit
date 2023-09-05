//|
//|    Copyright (C) 2020 Learning Algorithms and Systems Laboratory, EPFL, Switzerland
//|    Authors:  Farshad Khadivr (maintainer)
//|    email:   farshad.khadivar@epfl.ch
//|    website: lasa.epfl.ch
//|
//|    This file is part of iiwa_toolkit.
//|
//|    iiwa_toolkit is free software: you can redistribute it and/or modify
//|    it under the terms of the GNU General Public License as published by
//|    the Free Software Foundation, either version 3 of the License, or
//|    (at your option) any later version.
//|
//|    iiwa_toolkit is distributed in the hope that it will be useful,
//|    but WITHOUT ANY WARRANTY; without even the implied warranty of
//|    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//|    GNU General Public License for more details.
//|
#include <Eigen/Dense>

#include "../include/passive_control.h"

#define No_JOINTS 7
#define No_Robots 1
#define TOTAL_No_MARKERS 2

//****************************************************
//****************************************************
int main (int argc, char **argv)
{
    std::unique_ptr<PassiveControl> _controller;
    _controller = std::make_unique<PassiveControl>("hello", "end_effector");

    return 0;
}