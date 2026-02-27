# To-Do_CLI

A command-line task manager written in C++, with persistent JSON storage.

## Demo



https://github.com/user-attachments/assets/881a3893-9c89-49e5-9810-12fd00bfe5b5



## Features

- Add, remove, and list tasks
- Set priority (Low, Medium, High) and status (Todo, In Progress, Done)
- Set a due date for each task
- Filter tasks by priority or status
- Sort tasks by priority or due date
- Persistent storage via a local JSON file (Warning! You must back-up the file once done before using the application again if you do not want your .json to be overwritten, or you can load it at the start)

## Dependencies

- [nlohmann/json](https://github.com/nlohmann/json) — header-only JSON library (No download required, the file is already provided)

## Build & Run

**Requirements:** g++, make, C++17 or later

```bash
# Clone the repository
git clone https://github.com/XeradSE/To-Do_CLI.git
cd To-Do_CLI

# Build
mkdir build
cd build
cmake ..
make

# Run (depuis le dossier racine du projet)
./build/To-Do_CLI
```

## Project Structure

```
To-Do_CLI/
├── build/
│   ├── Makefile
├── README.md
├── CMakeLists.md
├── include/
│   ├── Task.hpp
│   ├── TaskManager.hpp
│   ├── Storage.hpp
│   └── CLI.hpp
├── src/
│   ├── main.cpp
│   ├── Task.cpp
│   ├── TaskManager.cpp
│   ├── Storage.cpp
│   └── CLI.cpp
└── data/
    └── data.json
```

## Architecture

The project is split into four clearly separated layers:

- **Task** — data model, holds all the information about a single task
- **TaskManager** — business logic, manages the task collection
- **Storage** — handles serialization and deserialization to/from JSON
- **CLI** — user interface, reads input and displays output

## Author

Made as a personal C++ project to practice OOP, STL, and clean architecture.
