#include "src/Task.cpp"
#include "src/TaskManager.cpp"

int main() {

    Task test("Task Test", 1);
    test.setDesc("This is a task made to test the program.");
    test.setDueDate("2026-04-25");
    test.setPriority(Priority::LOW);
    test.setStatus(Status::IN_PROGRESS);

    TaskManager TMTest;

    TMTest.addTask("test");
    TMTest.addTask("test2");
    TMTest.addTask("test3");
    TMTest.addTask("test4");

    TMTest.sortByPriority();

    test.display();
}