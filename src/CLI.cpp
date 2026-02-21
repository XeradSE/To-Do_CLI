#include "../include/CLI.hpp"
#include <exception>
#include <string>
#include <vector>
#include "../include/Storage.hpp"
#include <cctype>
#include <limits>

CLI::CLI(const TaskManager& TM) {
    this->TM = TM;
}

void CLI::promptAddTask(const std::string& title) {
    TM.addTask(title);
}

void CLI::promptRemoveTask(int id) {
    TM.removeTask(id);
}

void CLI::displayAllTasks() {
    std::vector<Task> tasks = TM.getAllTasks();
    for (Task& i : tasks){
        i.display();
    }
}

void CLI::displayByPriotity() {
    TM.sortByPriority();
}
    
void CLI::displayByStatus() {
    TM.sortByStatus();
}

void CLI::promptLoadSave(const std::string& path) {
    Storage ST;
    std::vector<Task> new_tasks = ST.load(path);
    for (const Task& i : new_tasks) {
        TM.addTask(i);
    }
}

void CLI::promptModifyTask(int id) {
    std::cout << "Quel titre voulez-vous donner à votre tâche (l'ancien nom est gardé si le champ est laissé vide)" << std::endl;
    std::string title;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, title);
    if (!title.empty()) {
        TM.getTask(id).setTitle(title);
    }
    std::cout << "Quel description voulez-vous donner à votre tâche (l'ancienne description est gardé si le champ est laissé vide)" << std::endl;
    std::string desc;
    std::getline(std::cin, desc);
    if (!desc.empty()) {
        TM.getTask(id).setDesc(desc);
    }
    std::cout << "Quel priorité (High - Medium - Low) voulez-vous donner à votre tâche (l'ancienne priorité est gardé si le champ est laissé vide)" << std::endl;
    std::string priority;
    std::cin >> priority;
    if (!priority.empty()) {
        for (char& c: priority) {c = std::toupper(c);}
        if (priority == "HIGH") TM.getTask(id).setPriority(Priority::HIGH);
        else if (priority == "MEDIUM") TM.getTask(id).setPriority(Priority::MEDIUM);
        else if (priority == "LOW") TM.getTask(id).setPriority(Priority::LOW);
        else {
            std::cout << "Priorité invalide." << std::endl;
        }
    }
    std::cout << "Quel status (To-Do - In Progress - Done) voulez-vous donner à votre tâche (l'ancien status est gardé si le champ est laissé vide)" << std::endl;
    std::string status;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, status);
    if (!status.empty()) {
        for (char& c: status) {c = std::toupper(c);}
        if (status == "TO-DO") TM.getTask(id).setStatus(Status::TODO);
        else if (status == "IN PROGRESS") TM.getTask(id).setStatus(Status::IN_PROGRESS);
        else if (status == "DONE") TM.getTask(id).setStatus(Status::DONE);
        else {
            std::cout << "Status invalide." << std::endl;
        }
    }
    std::cout << "Quel échéance (YYYY-MM-DD) voulez-vous donner à votre tâche (l'ancienne échéance est gardé si le champ est laissé vide)" << std::endl;
    std::string due_date;
    std::cin >> due_date;
    if (!due_date.empty()) {
        TM.getTask(id).setDueDate(due_date);
    }
}

void CLI::run(){
    try{
        std::cout << "Bienvenue dans votre To-Do List !" << std::endl;
        while(1){
            std::cout << "Que voulait faire ?" << std::endl;
            std::cout << "Ajouter une tâche ? (a) - Supprimer une tâche ? (r) - Modifier une tâche ? (m) - Lister toutes les tâches ? (l) - Charger un fichier .json ? (c)" << std::endl;
            char choix;
            std::cin >> choix;
            switch (choix) {
                case 'a': {
                    std::cout << "Quel titre voulez-vous donner à votre tâche ?" << std::endl;
                    std::string titre;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, titre);
                    promptAddTask(titre);
                    break;
                }
                case 'r': {
                    std::cout << "Quel est l'identifiant de la tâche que vous voulez supprimer ?" << std::endl;
                    int id;
                    std::cin >> id;
                    promptRemoveTask(id);
                    break;
                }
                case 'm': {
                    std::cout << "Quel est l'identifiant de la tâche que vous voulez modifier ?" << std::endl;
                    int id;
                    std::cin >> id;
                    promptModifyTask(id);
                    break;
                }
                case 'l': {
                    std::cout << "Voulez-vous afficher les tâches par priorité ? (High > Medium > Low - p) par status ? (TO-DO > In Progress > Done - s) ou par ordre de création ? (c)";
                    char type;
                    std::cin >> type;
                    switch (type) {
                        case 'p': displayByPriotity(); break;
                        case 's': displayByStatus(); break;
                        case 'c': displayAllTasks(); break;
                        default: std::cout << "Entrée invalide." << std::endl; break;
                    }
                    break;
                }
                case 'c': {
                    std::cout << "Veuillez préciser le chemain vers le fichier (relatif au dossier src ou le chemin complet)" << std::endl;
                    std::string path;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, path);
                    promptLoadSave(path);
                    break;
                }
                default: std::cout << "Entrée invalide." << std::endl; break;
            }
            Storage ST;
            ST.save(TM.getAllTasks(), "../data/data.json");
        }
    }catch(const std::exception& e) {
        std::cerr << "Erreur détecté : " << e.what() << std::endl;
    }
}