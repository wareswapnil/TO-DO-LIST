#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void printTasks() {
    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description
             << (tasks[i].completed ? " [Completed]" : " [Pending]") << endl;
    }
}

void addTask() {
    string description;
    cout << "Enter task description: ";
    cin.ignore(); // Clear newline character from buffer
    getline(cin, description);
    tasks.push_back({description, false});
    cout << "Task added." << endl;
}

void markTaskAsCompleted() {
    printTasks();
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

void removeTask() {
    printTasks();
    int index;
    cout << "Enter task number to remove: ";
    cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

void menu() {
    while (true) {
        cout << "\nMenu:\n"
             << "1. Add Task\n"
             << "2. View Tasks\n"
             << "3. Mark Task as Completed\n"
             << "4. Remove Task\n"
             << "5. Exit\n"
             << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                printTasks();
                break;
            case 3:
                markTaskAsCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                return;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
}

int main() {
    menu();
    return 0;
}
