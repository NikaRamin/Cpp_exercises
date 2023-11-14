#include <iostream>
using namespace std;


class book{

    private:
        string name;
        string author;
        int year;
    public:
    book(string nn = " ",string aa = " " ,int yy= 0){
        name = nn;
        author = aa;
        year = yy;
    }
    int operator >(book x){
        if(year > x.year){
            return 1;
        }
        return 0;
    }
     
    friend ostream& operator <<(ostream&,book);
    friend istream& operator >>(istream&,book&);
    
};

ostream& operator <<(ostream& cout, book x){
    cout<<"BookName:";
    cout<<x.name;
    cout<<endl;
    cout<<"Author:";
    cout<<x.author;
    cout<<endl;
    cout<<"PublictionYear:";
    cout<<x.year;
    cout<<endl;
    cout<<"=================";
    return cout;
}

istream& operator >>(istream& cin, book &x){
    cin>>x.name;
    cin>>x.author;
    cin>>x.year;
    return cin;
}


int main(){
    book shelf[5],temp;
    for(int i = 0 ; i < 5; i++){
        cout<<"please enter BookName, Author and PublictionYear of the book number "<<i+1<<":"<<endl;
        cin>>shelf[i];
    }
    for(int i = 0 ; i < 5 ; i++){
        for(int j = i+1 ;  j < 5 ; j++){
            if(shelf[i]>shelf[j]){
                temp = shelf[i];
                shelf[i] = shelf[j];
                shelf[j] = temp;
            }
        }
    }
    cout<<"Sorted books:"<<endl;
    for(int i = 0 ; i < 5 ; i++){
        cout<<shelf[i];
        cout<<endl;
    }
    return 0;
}
