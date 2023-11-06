#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Form{ //Abstract class
    protected:
        double x, y;

    public:
        Form(double xx=0, double yy=0) : x{xx}, y{yy} {}

        virtual void print_info() { 
            cout << "Origin: (" << x << ", " << y << ")" << endl << "Area: " << area() << endl;
        } 
        virtual double area() = 0; // PURE VIRTUAL
};

class Rectangle : public Form{
    double base, height;

    public:
        Rectangle(double xx=0, double yy=0, double ba = 0, double he = 0) : Form(xx, yy), base{ba}, height{he} {}

        virtual void print_info() override {
            Form::print_info();
            cout << "Base: " << base << endl << "Height: " << height << endl; 
        }
        double area(){return base*height;} //Note as it is not virtual, if it has a subclass, it will not be able to do polymorphism with this function
};

class Circle : public Form{
    double radius;

    public:
        Circle(double xx=0, double yy=0, double ra = 0) : Form(xx, yy), radius{ra} {}

        virtual void print_info() override {
            Form::print_info();
            cout << "Radius: " << radius << endl; 
        }
        double area(){return 3.14*radius*radius;} // Note as it is not virtual, if it has a subclass, it will not be able to do polymorphism with this function
};


int main(){
    // Form point1(10.0, 2);
    // cout << "Point - \n";
    // point1.print_info();
    // cout << endl;

    // As i made form an abstract class, with a pure virtual function, I cannot create objects from it.
    
    Rectangle rec1(5, 9, 2, 6);
    cout << "Rectangle - \n";
    rec1.print_info();
    cout << endl;
    
    Form* rec2 = new Rectangle(5, 9, 2, 6);
    cout << "Pointer to Rectangle - \n";
    rec2->print_info();  // As the functions are virtual, the print will be the same.
    cout << endl;

    Form* circ1 = new Circle(0, 0, 2);
    cout << "Circle - \n";
    circ1->print_info();
    cout << endl;


    vector<Form*> forms;
    forms.push_back(new Rectangle(45, 2, 5, 1));
    forms.push_back(new Circle(2, 4, 10));
    //forms.push_back(new Form(0, 0));
    forms.push_back(new Circle(9.5, 0.1, 1));
    //forms.push_back(new Form(22, 13));
    forms.push_back(new Circle(0, 7, 8));
    forms.push_back(new Rectangle(-2, 2, 3, 4));

    for(auto i : forms){
        cout << "Form: " << endl;
        i->print_info();
        cout << endl << endl;
    }
}