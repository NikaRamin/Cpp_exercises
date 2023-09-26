#include <iostream>
using namespace std;


template<typename T>
void myswap(T& a,T& b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    int a = 97 , b = 90;
    cout << "Original:"<<endl<<"a: "<<a<<" b: "<<b<<endl;
    myswap<int>(a,b);
    cout << "Swapped:"<<endl<<"a: "<<a<<" b: "<<b<<endl;
    return 0;
}
