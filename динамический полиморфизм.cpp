#include <iostream>

class Figure
{
public:
    virtual double getSquare() = 0;
    virtual double getPerimeter() = 0;
    virtual void showFigureType() = 0;
};
class Rectangle : public Figure
{
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h)
    {
    }
    double getSquare() override
    {
        return width * height;
    }
    double getPerimeter() override
    {
        return width * 2 + height * 2;
    }
    void showFigureType()
    {
        std::cout << "Rectangle" << std::endl;
    }
};
class Circle : public Figure
{
private:
    double radius;
public:
    Circle(double r) : radius(r)
    {
    }
    double getSquare() override
    {
        return radius * radius * 3.14;
    }
    double getPerimeter() override
    {
        return 2 * 3.14 * radius;
    }
    void showFigureType()
    {
        std::cout << "Circle" << std::endl;
    }
};

int main()
{
    Rectangle rect(30, 50);
    Circle circle(30);

    std::cout << "Rectangle square: " << rect.getSquare() << std::endl;
    std::cout << "Circle square: " << circle.getSquare() << std::endl;

    return 0;
}