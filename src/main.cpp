#include "../include/CLI.hpp"

int main() {
    TaskManager TM;
    CLI main(TM);
    main.run();
}