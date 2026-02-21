#ifndef _TASK_H_
#define _TASK_H_

#include <iostream>
#include <ostream>
#include <string>

enum class Priority { LOW, MEDIUM, HIGH };
enum class Status { TODO, IN_PROGRESS, DONE };

class Task {

    int id;
    std::string title;
    std::string desc;
    Priority priority;
    Status status;
    std::string due_date; //format: YYYY-MM-DD

public:

    /*
    CONSTRUCTEUR
    */

    Task(std::string title, int id);

    /*
    MÉTHODES
    */

    void display();

    /*
    ACCESSEURS
    */

    int getId() const {return id;};

    void setTitle(const std::string& title){this->title = title;};
    std::string getTitle() const {return title;};

    void setDesc(const std::string& desc){this->desc = desc;};
    std::string getDesc() const {return desc;};

    void setPriority(Priority priority) {this->priority = priority;};
    Priority getPriority() const {return priority;};

    void setStatus(Status status) {this->status = status;};
    Status getStatus() const {return status;};

    void setDueDate(const std::string& due_date) {this->due_date = due_date;};
    std::string getDueDate() const {return due_date;};
    
};

std::ostream& operator<<(std::ostream& o, const Priority& p);

std::ostream& operator<<(std::ostream& o, const Status& s);

#endif