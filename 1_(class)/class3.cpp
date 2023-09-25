#include <iostream>

using namespace std;

class Car{
    string color;
    string name;
    int motor;
    static int howmany;

    public:
        Car(string cc = "Default", string nn = "Default", int mm = 0): color{cc}, name{nn}, motor(mm) {howmany++;}
        ~Car(){howmany--;}

        string get_color(){return color;}
        string get_name(){return name;}
        int get_motor(){return motor;}

        void set_color(string cc){color = cc;}
        void set_name(string nn){name = nn;}
        void set_motor(int mm){motor = mm;}
        void print_info(){
            cout << "------------------------" << "\nName: " << this->name << "\nColor: " << this->get_color() << "\nMotor: " << motor << endl;
        }

        static int get_howmany(){return howmany;}
        static int motor_power(int mm){return 220*mm;} //pseudo motor power

};

int Car::howmany = 0;

int main(){
    Car car1{"Blue", "Honda", 22};
    Car car2{"Gray", "Tesla", 202};
    Car *car3 = new Car("Black");

    car1.print_info();
    car2.print_info();
    car3->print_info();

    cout << "\n^^^^^^^^^^^^^^^^^^\n" << Car::get_howmany() << endl << car1.get_howmany() << endl << car2.get_howmany() << endl;

    delete car3;
    car2.~Car();

    cout << "\n\n\n" << car1.motor_power(car1.get_motor()) << endl;
    cout << Car::motor_power(car1.get_motor()) << endl;
    cout << Car::motor_power(22) << "\n\n\n";


    cout << "\n^^^^^^^^^^^^^^^^^^\n" << Car::get_howmany() << endl << car1.get_howmany() << endl;

    car1.~Car();
    
    cout << "\n^^^^^^^^^^^^^^^^^^\n" << Car::get_howmany() << endl;
};