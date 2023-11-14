#include <iostream>
using namespace std;
class set
{
   int len, size;
   int *arr;
   public:
   set(int n=10)
   { arr = new int[n]; len = 0; size=n; }
   ~set() {delete arr;}
   void add(int x) { 
       if (search(x) == -1)
           arr[len++] = x;
   }
   int search(int x)
   {  for (int i=0; i<len; i++)
        if (arr[i] == x)
            return i;
      return -1;
   }
   void remove(int x)
   {
     int pos = search(x);
     if (pos >= 0)
     {
         arr[pos] = arr[--len];
     }
   }
   int is_full()
   {
      if (len == size) 
        return 1;
      return 0;
   }
   set operator +(set x)
   {
       set z(x.len + len);
       int i;
       for (i=0;i<len;i++)
       z.add(arr[i]);
       for (i=0;i<x.len;i++)
       z.add(x.arr[i]);
       return z;
   }
      set operator *(set x)
   {
       set z(len);
       int i;
       for (i=0;i<len;i++)
       if (x.search(arr[i]) >= 0)
        z.add(arr[i]);
       return z;
   }
    int& operator [](int n)
    {
      return arr[n];
    }
    set operator -(set x)
   {
       set z(len);
       int i;
       for (i=0;i<len;i++)
       if (x.search(arr[i]) == -1)
        z.add(arr[i]);
       return z;
   }
   
   friend ostream& operator <<(ostream&, set);
   friend istream& operator >>(istream&, set&);
};
 ostream& operator <<(ostream& cout, set x)
 {
     for (int i=0; i<x.len; i++)
        cout<<x.arr[i];
    return cout;
 }
  istream& operator >>(istream& cin, set &x)
 {
    int n;
    cin >> n;
    x.add(n);
    return cin;
 }
 
int main()
{
    set a;
    a.add(3);
    a.add(5);
    a.add(8);
    a.remove(3);
    cout<<a;
    return 0;
}
