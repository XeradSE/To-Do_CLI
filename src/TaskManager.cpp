#include "../include/TaskManager.hpp"
#include <stdexcept>
#include <algorithm>
#include <utility>

void TaskManager::addTask(const std::string& title) {
    Task new_task(title, ind);
    liste.insert({ind, new_task});
    ind++;
}

void TaskManager::addTask(const Task& task) {
    liste.insert({ind, task});
    ind++;
}

void TaskManager::removeTask(int id) {
    liste.erase(id);
}

Task TaskManager::getTask(int id) {
    if (liste.count(id) == 0) throw std::runtime_error("Cet id n'appartient à aucune tâche.");
    return liste.at(id);
}

std::vector<Task> TaskManager::getAllTasks() const {
    std::vector<Task> temp;
    for (auto i : liste) {
        temp.push_back(i.second);
    }
    return temp;
}

std::vector<Task> TaskManager::filterByStatus(Status s) const {
    std::map<int, Task> listeStatus;
    for (auto const& [id, task] : liste) {
        if (task.getStatus() == s) {
            listeStatus.insert({id, task});
        }
    }
    std::vector<Task> temp;
    for (auto i : listeStatus) {
        temp.push_back(i.second);
    }
    return temp;
}

std::vector<Task> TaskManager::filterByPriority(Priority p) const {
    std::map<int, Task> listePriority;
    for (auto const& [id, task] : liste) {
        if (task.getPriority() == p) {
            listePriority.insert({id, task});
        }
    }
    std::vector<Task> temp;
    for (auto i : listePriority) {
        temp.push_back(i.second);
    }
    return temp;
}

struct {
    bool operator()(const Task& a, const Task& b) const {
        return a.getPriority() > b.getPriority();
    }
}customPriority;

void TaskManager::sortByPriority() {
    std::vector<Task> temp;
    for (auto i : liste) {
        temp.push_back(i.second);
    }
    std::sort(temp.begin(), temp.end(), customPriority);
    for (Task i : temp) {
        i.display();
    }
}

struct {
    bool operator()(const Task& a, const Task& b) const {
        return a.getStatus() > b.getStatus();
    }
}customStatus;

void TaskManager::sortByStatus() {
    std::vector<Task> temp;
    for (auto i : liste) {
        temp.push_back(i.second);
    }
    std::sort(temp.begin(), temp.end(), customStatus);
    for (Task i : temp) {
        i.display();
    }
}