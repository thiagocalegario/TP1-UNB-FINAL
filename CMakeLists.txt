cmake_minimum_required(VERSION 3.22)
project(Projeto2Tp1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Projeto2Tp1
        container.cpp
        container.h
        ControlesApresentacao.cpp
        ControlesApresentacao.h
        ControlesServico.cpp
        ControlesServico.h
        Dominios.cpp
        Dominios.h
        Entidades.cpp
        Entidades.h
        Interfaces.h
        main.cpp)
