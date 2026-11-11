#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Shape
{
protected:
    string name;
    string type;

public:
    Shape(string name, string type)
    {
        this->name = name;
        this->type = type;
    }

    virtual void Show() const
    {
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
    }

    virtual double GetArea() const = 0;

    virtual ~Shape() {}
};


class Rectangle : public Shape
{
private:
    double width;
    double height;

public:
    Rectangle(double width, double height)
        : Shape("Rectangle", "Quadrilateral")
    {
        this->width = width;
        this->height = height;
    }

    void Show() const override
    {
        Shape::Show();
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
    }

    double GetArea() const override
    {
        return width * height;
    }
};


class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double radius)
        : Shape("Circle", "Round shape")
    {
        this->radius = radius;
    }

    void Show() const override
    {
        Shape::Show();
        cout << "Radius: " << radius << endl;
    }

    double GetArea() const override
    {
        return 3.14159 * radius * radius;
    }
};


class RightTriangle : public Shape
{
private:
    double a;
    double b;

public:
    RightTriangle(double a, double b)
        : Shape("Right Triangle", "Triangle")
    {
        this->a = a;
        this->b = b;
    }

    void Show() const override
    {
        Shape::Show();
        cout << "Side A: " << a << endl;
        cout << "Side B: " << b << endl;
    }

    double GetArea() const override
    {
        return a * b / 2;
    }
};


class Triangle : public Shape
{
private:
    double a;
    double b;
    double c;

public:
    Triangle(double a, double b, double c)
        : Shape("Triangle", "Triangle")
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    void Show() const override
    {
        Shape::Show();
        cout << "Side A: " << a << endl;
        cout << "Side B: " << b << endl;
        cout << "Side C: " << c << endl;
    }

    double GetArea() const override
    {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};


class Trapezoid : public Shape
{
private:
    double a;
    double b;
    double height;

public:
    Trapezoid(double a, double b, double height)
        : Shape("Trapezoid", "Quadrilateral")
    {
        this->a = a;
        this->b = b;
        this->height = height;
    }

    void Show() const override
    {
        Shape::Show();
        cout << "Base A: " << a << endl;
        cout << "Base B: " << b << endl;
        cout << "Height: " << height << endl;
    }

    double GetArea() const override
    {
        return (a + b) * height / 2;
    }
};


void TestShape(const Shape& shape)
{
    cout << "------------------------" << endl;
    shape.Show();
    cout << "Area: " << shape.GetArea() << endl;
}

int main()
{
    Rectangle r(5, 10);
    Circle c(4);
    RightTriangle rt(3, 6);
    Triangle t(3, 4, 5);
    Trapezoid tr(6, 10, 4);

    TestShape(r);
    TestShape(c);
    TestShape(rt);
    TestShape(t);
    TestShape(tr);

    return 0;
}
