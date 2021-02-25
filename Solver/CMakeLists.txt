cmake_minimum_required(VERSION 3.1.0)

project(csp_solveur)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)

file(GLOB fichier_src CONFIGURE_DEPENDS
    "*.hh"
    "*.cc"
    "*.cpp"
)


add_executable(${PROJECT_NAME} ${fichier_src} ${recur_src})
