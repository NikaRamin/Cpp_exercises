#include <iostream>
#include <queue>
using namespace std;


void addTask(queue <string> &todolist){
    string newTask;
    cout<<"Enter the title of your new task:"<<endl;
    cin>>newTask;
    todolist.push(newTask);
    cout<<"Task added Successfully"<<endl;
}


void showList(queue <string> todolist){
    int i = 1;
    while(!todolist.empty()){
        cout<<i<<". "<<todolist.front()<< " " ;
        i++;
        todolist.pop();
        cout<<endl;
    }
}


int main(){
    int choice;
    queue <string> todolist;
    while(true){
        cout<<"Menu:"<<endl;
        cout<<"1.Add task to the end of the list.\n2.Show list.\n3.Remove the task from the top of the list.\n4.Exit.\n";
        cin>>choice;
        if(choice==4){
            cout<<"Thank you for using this program."<<endl;
            break;
        }
        switch(choice){
            case 1: addTask(todolist); break;
            case 2: showList(todolist);break;
            case 3: todolist.pop(); cout<<"Task added Successfully"<<endl; break;
            default: cout<<"Invalid input"<<endl ; break;
        }
    }

    return 0;
}