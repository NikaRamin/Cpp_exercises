#include <iostream>
using namespace std;

void swap(int& a,int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    int a = 97 , b = 90;
    cout << "Original:"<<endl<<"a: "<<a<<" b: "<<b<<endl;
    swap(a,b);
    cout << "Swapped:"<<endl<<"a: "<<a<<" b: "<<b<<endl;
    return 0;
}