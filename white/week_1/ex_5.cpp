/*
 * Ilia's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
 * Ivan's tasks: 3 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
 * Updated Ivan's tasks: 0 new tasks, 2 tasks in progress, 0 tasks are being tested, 0 tasks are done
 * Untouched Ivan's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
 * Updated Ivan's tasks: 0 new tasks, 1 tasks in progress, 1 tasks are being tested, 0 tasks are done
 * Untouched Ivan's tasks: 0 new tasks, 1 tasks in progress, 0 tasks are being tested, 0 tasks are done
 * */

#include <iostream>
#include <map>
#include <tuple>
#include <vector>

using namespace std;
//
//enum class TaskStatus {
//    NEW,
//    IN_PROGRESS,
//    TESTING,
//    DONE
//};
//
//// Объявляем тип-синоним для map<TaskStatus, int>, позволяющего хранить количество задач каждого статуса
//using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
private:
    map<string, TasksInfo> employee;
public:
    const TasksInfo& GetPersonTasksInfo(const string& person) const{
        return employee.at(person);
    }
    void AddNewTask(const string& person){
        ++employee[person][TaskStatus::NEW];
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count){
        map<TaskStatus, int> updated_tasks;
        map<TaskStatus, int>  untouched_tasks;

        untouched_tasks[TaskStatus::NEW] = employee[person][TaskStatus::NEW];
        untouched_tasks[TaskStatus::IN_PROGRESS] = employee[person][TaskStatus::IN_PROGRESS];
        untouched_tasks[TaskStatus::TESTING] = employee[person][TaskStatus::TESTING];

        //cout << "The size of "<<untouched_tasks.size() << endl;

        int neww = employee[person][TaskStatus::NEW];
        int in_progress = employee[person][TaskStatus::IN_PROGRESS];
        int testing = employee[person][TaskStatus::TESTING];
        int done = employee[person][TaskStatus::DONE];

        int count = 0;

        for(int i = 0; i < neww && count < task_count; ++i){
            --employee[person][TaskStatus::NEW];
            ++employee[person][TaskStatus::IN_PROGRESS];
            ++updated_tasks[TaskStatus::IN_PROGRESS];
            --untouched_tasks[TaskStatus::NEW];
            ++count;
        }
        for(int i = 0; i < in_progress && count < task_count; ++i){
            --employee[person][TaskStatus::IN_PROGRESS];
            ++employee[person][TaskStatus::TESTING];
            ++updated_tasks[TaskStatus::TESTING];
            --untouched_tasks[TaskStatus::IN_PROGRESS];
            ++count;
        }
        for(int i = 0; i < testing && count < task_count; ++i){
            --employee[person][TaskStatus::TESTING];
            ++employee[person][TaskStatus::DONE];
            ++updated_tasks[TaskStatus::DONE];
            --untouched_tasks[TaskStatus::TESTING];
            ++count;
        }

        ZeroOut(untouched_tasks);
        ZeroOut(updated_tasks);
        ZeroOut(employee[person]);

        return tie(updated_tasks, untouched_tasks);
    }
    void ZeroOut(TasksInfo& map) {
        vector<TaskStatus> temp;
        for (const auto& item : map) {
            if (item.second == 0) {
                temp.push_back(item.first);
            }
        }
        for (const auto item_2 : temp) {
            map.erase(item_2);
        }

    }
};


// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
//void PrintTasksInfo(TasksInfo tasks_info) {
//    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
//         ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
//         ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
//         ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
//}
//void PrintTasksInfo(const TasksInfo& tasks_info) {
//    if (tasks_info.count(TaskStatus::NEW)) {
//        cout << "NEW: " << tasks_info.at(TaskStatus::NEW) << " ";
//    }
//    if (tasks_info.count(TaskStatus::IN_PROGRESS)) {
//        cout << "IN_PROGRESS: " << tasks_info.at(TaskStatus::IN_PROGRESS) << " ";
//    }
//    if (tasks_info.count(TaskStatus::TESTING)) {
//        cout << "TESTING: " << tasks_info.at(TaskStatus::TESTING) << " ";
//    }
//    if (tasks_info.count(TaskStatus::DONE)) {
//        cout << "DONE: " << tasks_info.at(TaskStatus::DONE) << " ";
//    }
//}
//
//int main() {
//    TeamTasks tasks;
//
////    tasks.AddNewTask("Ilia");
////    for (int i = 0; i < 3; ++i) {
////        tasks.AddNewTask("Ivan");
////    }
////    cout << "Ilia's tasks: ";
////    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
////    cout << "Ivan's tasks: ";
////    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//    TasksInfo updated_tasks, untouched_tasks;
////    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
////    cout << "Updated Ivan's tasks: ";
////    PrintTasksInfo(updated_tasks);
////    cout << "Untouched Ivan's tasks: ";
////    PrintTasksInfo(untouched_tasks);
////    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);
////    cout << "Updated Ivan's tasks: ";
////    PrintTasksInfo(updated_tasks);
////    cout << "Untouched Ivan's tasks: ";
////    PrintTasksInfo(untouched_tasks);
//
//
//    for (int i = 0; i < 5; ++i) {
//        tasks.AddNewTask("Alice");
//    }
//    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
//
//    cout << "upDated: ";
//    PrintTasksInfo(updated_tasks);
//    cout << endl;
//    cout << "unTouched: ";
//    PrintTasksInfo(untouched_tasks);
//    cout << endl;
//
//    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 5);
//
//    cout << "upDated: ";
//    PrintTasksInfo(updated_tasks);
//    cout << endl;
//    cout << "unTouched: ";
//    PrintTasksInfo(untouched_tasks);
//    cout << endl;
//
//    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 1);
//
//    cout << "upDated: ";
//    PrintTasksInfo(updated_tasks);
//    cout << endl;
//    cout << "unTouched: ";
//    PrintTasksInfo(untouched_tasks);
//    cout << endl;
//
//    tasks.AddNewTask("Alice");
//    for (int i = 0; i < 5; ++i) {
//        tasks.AddNewTask("Alice");
//    }
//
//    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 2);
//
//    cout << "upDated: ";
//    PrintTasksInfo(updated_tasks);
//    cout << endl;
//    cout << "unTouched: ";
//    PrintTasksInfo(untouched_tasks);
//    cout << endl;
//
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
//    cout << endl;
//
//    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Alice", 4);
//
//    cout << "upDated: ";
//    PrintTasksInfo(updated_tasks);
//    cout << endl;
//    cout << "unTouched: ";
//    PrintTasksInfo(untouched_tasks);
//    cout << endl;
//
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
//    return 0;
//}
//AddNewTasks Alice 5
//PerformPersonTasks Alice 5
//PerformPersonTasks Alice 5
//PerformPersonTasks Alice 1
//AddNewTasks Alice 5
//PerformPersonTasks Alice 2
//GetPersonTasksInfo Alice
//PerformPersonTasks Alice 4
//GetPersonTasksInfo Alice