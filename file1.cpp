#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //create file
    ofstream myfile("file.txt");

    //write in the file 
    myfile << "Hello world! This is my first file!" << endl;

    //close file
    myfile.close();
    cout << "Done!" <<endl;

    return 0;
}