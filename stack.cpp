#include <iostream>
#include <stack>
using namespace std;

// functions for stack : empty() , top() , pop(), size(), push()

void printsTheElements(stack<int>stack){
    while(!stack.empty()){
        cout << stack.top()<<endl;
        stack.pop();
    }
}

int main(){
    stack<int>myNumbers;
    int choice,n;
    while(1){
        cout<<"1.Add a number to the top.\n2.Remove a number from the top.\n3.Print the elements of the stack.\n4.Exit\n";
        cin >> choice;
        if(choice==4){
            cout<<"Thanks for using this program."<<endl;
            break;
        }
        switch(choice){
            case 1: cout<<"Type a number:\n"; cin >> n ; myNumbers.push(n); break;
            case 2: myNumbers.pop(); break;
            case 3: printsTheElements(myNumbers); break;
        }
    }
    return 0;

}