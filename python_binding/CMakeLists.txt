cmake_minimum_required(VERSION 3.1.0)

set (CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")


project(wrap_passive_control)

set(PY_PROJECT py_passive_inertial_control)
set(CPP_LIBRARY cpp_passive_inertial_control)


find_package(pybind11 REQUIRED)
find_package(Eigen3 QUIET NO_CMAKE_PACKAGE_REGISTRY)
if(Eigen3_FOUND)
  set(FIND_EIGEN "find_package(Eigen3 REQUIRED NO_CMAKE_PACKAGE_REGISTRY)")
else()
  find_package(Eigen3 MODULE REQUIRED)
  set(FIND_EIGEN "find_package(Eigen3 MODULE REQUIRED)")
endif()

find_package(RBDyn REQUIRED )
find_package(mc_rbdyn_urdf REQUIRED )
find_package(PkgConfig)

## Specify locations of header files
set(HEADERS_FOLDER  "${CMAKE_CURRENT_SOURCE_DIR}/include")
## Specify locations of source files
set(SRC_FOLDER      "${CMAKE_CURRENT_SOURCE_DIR}/src")

set(H_FILES
    ${HEADERS_FOLDER}/passive_control.h
    ${HEADERS_FOLDER}/iiwa_tools.h
    ${HEADERS_FOLDER}/Utils.h
    ${HEADERS_FOLDER}/Utils.cpp
    ${HEADERS_FOLDER}/cvxgen/iiwa_ik_cvxgen.hpp
    )
    
set(SRCS
    ${SRC_FOLDER}/passive_control.cpp
    ${SRC_FOLDER}/iiwa_tools.cpp
    )

add_library(${CPP_LIBRARY} SHARED ${H_FILES} ${SRCS})
target_compile_definitions(${CPP_LIBRARY} PUBLIC _USE_MATH_DEFINES)
target_link_libraries(${CPP_LIBRARY} PUBLIC RBDyn mc_rbdyn_urdf)

if(TARGET Eigen3::Eigen)
  target_link_libraries(${CPP_LIBRARY} PUBLIC Eigen3::Eigen)
else()
  target_include_directories(${CPP_LIBRARY} SYSTEM PUBLIC "${EIGEN3_INCLUDE_DIR}")
endif()


install(FILES ${H_FILES} DESTINATION include/${CPP_LIBRARY})
install(TARGETS ${CPP_LIBRARY}
  EXPORT ${CPP_LIBRARY}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

# ________________ PYBIND ________________


add_subdirectory(pybind11)
pybind11_add_module(${PY_PROJECT} pythonApi/py_passive_inertial_control.cpp)
target_include_directories(${PY_PROJECT} PUBLIC ${RBDyn_INCLUDE_DIRS} ${mc_rbdyn_urdf_INCLUDE_DIRS})

target_link_libraries(${PY_PROJECT} PUBLIC Eigen3::Eigen pybind11::module ${CPP_LIBRARY} )
set_target_properties(${PY_PROJECT} PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}" SUFFIX "${PYTHON_MODULE_EXTENSION}")
set_target_properties(${PY_PROJECT} PROPERTIES OUTPUT_NAME ${PY_PROJECT})