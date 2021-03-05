#include "Point.cpp"

int main()
{
    Point point1, point2;
    point1.read();
    point2.read();

    std::cout << point1.distanceFrom0() << std::endl;
    std::cout << point2.distanceFrom0() << std::endl;

    std::cout << distanceBetweenTwo(point1, point2);
}