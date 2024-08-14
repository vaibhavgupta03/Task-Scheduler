#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Task {
    int priority;
    string description;
    int taskId;

    // Constructor to initialize the task object
    Task(int p, string desc, int id) {
        priority = p;
        description = desc;
        taskId = id;
    }
};

// Custom comparator for the priority_queue
struct CompareTasks {
    bool operator()(const Task& t1, const Task& t2) {
        return t1.priority < t2.priority;
    }
};

class TaskScheduler {
private:
    priority_queue<Task, vector<Task>, CompareTasks> taskQueue;

public:
    void addTask(const Task& task) {
        taskQueue.push(task);
    }

    void executeTasks() {
        while (!taskQueue.empty()) {
            Task currentTask = taskQueue.top();
            taskQueue.pop();
            execute(currentTask);
        }
    }

    void execute(const Task& task) {
        cout << "Executing Task ID: " << task.taskId 
             << " | Priority: " << task.priority 
             << " | Description: " << task.description << endl;
    }
};

int main() {
    TaskScheduler scheduler;

    // Adding tasks
    scheduler.addTask(Task(5, "Low priority task", 1));
    scheduler.addTask(Task(10, "High priority task", 2));
    scheduler.addTask(Task(7, "Medium priority task", 3));

    // Executing tasks
    scheduler.executeTasks();

    return 0;
}