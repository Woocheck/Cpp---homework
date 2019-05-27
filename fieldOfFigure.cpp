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

enum class type { circle, rectangle, sqare, triangle };

class Figure
{
   protected: 
     double surfaceArea { 0 };

   public:
     Figure( double s ): surfaceArea { s } {};
     virtual double getSurfaceArea() {return surfaceArea; };
};

class Circle : public Figure
{
   private:
     const double pi { 3.1415 };
   public:
     Circle( double radius ): Figure { radius * radius * pi } {};
     double getSurfaceArea() {return Figure::surfaceArea; };
};

class Rectangle : public Figure
{
   public:  
     Rectangle( double a, double b): Figure { a * b } {};
     double getSurfaceArea() {return Figure::surfaceArea; };
};

class Square : public Rectangle
{
   public:
     Square( double a ): Rectangle { a, a } {};
     double getSurfaceArea() {return Figure::surfaceArea; };
};

class Triangle : public Figure
{
   public:
    Triangle( double a , double h ): Figure {0.5 * a * h } {};
    double getSurfaceArea() {return Figure::surfaceArea; };
};

Figure *newFigure( type typeOfFigure, double a = 0, double b = 0 )
{
   switch (typeOfFigure) {
    case type::circle :
        return new Circle( a );
    case type::rectangle :
        return new Rectangle( a, b );
    case type::sqare :
        return new Square( a );
    case type::triangle :
        return new Triangle( a, b );
    default:
        return new Figure( a );
    }
};


int main()
{
   std::vector<Figure*> figure;
   double a {0};
   double b {0};
   std::cout << "Please write Circle radius: ";
   std::cin >> a;
   figure.push_back( newFigure( type::circle, a) );

   std::cout << "Surface area of circle: " << figure.at(0)->getSurfaceArea() << std::endl;


}