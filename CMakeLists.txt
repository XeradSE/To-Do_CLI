cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(To-Do_CLI)

# Standard C++
set(CMAKE_CXX_STANDARD 17)

# Création de l'exécutable
add_executable(To-Do_CLI ./src/main.cpp
                        ./src/CLI.cpp
                        ./src/Storage.cpp
                        ./src/Task.cpp
                        ./src/TaskManager.cpp
)
