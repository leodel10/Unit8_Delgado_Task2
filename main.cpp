//a program to practice passing a struct by pointer (*)
#include <iostream>
#include <string>
using namespace std;
//declaration of the struct 

struct car
{
string make;
string model;
int year;
string Color;
};
//function definition declared above int main()
void printCar(car *c)
{
  cout << "\nCar details: " << endl;
  cout << "Make - " << c->make << endl;
  cout << "Model - " << c->model << endl;
  cout << "Year - " << c->year << endl;
  //set the color variable based upon the year, and print it 
if (c->year <= 2010)
{
  c->Color = "RED";
}  
else if (c->year > 2010)
{
  c->Color = "GREEN";
}
//print color to the screen 
cout << "Color: " << c->Color << endl;



}

void preserveData(car &c)
{
  cout << "\nOriginal DATA in c: " << endl;
  printCar(&c);
      
      car *p_car = &c;

  cout << "\nData copied into a new struct p_car";
  printCar(p_car);

    new(p_car) car;
    cout << p_car->year << endl;// print current year 
    new(p_car) car(); //default constructor (reset values)
    cout << p_car->year << endl; //0

  cout  << "\nData after default const reset: ";
  printCar(p_car);

   cout << "\nOriginal DATA in c: " << endl;
  printCar(&c);
}


int main() 
{
 //dclare an instance of the structure 
 car car1;
 car1.make = "Hyundai";
 car1.model = "Genesis";
 car1.year = 2016;

 car car2 = {"GMC", "Yukon", 1975}; 
 
 car car3 = {"Toyota", "Avalon", 2003};

 //print each car 
 printCar(&car1);
 printCar(&car2);
 printCar(&car3);

 preserveData(car1);
 preserveData(car2);
 preserveData(car3);


 return 0;
}