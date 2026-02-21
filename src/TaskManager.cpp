#include "../include/TaskManager.hpp"

void TaskManager::addTask(const std::string& title) {
    Task new_task(title, ind);
    liste.insert({ind, new_task});
    ind++;
}

void TaskManager::removeTask(int id) {
    liste.erase(id);
}