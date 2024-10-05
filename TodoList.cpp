#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#define MAXTASK 100

class Task
{
public:
    string name; // task name
    bool status; // status representing boolean value (true if completed otherwise false)
    string priority;
    string date;

    Task() : status(false) {}
    Task(string taskName, string prio, string dateee) : name(taskName), status(false), priority(prio), date(dateee) {}
};

class Node
{
public:
    Task task;
    Node *next;

    Node(Task newTask) : task(newTask), next(nullptr) {}
};

class ToDoList
{
private:
    Node *head;
    Node *tail;

public:
    ToDoList() : head(nullptr), tail(nullptr) {}

    void addTask(string Tname, string pr, string date)
    {
        Task newTask(Tname, pr, date);
        Node *newNode = new Node(newTask);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        cout << "Sucessfully Added Task!!!" << endl;
    }

    void viewTask()
    {
        if (head == nullptr)
        {
            cout << "No task to display!!!" << endl;
            return;
        }

        Node *current = head;
        int i = 1;
        while (current != nullptr)
        {
            cout << setw(3) << i  << "."
                 << setw(15) << current->task.name
                 << setw(10) << current->task.priority
                 << setw(15) << current->task.date
                 << setw(15) << (current->task.status ? "Completed" : "Not Done")
                 << endl;
            current = current->next;
            i++;
        }
    }

    void markAsCompleted(int index)
    {
        Node *current = head;
        int i = 0;
        while (current != nullptr && i < index)
        {
            current = current->next;
            i++;
        }
        if (current != nullptr)
        {
            current->task.status = true;
            cout << "Task : " << current->task.name << " Marked as completed!" << endl;
        }
        else
        {
            cout << "Invalid task number!?" << endl;
        }
    }

    void removeTask(int index)
    {
        Node *current = head;
        Node *prev;
        int i = 0;

        while (current != nullptr && i < index)
        {
            prev = current;
            current = current->next;
            i++;
        }

        if (current != nullptr)
        {
            cout << "Removed Task : " << current->task.name << endl;
            if (prev == nullptr)
            {
                head = current->next;
            }
            else
            {
                prev->next = current->next;
                if (current == tail)
                {
                    tail = prev;
                }
            }
            delete current;
        }
        else
        {
            cout << "Invalid task number!?" << endl;
        }
    }

    int priorityToInt(string pr)
    {
        if (pr == "high")
            return 1;
        else if (pr == "medium")
            return 2;
        else if (pr == "low")
            return 3;
    }

    void taskSortByPriority()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        Node *current = head;
        while (current != nullptr)
        {
            Node *cur_next = current->next;
            while (cur_next != nullptr)
            {
                if (priorityToInt(current->task.priority) > priorityToInt(cur_next->task.priority))
                {
                    Task temp = current->task;
                    current->task = cur_next->task;
                    cur_next->task = temp;
                }
                cur_next = cur_next->next;
            }
            current = current->next;
        }
    }
};
// USING ARRAY
// class ToDoList
// {
// private:
//     Task tasks[MAXTASK];
//     int count = 0;

// public:
//     void addTask(string Tname, string pr, string date)
//     {
//         tasks[count] = Task(Tname, pr, date);
//         count++;
//         cout << "Sucessfully Added Task!!!" << endl;
//     }

//     void viewTask()
//     {
//         if (count == 0)
//         {
//             cout << "No task to display!!!" << endl;
//         }

//         for (int i = 0; i < count; i++)
//         {
//             cout << setw(3) << (i + 1) << "."
//                  << setw(15) << tasks[i].name
//                  << setw(10) << tasks[i].priority
//                  << setw(12) << tasks[i].date
//                  << setw(12) << (tasks[i].status ? "Completed" : "Not Done")
//                  << endl;
//         }
//     }

//     void markAsCompleted(int index)
//     {
//         if (index - 1 >= 0 && index - 1 < count)
//         {
//             tasks[index - 1].status = true;
//             cout << "Task : " << tasks[index - 1].name << " Marked as completed!" << endl;
//         }
//         else
//         {
//             cout << "Invalid task number!?" << endl;
//         }
//     }

//     void removeTask(int index)
//     {
//         if (index - 1 >= 0 && index - 1 < count)
//         {
//             cout << "Removed Task : " << tasks[index - 1].name << endl;
//             for (int i = index - 1; i < count - 1; i++)
//             {
//                 tasks[i] = tasks[i + 1];
//             }
//             count--;
//         }
//         else
//         {
//             cout << "Invalid task number!?" << endl;
//         }
//     }

//     int priorityToInt(string pr)
//     {
//         if (pr == "high")
//             return 1;
//         else if (pr == "medium")
//             return 2;
//         else if (pr == "low")
//             return 3;
//     }

//     void taskSortByPriority()
//     {
//         for (int i = 0; i < count; i++)
//         {
//             for (int j = 0; j < count - i - 1; j++)
//             {
//                 if (priorityToInt(tasks[i].priority) > priorityToInt(tasks[i + 1].priority))
//                 {
//                     Task temp = tasks[i];
//                     tasks[i] = tasks[i + 1];
//                     tasks[i + 1] = temp;
//                 }
//             }
//         }
//         // cout << "Tasks sorted by priority based!!" << endl;
//     }

//     // void taskSortByDeadline()
//     // {
//     //     for (int i = 0; i < count; i++)
//     //     {
//     //         for (int j = 0; j < count - i - 1; j++)
//     //         {
//     //             if (tasks[i].priority > tasks[i + 1].priority)
//     //             {
//     //                 Task temp = tasks[i];
//     //                 tasks[i] = tasks[i + 1];
//     //                 tasks[i + 1] = temp;
//     //             }
//     //         }
//     //     }
//     //     // cout << "Tasks sorted by priority based!!" << endl;
//     // }
// };

int main()
{
    ToDoList list;

    while (true)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~To Do List 1.0~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "1. Add a Task" << endl;
        cout << "2. Remove a task" << endl;
        cout << "3. View all tasks" << endl;
        cout << "4. Priority Sorted Task view" << endl;
        // cout << "5. Deadline Sorted Task view" << endl;
        cout << "5. Mark a task as completed" << endl;
        cout << "6. Exit" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "Which option you wanna perform?" << endl;
        int choice, tsk_num;
        string tsk, P, date;
        cin >> choice;
        if (choice > 6)
        {
            cout << "Invalid Choice!!!! Try again!" << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            cin.ignore();
            cout << "Enter your task name : ";
            getline(cin, tsk);
            cout << "Enter priority of this task (High/Medium/Low) : ";
            getline(cin, P);
            cout << "Enter your deadline for this task (DD-MM-YYYY): ";
            getline(cin, date);
            list.addTask(tsk, P, date);
            cout << endl;
            break;

        case 2:
            cout << "(Tip: First view all the task so that you know which task u wanna remove)" << endl;
            cout << "Enter the task number : ";
            cin >> tsk_num;
            list.removeTask(tsk_num);
            cout << endl;
            break;

        case 3:
            cout << "No. \tTask Name \tPriority \tDeadLine \t Status" << endl;
            cout << "---- \t----------- \t--------- \t---------- \t-------" << endl;
            list.viewTask();
            break;

        case 4:
            cout << "Tasks sorted by prioriy view" << endl;
            list.taskSortByPriority();
            cout << "No. \tTask Name    Priority    DeadLine   Status" << endl;
            cout << "---- \t----------- ---------   ---------- -------" << endl;
            list.viewTask();
            break;

        case 5:
            cout << "(Tip: First view all the task so that you know which task u wanna mark completed)" << endl;
            cout << "Enter the task number : ";
            cin >> tsk_num;
            list.markAsCompleted(tsk_num);
            cout << endl;
            break;

        case 6:
            cout << "Exiting the program!! We will miss you :( " << endl;
            exit(0);
            break;

        default:
            break;
        }
    }

    return 0;
}

// Coded by Dipanshu Sahu , Github username - dipanshu447