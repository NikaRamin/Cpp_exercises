#include <iostream>
using namespace std;

void GetMinAndMax(int numbers[], int size , int* min , int* max){
    for(int i = 1 ; i < size ; i++){
        if(numbers[i] > *max){
            *max = numbers[i];
        }
    }
    for(int i = 1 ; i < size ; i++){
        if(numbers[i] < *min){
            *min = numbers[i];
        }
    }
}

int main(){
    int numbers[] = {12, 67 , 89 , -34 , 100};
    int min , max = numbers[0];
    GetMinAndMax(numbers,5,&min,&max);
    cout<<"Min is: "<<min<<endl;
    cout<<"Max is: "<<max<<endl;

    return 0;
}