#ifndef _CLI_H_
#define _CLI_H_

#include "TaskManager.hpp"
class CLI {

    TaskManager TM;

    void promptAddTask(const std::string& title);
    void promptRemoveTask(int id);
    void displayAllTasks();

public:

    CLI(const TaskManager& TM);

    void run();

};

#endif