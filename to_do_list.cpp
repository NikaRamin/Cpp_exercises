#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Task{
    public:
    string Title;
    string Description;
    string SubTask;
    string Priority;
    string DueDate;
    bool done;
};

class ToDoList : public Task{
    private:
    vector <Task> tasks;
    public:

    void addTask(){
        Task newTask;
        cout<<"What is the title of your task?"<<endl;
        cin>>newTask.Title;
        cout<<"What is the description of your task?"<<endl;
        cin>>newTask.Description;
        cout<<"Does it have any sub-tasks? if not, type none"<<endl;
        cin>>newTask.SubTask;
        cout<<"Define the priority of your task."<<endl;
        cin>>newTask.Priority;
        cout<<"Set a deadline. you can type none."<<endl;
        cin>>newTask.DueDate;
        done = false;
        tasks.push_back(newTask);
    }

    void viewList(){
        cout<<"Your To-Do list:"<<endl;
        for(int i = 0 ; i < tasks.size() ; i++){
            cout<<i+1<<"."<<" "<<tasks[i].Title<<endl;
        }
    }
    void removeTask(int index){
        if(index >= 1 && index < tasks.size()){
            index--;
            tasks.erase(tasks.begin()+index);
            cout<<"Task removed Successfully"<<endl;
        }
        else{
            cout<<"Invalid index input."<<endl;
        }
    }
    void markComplete(int index){
        if(index >= 1 && index <= tasks.size()){
            tasks[index - 1].done = true;
            cout<<"Task marked as completed"<<endl;
        }
        else{
            cout<<"Invalid index input."<<endl;
        }
    }

    void saveList(){
        ofstream file("todolist.txt");
        if(!file){
            cout<<"FILE NOT FOUND!"<<endl;
        }
        else{
            for(int i = 0 ; i < tasks.size() ; i++){
            file<<tasks[i].Title;
            file<<" - ";
            file<<tasks[i].Description;
            file<<" - ";
            file<<tasks[i].SubTask;
            file<<" - ";
            file<<tasks[i].Priority;
            file<<" - ";
            file<<tasks[i].DueDate;
            file<<" - ";
            tasks[i].done ? file << " Done! " : file << " In progress! ";
            file<<endl;
            }
        }
        
        tasks.clear();
        file.close();
        cout<<"List saved to file Successfully!"<<endl;

    }

    void loadFromFile(){
        string text;
        ifstream file("todolist.txt");
        if(!file){
            cout<<"NOT FOUND!"<<endl;
        }
        else{
            while(getline(file,text)){
                cout<<text<<endl;
            }
        }
        file.close();
        tasks.clear();
    }
};


int main(){
    int choice,index;
    ToDoList ToDoList;
    cout<<"Previous saved list:"<<endl;
    ToDoList.loadFromFile();
    while(true){
        cout<<"Menu:"<<endl;
        cout<<"1.Add a task to your To-Do list.\n"<<"2.View the current tasks in the to-do list.\n"<<"3.Remove a task from the to-do list.\n";
        cout<<"4.Mark as completed.\n5.Save the to-do list to a file.\n"<<"6.Exit\n";
        cin>>choice;
        if(choice==6){
            cout<<"Are you sure you want to exit the program?\n1.Yes\n2.No\n";
            cin>>choice;
            if(choice==1){
                cout<<"Thank you four using this program.\n";
                break;
            }
            else if(choice==2){
                continue;
            }
        }
        switch(choice){
            case 1: ToDoList.addTask(); break;
            case 2: ToDoList.viewList(); break;
            case 3:{
                ToDoList.viewList();
                cout<<"Which one you want to remove?"<<endl;
                cin>>index;
                ToDoList.removeTask(index);
                break;
            }
            case 4:{
                ToDoList.viewList();
                cout<<"Which one you want to mark as completed?"<<endl;
                cin>>index;
                ToDoList.markComplete(index);
                break;
            }
            case 5:{
                cout<<"Are you sure you want to save your current list?\n1.Yes\n2.No"<<endl;
                cin>>choice;
                if(choice==1){
                    ToDoList.saveList();
                }
                else{
                    continue;
                }
                break;
            }
            default:cout<<"Invalid Input!"; break;
        }
    }

    return 0;
}