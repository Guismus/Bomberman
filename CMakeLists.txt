# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
FIND_PACKAGE(raylib REQUIRED)

# Notre projet est étiqueté hello
project(hello)

# Crée des variables avec les fichiers à compiler
set(SRCS main.cpp)

include_directories(${CMAKE_SOURCE_DIR}/header)

# On indique que l'on veut un exécutable "hello" compilé à partir des fichiers décrits par les variables SRCS et HEADERS
add_executable(hello ${SRCS})

TARGET_LINK_LIBRARIES(hello raylib)