#include "Point.h"
#include <iostream>
#include <cmath>

void Point::read()
{
    std::cout << "Enter coordinate for X";
    std::cin >> x;
    std::cout << "Enter coordinate for Y";
    std::cin >> y;
}
void Point::write()
{
    std::cout << "The point is with coordinates (" << x << ";" << y << ")";
}
double Point::distanceFrom0()
{
   return sqrt(x * x + y * y);
}

double distanceBetweenTwo(Point point1, Point point2)
{
    return sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));
}