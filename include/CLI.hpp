#ifndef _CLI_H_
#define _CLI_H_

#include "TaskManager.hpp"
#include "Storage.hpp"

class CLI {

    TaskManager TM;
    Storage ST;

    void promptAddTask(const std::string& title);
    void promptRemoveTask(int id);
    void displayAllTasks();
    void displayByPriotity();
    void displayByStatus();
    void promptLoadSave(const std::string& path);
    void promptModifyTask(int id);

public:

    CLI(const TaskManager& TM);

    void run();

};

#endif