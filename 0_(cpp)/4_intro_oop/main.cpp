#include <iostream>

using namespace std;

class Human{
    private:
    //can't be accessed outside the class
        string ocupation;
        int age;

    public:  
        //attributes
        string name = "Davi";

        //construct
        Human(string name = "", string oo = "", int a = 0){ //0 will be thew default value
            this->name = name;
            ocupation = oo;
            set_age(a);  //I can use my methods/gets-sets inside the constructor.
        }

        //gets/sets
        string get_name(){return name;}
        string get_ocupation(){return ocupation;}
        int get_age(){return age;}

        void set_name(string n){name = n;}
        void set_ocupation(string o){ocupation = o;}
        void set_age(int a){age = a;}

        //methods
        void eat(){cout << "eat" << endl;}
        void drink(string something){cout << "drink " << something << endl;}
};

int main(){
    Human object_human, object_human2("Davi", "Student", 20);

    object_human.name = "Nasiasene";
    object_human.set_ocupation("Programmer");
    cout << object_human.name << endl;
    cout << object_human.get_age() << endl;
    cout << object_human.get_ocupation() << endl;

    cout << object_human2.name << endl;
    cout << object_human2.get_ocupation() << endl;
    cout << object_human2.get_age() << endl;

    object_human.eat();
    object_human2.drink("milk");
}