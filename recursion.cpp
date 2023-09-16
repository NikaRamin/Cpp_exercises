#include <iostream>
#include <string>
using namespace std;

int sum(int x){
    if(x > 0){
        return x + sum (x-1);
    }
    else{
        return 0;
    }
}

int main(){
    int x;
    cout << "The sum of range of [0,X] will be calculated.\nEnter X:\n";
    cin >> x;
    int result = sum(x);
    cout << "The result is:\t" << result << endl;
    return 0;
}