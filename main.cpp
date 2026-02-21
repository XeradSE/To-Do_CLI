#include "src/Task.cpp"

int main() {

    Task test("Task Test", 1);
    test.setDesc("This is a task made to test the program.");
    test.setDueDate("2026-04-25");
    test.setPriority(Priority::LOW);
    test.setStatus(Status::IN_PROGRESS);

    test.display();
}