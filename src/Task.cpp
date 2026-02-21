#include "../include/Task.hpp"

Task::Task(std::string title, int id){
    this->title = title;
    this->id = id;
    priority = Priority::LOW;
    status = Status::TODO;
}

void Task::display(){
    std::cout << title << std::endl;
    std::cout << desc << std::endl;
    std::cout << "Task priority: " << priority << std::endl;
    std::cout << "Task status: " << status << std::endl;
    std::cout << "Task due on " << due_date << std::endl;
    std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& o, const Priority& p){
    switch(p) {
        case Priority::LOW: o << "Low"; break;
        case Priority::MEDIUM: o << "Medium"; break;
        case Priority::HIGH: o << "High"; break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const Status& s){
    switch(s) {
        case Status::TODO: o << "To-Do"; break;
        case Status::IN_PROGRESS: o << "In Progress"; break;
        case Status::DONE: o << "Done"; break;
    }
    return o;
}