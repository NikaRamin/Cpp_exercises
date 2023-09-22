#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string mytext;

    //read the file
    ifstream myfile("file.txt");

    while(getline(myfile,mytext)){
        cout<<mytext<<endl;
    }


    //close the file
    myfile.close();

    return 0;
}