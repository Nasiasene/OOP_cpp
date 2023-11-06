#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee{
    string name;
    int age;

    public:
        Employee(string nn, int aa) : name{nn}, age{aa} {}

        void print_info(){
            cout << "Name: " << name << endl << "Age: " << age << endl;
        }

        friend ostream& operator<<(ostream& o, Employee& ee){
            o << "Name: " << ee.name << endl << "Age: " << ee.age << endl;
            return o;
        }
};

class Manager : public Employee{
    string departmaent;
    int access_level;

    public:
        Manager(string nn, int aa, string dp, int al) : Employee(nn, aa), departmaent{dp}, access_level{al}{}

        void print_info(){
            Employee::print_info();
            cout << "Department: " << departmaent << endl << "Access Level: " << access_level << endl;
        }

        void define_access_level(int al){access_level=al;}
};

class Developer : protected Employee{
    protected:
        string programming_language;

    public:
        Developer(string nn, int aa, string pl) : Employee(nn, aa), programming_language{pl}{}

        void print_info(){
            Employee::print_info();
            cout << "Programming Language: " << programming_language << endl;
        }
};

class Analyst : private Employee{
    string current_project;

    public:
        Analyst(string nn, int aa, string cp) : Employee(nn, aa), current_project{cp}{}

        void print_info(){
            Employee::print_info();
            cout << "Current Project: " << current_project << endl;
        }

        void definde_current_project(string cp){current_project = cp;}
};

class EmployeeIntern : public Analyst, public Developer{
    int internship_duration_months;

    public:
        EmployeeIntern(string nn, int aa, string cp, string pl, int idm) : Analyst(nn, aa, cp), Developer{nn, aa, pl}, internship_duration_months{idm} {}

        void print_info(){
            Analyst::print_info();
            cout << "Programming Language: " << Developer::programming_language << endl;
            cout << "Internship duration: " << internship_duration_months << " months" << endl;
        }
};



int main() {
    Employee emp("Johny", 28);
    Manager mgr("Maira", 20, "HR", 2);
    Developer dev("Nasiasene", 20, "C++");
    Analyst analyst("Suzy", 78, "Project LUNA");
    EmployeeIntern intern("Davi", 22, "Project Tril", "Python", 6);

    cout << "Employee Info: " << endl;
    emp.print_info();
    cout << endl;

    cout << "Manager Info: " << endl;
    mgr.print_info();
    mgr.define_access_level(3);
    cout << "After setting a new access level: " << endl;
    mgr.print_info();
    cout << endl;

    cout << "Developer Info: " << endl;
    dev.print_info();
    cout << endl;

    cout << "Analyst Info: " << endl;
    analyst.print_info();
    analyst.definde_current_project("Project MOCOCA");
    cout << "After changing the current project: " << endl;
    analyst.print_info();
    cout << endl;

    cout << "Employee Intern Info: " << endl;
    intern.print_info();
    cout << endl;

    return 0;
}