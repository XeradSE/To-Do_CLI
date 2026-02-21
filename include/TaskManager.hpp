#ifndef _TASKMANAGER_H_
#define _TASKMANAGER_H_

#include "Task.hpp"
#include <map>

class TaskManager {

    std::map<int, Task> liste;
    int ind = 1;

public:

    void addTask(const std::string& title);

    void removeTask(int id);

};

#endif