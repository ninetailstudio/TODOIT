#include <iostream>
#include <limits>
#include <ios>
#include <vector>


void displayMenu() {
   std::cout << "----- To Do List Menu -----" << std::endl;
   std::cout << "1: Add Task" << std::endl;
   std::cout << "2: Complete a Task" << std::endl;
   std::cout << "3: Delete a Task" << std::endl;
   std::cout << "4: View Task" << std::endl;
   std::cout << "5: Exit" << std::endl;
   std::cout << "-----------------------" << std::endl;
}

void addTask(std::vector<std::string> &tasks, std::string task) {
    tasks.push_back(task);
}

void deleteTask(std::vector<std::string> &tasks, int taskNumber) {
    if(taskNumber < tasks.size()) 
        tasks.erase(tasks.begin() + taskNumber);
    else
        std::cout << "Invalid request" << std::endl;
}

void completeTask(std::vector<std::string> &tasks, int taskNumber) {
    if(taskNumber < tasks.size()) 
        tasks[taskNumber] += " COMPLETE";
    else
        std::cout << "Invalid request" << std::endl;
}

void getTasks(std::vector<std::string> tasks) {
    if (tasks.size() > 0)
    {
        std::cout << "-------------- Start of List --------------" << std::endl;
        for (int i = 0; i < tasks.size(); i++)
        {
            std::cout << i << ": " << tasks[i] << std::endl;
        }
        std::cout << "-------------- End of List --------------" << std::endl;
    } else {
        std::cout << "Currently there are no pending tasks" << std::endl;
    }
}


int main(int argc, char* argv[]) {


    if(argc > 1) {

    }

    

    std::vector<std::string> tasks;
    int selector = 0; 

    displayMenu();

    while(selector != 5) {

        std::string task;
        int taskSelector = 0;

        std::cout << "Enter a number" << std::endl;
        std::cin >> selector;
        std::cin.ignore();


        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        }


        if(selector > 5 || selector < 1) {
            std::cout << "Not a valid input" << std::endl;
            selector = 4;
        }


        switch(selector) {
            case(1):
                std::cout << "Enter a task" << std::endl;
                std::getline(std::cin, task);
                addTask(tasks, task);

                break;
            case(2):
                std::cout << "Enter a task number to mark complete" << std::endl;
                std::cin >> taskSelector;
                std::cin.ignore();

                completeTask(tasks, taskSelector);
                break;
            case(3):
                std::cout << "Enter a task number to remove" << std::endl;
                std::cin >> taskSelector;
                std::cin.ignore();

                deleteTask(tasks, taskSelector);
                break;
            case(4):
                getTasks(tasks);
                break;
            default:
                break;
        }

    }


    
    return 0;
}

