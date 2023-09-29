#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<char>mystack;
    string input;

    //get the input from the user
    cout<<"Type the text you want to reverse:"<<endl;
    cin>>input;

    //save it in stack
    for(char ch: input){
        mystack.push(ch);
    }

    //print the output from the stack
    while(!mystack.empty()){
        cout<<mystack.top();
        mystack.pop();
    }

    cout<<endl;


    return 0;
}