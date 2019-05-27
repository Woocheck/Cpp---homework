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
};

class Rectangle : public Figure
{
   public:  
     Rectangle( double a, double b): Figure { a * b } {};
};

class Square : public Rectangle
{
   public:
     Square( double a ): Rectangle { a, a } {};
};

class Triangle : public Figure
{
   public:
    Triangle( double a , double h ): Figure {0.5 * a * h } {};
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
   std::vector<Figure>* figure {};

   std::cout << 


}