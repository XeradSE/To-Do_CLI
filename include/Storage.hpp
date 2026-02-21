#ifndef _STORAGE_H_
#define _STORAGE_H_

#include <vector>
#include "Task.hpp"

class Storage {

public:

    static void save(const std::vector<Task>& liste, const std::string& path);

    static std::vector<Task> load(const std::string& path);
};

#endif