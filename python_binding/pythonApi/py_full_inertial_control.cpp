
#include "../pybind11/include/pybind11/pybind11.h"
#include "../pybind11/include/pybind11/eigen.h"


#include "../include/passive_control.h"
#include <string>
#include <iostream>

namespace py = pybind11;

PYBIND11_MODULE(py_full_inertial_control, m)
{
    py::class_<PassiveControl>(m, "PassiveControl")
    .def(py::init<const std::string &, const std::string &>()) // constructor
    .def("updateRobot", &PassiveControl::updateRobot)
    .def("set_desired_pose", &PassiveControl::set_desired_pose)
    .def("set_desired_position", &PassiveControl::set_desired_position)
    .def("set_desired_quat", &PassiveControl::set_desired_quat)
    .def("set_desired_velocity", &PassiveControl::set_desired_velocity)
    .def("set_desired_inertia", &PassiveControl::set_desired_inertia)
    .def("set_pos_gains", &PassiveControl::set_pos_gains)
    .def("set_ori_gains", &PassiveControl::set_ori_gains)
    .def("set_null_pos", &PassiveControl::set_null_pos)
    .def("set_load", &PassiveControl::set_load)
    .def("getCmd", &PassiveControl::getCmd)
    .def("getEEpos", &PassiveControl::getEEpos)
    .def("getEEVel", &PassiveControl::getEEVel)
    .def("getEEAngVel", &PassiveControl::getEEAngVel)
    .def("getEEquat", &PassiveControl::getEEquat)
    .def("getTaskInertiaPos", &PassiveControl::getTaskInertiaPos)
    .def("getDirInertiaGrad", &PassiveControl::getDirInertiaGrad)
    .def("getSteinDivergenceGradient", &PassiveControl::getSteinDivergenceGradient)
    .def("jointToTaskInertia", &PassiveControl::jointToTaskInertia)
    .def("computeJointPositionQP", &PassiveControl::computeJointPositionQP);

}