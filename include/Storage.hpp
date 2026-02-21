#ifndef _STORAGE_H_
#define _STORAGE_H_

#include "json.hpp"
#include "TaskManager.hpp"

class Storage {

public:

    static void save(const std::vector<Task>&, const std::string& path);

    static std::vector<Task> load(const std::string& path);
};

#endif