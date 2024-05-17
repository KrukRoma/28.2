#include <iostream>
#include <fstream>
using namespace std;

class Shape 
{
public:
    virtual void Show() const = 0;
    virtual void Save(ostream& out) const = 0;
    virtual void Load(istream& in) = 0;
    virtual ~Shape() = default;
};

class Square : public Shape 
{
private:
    double x, y; 
    double side; 
public:
    Square(double x = 0, double y = 0, double side = 0) : x(x), y(y), side(side) {}

    void Show() const override 
    {
        cout << "Square: (" << x << ", " << y << "), side = " << side << endl;
    }

    void Save(ostream& out) const override 
    {
        out << "Square " << x << " " << y << " " << side << endl;
    }

    void Load(istream& in) override 
    {
        in >> x >> y >> side;
    }
};

class Rectangle : public Shape 
{
private:
    double x, y; 
    double width, height; 

public:
    Rectangle(double x = 0, double y = 0, double width = 0, double height = 0) : x(x), y(y), width(width), height(height) {}

    void Show() const override 
    {
        cout << "Rectangle: (" << x << ", " << y << "), width = " << width << ", height = " << height << endl;
    }

    void Save(ostream& out) const override 
    {
        out << "Rectangle " << x << " " << y << " " << width << " " << height << endl;
    }

    void Load(istream& in) override 
    {
        in >> x >> y >> width >> height;
    }
};

class Circle : public Shape 
{
private:
    double x, y; 
    double radius; 

public:
    Circle(double x = 0, double y = 0, double radius = 0) : x(x), y(y), radius(radius) {}

    void Show() const override 
    {
        cout << "Circle: (" << x << ", " << y << "), radius = " << radius << endl;
    }

    void Save(ostream& out) const override 
    {
        out << "Circle " << x << " " << y << " " << radius << endl;
    }

    void Load(istream& in) override 
    {
        in >> x >> y >> radius;
    }
};

class Ellipse : public Shape 
{
private:
    double x, y; 
    double width, height; 

public:
    Ellipse(double x = 0, double y = 0, double width = 0, double height = 0) : x(x), y(y), width(width), height(height) {}

    void Show() const override 
    {
        cout << "Ellipse: (" << x << ", " << y << "), width = " << width << ", height = " << height << endl;
    }

    void Save(ostream& out) const override 
    {
        out << "Ellipse " << x << " " << y << " " << width << " " << height << endl;
    }

    void Load(istream& in) override 
    {
        in >> x >> y >> width >> height;
    }
};

int main() 
{
    const int numShapes = 4;
    Shape* shapes[numShapes];

    shapes[0] = new Square(1, 1, 5);
    shapes[1] = new Rectangle(2, 2, 6, 4);
    shapes[2] = new Circle(3, 3, 7);
    shapes[3] = new Ellipse(4, 4, 8, 5);

    ofstream outFile("shapes.txt");
    for (int i = 0; i < numShapes; ++i) 
    {
        shapes[i]->Save(outFile);
    }
    outFile.close();

    ifstream inFile("shapes.txt");
    Shape* loadedShapes[numShapes];
    string shapeType;

    for (int i = 0; i < numShapes; ++i) 
    {
        inFile >> shapeType;
        if (shapeType == "Square") 
        {
            loadedShapes[i] = new Square();
        }
        else if (shapeType == "Rectangle") 
        {
            loadedShapes[i] = new Rectangle();
        }
        else if (shapeType == "Circle") 
        {
            loadedShapes[i] = new Circle();
        }
        else if (shapeType == "Ellipse") 
        {
            loadedShapes[i] = new Ellipse();
        }
        loadedShapes[i]->Load(inFile);
    }
    inFile.close();

    for (int i = 0; i < numShapes; ++i) 
    {
        loadedShapes[i]->Show();
        delete loadedShapes[i];
    }

    for (int i = 0; i < numShapes; ++i) 
    {
        delete shapes[i];
    }
}
