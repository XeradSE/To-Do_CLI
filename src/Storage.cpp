#include "../include/Storage.hpp"
#include "../include/json.hpp"
#include <fstream>
#include <stdexcept>

void Storage::save(const std::vector<Task>& liste, const std::string& path) {
    std::ofstream file (path);
    if (!file.is_open()) throw std::runtime_error("Error creating the JSON file.");
    nlohmann::json json_array = nlohmann::json::array();
    for (const Task& i : liste) {
        nlohmann::json objet;
        objet["id"] = i.getId();
        objet["title"] = i.getTitle();
        objet["desc"] = i.getDesc();
        objet["priority"] = i.getPriority();
        objet["status"] = i.getStatus();
        objet["due_date"] = i.getDueDate();
        json_array.push_back(objet);
    }
    file << json_array.dump(4); // Le paramètre "4" permet d'indenter le fichier pour qu'il soit lisible par un humain.
    file.close();
}

std::vector<Task> Storage::load(const std::string& path) {
    std::vector<Task> tasks;
    std::ifstream file;
    file.open(path);
    if (!file.is_open()) throw std::runtime_error("Couldn't load the file.");
    nlohmann::json data;
    try {
        data = nlohmann::json::parse(file);
    } catch (const nlohmann::json::parse_error& e) {
        std::cerr << "Attention: le fichier JSON est vide ou mal formaté. (" << e.what() << ")\n";
        return tasks;
    }
    for (const auto& i : data) {
        Task temp(i["title"], i["id"]);
        temp.setDesc(i["desc"]);
        temp.setPriority(i["priority"]);
        temp.setStatus(i["status"]);
        temp.setDueDate(i["due_date"]);
        tasks.push_back(temp);
    }
    return tasks;
}