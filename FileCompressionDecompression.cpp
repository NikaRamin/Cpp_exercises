#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// compression and decompression with RLE algorithm


void fileCompression(string inputFileNum , string ouputFileNum){
    char currentchar,prechar;
    int charcount;
    ifstream inputFile(inputFileNum);
    if(!inputFile){
        cout<<"Error! File Not Found"<<endl;
        return;
    }
    ofstream outputFile(ouputFileNum);
    if(!outputFile){
        cout<<"Error! File Can Not Be Created"<<endl;
        return;
    }
    inputFile.get(prechar);
    charcount = 1;
    int inputmemory = 1,outputmemory=0;
    while(inputFile.get(currentchar)){
        inputmemory++;
        if(prechar==currentchar){
            charcount++;

        }
        else{
            outputFile<<prechar<<charcount;
            outputmemory += 2;
            charcount = 1;
            prechar = currentchar;
        }
    }
    inputFile.close();
    outputFile.close();
    cout<<"Compression complete. Compressed file saved as"<<ouputFileNum<<"Compression ratio: "<<outputmemory/inputmemory<<endl;
}

void fileDecompression(string inputFileNum,string outputFileNum){

    ifstream inputFile(inputFileNum);
    if(!inputFile){
        cout<<"Error! File Not Found"<<endl;
        return;
    }
    ofstream outputFile(outputFileNum);
    if(!outputFile){
        cout<<"Error! File Can Not Be Created"<<endl;
        return;
    }
    int count=0;
    char prech,currentch;
    inputFile.get(prech);
    while (inputFile.get(currentch))
    {
        if(isdigit(currentch)){
            count = count * 10 + (currentch - '0');
        }
        else{
            for(int i = 0 ; i < count ; i++){
                outputFile << prech;
            }
            prech = currentch;
            count = 0;
        }
    }
    //for the last letter
    for(int i = 0 ; i < count ; i++){
        outputFile << prech;
    }
    inputFile.close();
    outputFile.close();
    cout<<"Decompression complete. Decompressed file saved as"<<outputFileNum<<endl;
}


int main(){
    int choice;
    string inputFileNum,ouputFileNum;
    cout<<"Welcome to file compression and decompression program!"<<endl;
    while(true){
        cout<<"1.Compression\n2.Decompression\n3.Exit"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;
        if(choice==3){
                cout<<"Thank you for using this program."<<endl;
                break;
        }
        switch(choice){
            case 1:{
                cout<<"Enter the name of the file you want to compress:"<<endl;
                cin>>inputFileNum;
                ouputFileNum = inputFileNum +"_compressed.txt";
                fileCompression(inputFileNum,ouputFileNum);
                break;
            }
            case 2:{
                cout<<"Enter the name of the file you want to decompress:"<<endl;
                cin>>inputFileNum;
                ouputFileNum = inputFileNum +"_decompressed.txt";
                fileDecompression(inputFileNum,ouputFileNum);
                break;
            }
            default:
                cout<<"Unvalid choice."<<endl;
                break;
        }
    }

    return 0;
}