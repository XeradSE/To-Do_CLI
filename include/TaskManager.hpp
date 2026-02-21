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

    Task getTask(int id);

    std::map<int, Task> getAllTasks() const {return liste;};

    std::map<int, Task> filterByStatus(Status s) const;

    std::map<int, Task> filterByPriority(Priority p) const;

    void sortByPriority();

    void sortByStatus();

};

#endif