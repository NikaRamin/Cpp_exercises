#include <iostream>
using namespace std;

/* Abstraction : simplifying complex systems by breaking them down into smaller, 
more manageable parts while hiding the unnecessary details. */
class bookAbstraction{
  virtual void toGetPublished() = 0 ; 
};

class Book : bookAbstraction {
  /*
  Encapsulation:
  restricting direct access to some of the class's components, 
  typically its internal data, and providing controlled access 
  through well-defined interfaces (public methods).
  */
  protected:
    string Name;
    string Genre;
    string Author;
    int Year;
    int Pages;
  public:
    void pagecount(){
      cout << Name << " book has " << Pages << " pages. "<< endl;
    }
    // Public methods of Encapsulation :
    void setName(string name){ //setter
      Name = name;
    }
    string getName(){ //getter
      return Name;
    }
    void setGenre(string genre){ //setter
      Genre = genre;
    }
    string getGenre(){ //getter
      return Genre;
    }
    void setAuthor(string author){ //setter
      Author = author;
    }
    string getAuthor(){ //getter 
      return Author;
    }
    void setYear(int year){ //setter
      Year = year;
    }
    int getYear(){ //getter
      return Year;
    }
    void setPages(int pages){ //setter
      Pages = pages;
    }
    int getPages(){//getter
      return Pages;
    }
    Book(string name,string genre,string author, int year, int pages){
      Name = name;
      Genre = genre;
      Author = author;
      Year = year;
      Pages = pages;
    }
    void toGetPublished(){
      if(Pages > 500)
      cout << "Sorry your request has been denied."<<endl;
      else
      cout << "Congratulations!! your book will get published!"<<endl;
    }
    // Polymorphism :
    virtual void buyBook(){
      cout << "You can probably buy the " << Name << " book in on paper or digital form. " << endl;
    }
};


/*
Inheritance allows you to create a new class (the derived or child class)
based on an existing class (the base or parent class). 
The child class inherits the properties (attributes and methods) of the parent class,
and you can extend or modify the behavior of the child class as needed.
*/
class DigitalBook : public Book{
  private:
  int Downloads;
  public:
  void setDownloads(int downloads){ //setter
    Downloads = downloads;
  }
  int getDownloads(){ //getter
    return Downloads;
  }
  //you should define a constructor for the child class.
  DigitalBook(string name,string genre,string author, int year, int pages, int downloads)
  :Book(name,genre,author,year,pages)
  {
    Downloads = downloads;
  }
  void HowManyDownloads(){
    cout << Name << " book has been downloaded " << Downloads << " times."<<endl;
  }
  void buyBook(){
      cout << "You can only buy the " << Name << " book in digital form. " << endl;
  }
};

class TraditionalBook : public Book{
  private:
  int Sells;
  public:
  void setSells(int sells){
    Sells = sells;
  }
  int getsSells(){
    return Sells;
  }
  TraditionalBook(string name,string genre,string author, int year, int pages, int sells)
  :Book(name,genre,author,year,pages)
  {
    Sells = sells;
  }
  void buyBook(){
      cout << "You can only buy the " << Name << " book on paper form. " << endl;
  }
};


int main(){
  Book one = Book("\"Harry Potter\"","Fantasy","JK Rowling",1990,200);
  DigitalBook two = DigitalBook("\"My life\"","Biography","John",2023,600,1000);
  TraditionalBook three = TraditionalBook("\"Pride and prejudice\"","Drama","Jane Austen",1813,496,100000);
  /*
    Polymorphism : the ability of different objects or classes to respond in a unique way to the same method
    or function call. In simpler terms, polymorphism allows objects of different types
    to be treated as if they are objects of a common base type.
  */
  Book* mybook;
  mybook = &one;
  mybook -> buyBook();
  mybook = &two;
  mybook -> buyBook();
  mybook = &three;
  mybook -> buyBook();
  return 0;
}