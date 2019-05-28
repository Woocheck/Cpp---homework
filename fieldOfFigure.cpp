/*
Write a program to calculate field of a figure:

plan a field hierarchy
implement count method for all classes
asking user to provide data in appropriate classes
program:
asks user to provide filed type to calculate
call virtual count method
*/

#include <vector>
#include <algorithm>
#include <iostream>

enum class Type { circle, rectangle, sqare, triangle };

class Figure
{
   public:
     virtual double getSurfaceArea() = 0 ;
};

class Circle : public Figure
{
   private:
     const double pi { 3.1415 };
     double radius { 0 };
   public:
     Circle( double r ): radius { r } {};
     double getSurfaceArea() {return radius * radius * pi; };
};

class Rectangle : public Figure
{
   private:
   double sideA { 0 };
   double sideB { 0 };
   public:  
     Rectangle( double a, double b): sideA { a },  sideB { 0 } {};
     double getSurfaceArea() {return sideA * sideB; };
};

class Square : public Figure 
{
   private:
     double sideA { 0 };
   public:
     Square( double a ): sideA { a } {};
     double getSurfaceArea() {return sideA * sideA; };
};

class Triangle : public Figure
{
   private:
    double base { 0 };
    double height { 0 };
   public:
    Triangle( double a , double h ): base { a }, height { h } {};
    double getSurfaceArea() {return 0.5 * base * height; };
};

Figure *newFigure( Type typeOfFigure, double a, double b = 0 );
double printSurfaceAreaFor( Type typeOfFigure, std::vector<Figure*> figure );
double choseGetSurfaceMethodFor( Type typeOfFigure, std::vector<Figure*> figure );

int main()
{
   std::vector<Figure*> figure;
   double a {0};
   double b {0};

   std::cout << "Please write Circle radius: ";
   std::cin >> a;
   figure.push_back( newFigure( Type::circle, a) );

   std::cout << "Please write Rectangle side a :";
   std::cin >> a;
   std::cout <<" and b"; 
   std::cin >> b;
   figure.push_back( newFigure( Type::rectangle, a ,b) );

   std::cout << "Please write Sqare side a: ";
   std::cin >> a;
   figure.push_back( newFigure( Type::sqare, a) );

   std::cout << "Please write Triangle the base :";
   std::cin >> a;
   std::cout <<" and the heigh :"; 
   std::cin >> b;
   figure.push_back( newFigure( Type::triangle, a ,b) );

   std::cout << "Please chose figure to calculate surface area." << std::endl;
   std::cout << "(1 - circle, 2 - rectangle, 3 - square, 4 - triangle)" << std::endl; 
   a = 0;
   Type chosenFigure {};
   std::cin >> a;
   if( a == 1) 
    chosenFigure = Type::circle;
   else if( a == 2 )
    chosenFigure = Type::rectangle;
   else if( a == 3 )
    chosenFigure = Type::sqare;
   else if( a == 4 )
    chosenFigure = Type::triangle;
   else
    std::cout << "You have to choose a number between 1 and 4." << std::endl;
   
   printSurfaceAreaFor( chosenFigure, figure ) ;
  
};

Figure *newFigure( Type typeOfFigure, double a, double b = 0 )
{
   switch (typeOfFigure) {
    case Type::circle : 
        return new Circle( a );
    case Type::rectangle :
        return new Rectangle( a, b );
    case Type::sqare :
        return new Square( a );
    case Type::triangle :
        return new Triangle( a, b );
    default:
        std::cout << "Wrong choise";
        return  0;
    }
};

double printSurfaceAreaFor( Type typeOfFigure, std::vector<Figure*> figure )
{
  for( auto chosenFigure : figure )
  {
    if( dynamic_cast<Circle*> (chosenFigure) != NULL && typeOfFigure == Type::circle ) 
      std::cout << "Surface area : " << chosenFigure->getSurfaceArea() << std::endl;
    if( dynamic_cast<Rectangle*> (chosenFigure) != NULL && typeOfFigure == Type::rectangle ) 
      std::cout << "Surface area : " << chosenFigure->getSurfaceArea() << std::endl;
    if( dynamic_cast<Square*> (chosenFigure) != NULL && typeOfFigure == Type::sqare ) 
      std::cout << "Surface area : " << chosenFigure->getSurfaceArea() << std::endl;
    if( dynamic_cast<Triangle*> (chosenFigure) != NULL && typeOfFigure == Type::triangle ) 
      std::cout << "Surface area : " << chosenFigure->getSurfaceArea() << std::endl;
  }

};

