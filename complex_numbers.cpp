#include <iostream>
using namespace std;

class complexNumber{
    private:
        int real;
        int img;
    public:
    complexNumber(int rr, int ii){
        setNumber(rr,ii);
    }
    void setNumber(int rr, int ii){
        real = rr;
        img = ii;
    }
    void conjugate(){
        img *= -1;
    }
    complexNumber operator+(complexNumber x){
        complexNumber z(0,0);
        z.img = x.img + img ;
        z.real = z.real + real;
        return z;
    }
    complexNumber operator-(complexNumber x){
        complexNumber z(0,0);
        z.img = img - x.img;
        z.real = real - x.real;
        return z;
    }
    complexNumber operator *(complexNumber x){
        complexNumber z(0,0);
        z.real =(real * x.real)-(img * x.img);
        z.img =(real*x.img)+(x.real*img);
        return z;
    }
    friend ostream& operator <<(ostream&,complexNumber);
    friend istream& operator >>(istream&,complexNumber&);

};
ostream& operator <<(ostream& cout,complexNumber x){
    if(x.real)
            cout<<x.real;
        if(x.img){
            if(x.img>0)
            cout<<"+"<<x.img<<"i";
            else
            cout<<x.img<<"i";
    }
    cout<<endl;
    return cout;
}

istream& operator >>(istream& cin,complexNumber &x){
    int rr,ii;
    cin>>rr>>ii;
    x.setNumber(rr,ii);
    return cin;
}

int main(){
    complexNumber a(1,-1),b(-3,9);
    a.conjugate();
    cout<<a;

    return 0;
}