#include <iostream>

using namespace std;

const double PI = 3.14;

class Circle{
    double radius;
    int x, y;

    public:
    //construct
        Circle(float rr=0.0, int xx=0, int yy=0){
            radius = rr;
            x = xx;
            y = yy;
        }

    //gets sets
        double get_radius(){return radius;}
        void set_radius(double rr){(rr > 0) ? radius = rr : radius = 0;}
        void set_origin(int xx = 0, int yy = 0){x = xx; y =yy;}
        double area();
        double diameter();
        void output();
};


double Circle::area(){
    return PI * radius * radius;
}
double Circle::diameter(){
    return 2 * PI * radius;
}

void Circle::output(){
    cout << "\nRadius: " << radius << "\nX/Y: " << x << "/" << y << "\nArea: " << area() << "\nDiameter: " << diameter() << "\n-----------------\n";;
}


int main(){
    Circle c1;
    Circle c2(15, 2);
    Circle c3(20, 1, 1);

    cout << "C1: ";
    c1.output();
    cout << "C2: ";
    c2.output();
    cout << "C3: ";
    c3.output();

    c1.set_origin(22);
    c1.set_radius(-20);
    cout << "C1: ";
    c1.output();
    c1.set_radius(220.445);
    c1.set_origin(-2, 22);
    cout << "C1: ";
    c1.output();

    return 0;
}