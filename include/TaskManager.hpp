#ifndef _TASKMANAGER_H_
#define _TASKMANAGER_H_

#include "Task.hpp"
#include <map>
#include <vector>

class TaskManager {

    std::map<int, Task> liste;
    int ind = 1;

public:

    void addTask(const std::string& title);
    
    void addTask(const Task& task);

    void removeTask(int id);

    Task getTask(int id);

    std::vector<Task> getAllTasks() const;

    std::vector<Task> filterByStatus(Status s) const;

    std::vector<Task> filterByPriority(Priority p) const;

    void sortByPriority();

    void sortByStatus();

};

#endif