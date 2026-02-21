#include "../include/CLI.hpp"
#include <exception>
#include <vector>
#include "../include/Storage.hpp"

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

void CLI::run(){
    try{
        std::cout << "Bienvenue dans votre To-Do List !" << std::endl;
        while(1){
            std::cout << "Que voulait faire ?" << std::endl;
            std::cout << "Ajouter une tâche ? (a) - Supprimer une tâche ? (r) - Lister toutes les tâches ? (l)" << std::endl;
            char choix;
            std::cin >> choix;
            switch (choix) {
                case 'a': {
                    std::cout << "Quel titre voulez-vous donner à votre tâche ?" << std::endl;
                    std::string titre;
                    std::cin >> titre;
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
                case 'l': displayAllTasks(); break;
                default: std::cout << "Entrée invalide." << std::endl; break;
            }
            Storage ST;
            ST.save(TM.getAllTasks(), "../data/data.json");
        }
    }catch(const std::exception& e) {
        std::cerr << "Erreur détecté : " << e.what() << std::endl; 
    }
}