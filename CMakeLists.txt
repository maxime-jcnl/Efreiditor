cmake_minimum_required(VERSION 3.25)
project(Projet_C_vMac C)

set(CMAKE_C_STANDARD 11)

add_executable(Projet_C_vMac main.c assets/area.c assets/area.h assets/function.c assets/function.h assets/id.c assets/id.h assets/struct.h assets/pixel.c assets/pixel.h assets/commands.c assets/commands.h)
