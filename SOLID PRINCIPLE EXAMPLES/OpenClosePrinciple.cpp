//OPen/CLose Principle - Class Open for extension but close for modification
#include <bits/stdc++.h>
using namespace std;

class Rectangle{
    public:
        int len;
        int wdt;
};

class Circle{
    public:
        int rad;
};


//here if we want to add any new shape then again i have to change the class - so here we have to modify this - if we have to add triangle
class CalculateArea{
    public:
        double area_of_rectangle(int len, int wdt){
            return len*wdt;
        }
        double area_of_circle(int rad){
            return 3.14*rad*rad;
        }
};

//now if we want to execute in open/close principle way then


#include <bits/stdc++.h>
using namespace std;

class Shape{
    public:
        virtual double area () const = 0;
        virtual ~Shape(){}
};

class Rectangle: public Shape{
    public:
        int width, length;
        Rectangle(int w, int l) : width(w), length(l){}
        double area() const override{
            return width*length;
        }
};

class Circle: public Shape{
    public:
        int rad;
        Circle(int r) : rad(r){}
        double area() const override{
            return 3.14*rad*rad;
        }
};

class AreaCalculator{
    public:
        double calculateArea(Shape & shape){
            return shape.area();
        }
};


int main(){
    Rectangle r1(3,4);
    Circle c1(3);

    AreaCalculator a1;
    cout<<"Area of rectangle is: "<<a1.calculateArea(r1)<<endl;
    cout<<"Area of circle is: "<<a1.calculateArea(c1)<<endl;
    return 0;
}
