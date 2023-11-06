#include <iostream>
#include <string>

using namespace std;

class Person{
    protected:             //halfway between public and private
        string name;
        int age;

    public:
        Person(string nn, int aa) : name{nn}, age{aa} {}
        ~Person() {}

        string get_name(){return name;}
        int get_age(){ return age;}
        void set_name(string nn){name = nn;}
        void set_age(int aa){age = aa;}
        void print_info(){
            cout << "\nName: " << name << "\nAge: " << age << endl;
        }
};

class Student : public Person{
    protected:
        string course;
        int code;

    public:
        Student(string na, int aa, string cour, int co) : Person{na, aa}{
            course= cour; 
            code = co; 
        }
        ~Student() {}

        void set_course(string co) { course = co;}
};

class Professor : public Person{
    string institute;
    int years_work;

    public:
        Professor(string na, int aa, string inst, int yw) : Person{na, aa}, institute{inst}, years_work{yw} {}
        ~Professor() {}

        void promove() { ++years_work;}
        void set_institute(string inst) {institute = inst;}

        void print_info(){
            cout << "\nInstitute: " << institute << "\nYears_work: " << years_work;
            Person::print_info();   //When you have a function with the same name as another in the parent class, you need to specify which one to use.
        }
};

class Professor_Student: public Professor, public Student{
    bool is_active;

    public:
        Professor_Student(string na, int aa, string inst, int yw, string cour, int co) : Professor(na, aa, inst, yw), Student(na, aa, cour, co) {
            is_active = true;
        }

        void print_info(){
            Professor::print_info();
            cout << "Course: " << Student::course << "\nCode: " << code; //As the course and code variables are protected, I can use them in their subclasses.
        }
};



int main(){

    Person p1("Davi", 20);
    p1.print_info();

    Student s1("Nasiasene", 21, "CDIA", 27022205);
    s1.print_info();

    Professor pr1("Amorim", 22, "UFPB", 7);
    pr1.print_info();
    pr1.Person::print_info(); //i can use a function of the other class if i want

    Person p2 = pr1;           //Objects from the parent class can receive the same value as objects from the child class, however, they will only have the values ​​present in the parent class.
    //OBS: the reverse does not occur ((Professor pr1 = Person p1) = ERROR)
    p2.print_info();

    Professor_Student ps("Bidu", 30, "UFPB", 12, "CC", 320221678);
    ps.print_info();

    return 0;
}