#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Client{
    string name, phone;

    public:
        Client(string nn, string pp) : name{nn}, phone{pp} {}
        ~Client() {}

        string get_name(){return name;}
        string get_phone(){return phone;}
};

class Vehicle{
    string model;
    int year, plate;

    public:
        Vehicle(string mm, int yy, int pp) : model{mm}, year{yy}, plate{pp} {}
        ~Vehicle() {}

        string get_model(){return model;}
        int get_year(){return year;}
        int get_plate(){return plate;}

};

class Employee{
    string name, position;

    public:
        Employee(string nn, string pp) : name{nn}, position{pp} {}
        ~Employee() {}

        string get_name(){return name;}
        string get_position(){return position;}

};

class Service{
    string description;
    double value;
    Client* client;
    Vehicle* vehicle;
    vector<Employee*> employees;

    public:
        Service(string dec, Client *cc, Vehicle *vv, double va) : description{dec}, client{cc}, vehicle{vv}, value{va} {}
        ~Service(){employees.clear();}

        string get_description(){return description;}
        int get_value(){return value;}

        void add_employee(Employee &ee){
            employees.push_back(&ee);
        }

        void get_service(){
            cout << "\nClient: " << client->get_name() << "\nVehicle: " << vehicle->get_model() << "\n" << "Value: " << value << "\nEmployees: ";
            for (int i = 0; i < employees.size(); i ++){
                cout << "\n" << i+1 << ": " << employees[i]->get_name() << " // " << employees[i]->get_position() << ".";
            }
            cout << "\n-----------------------------\n";
        }
};

int main(){
    Employee e1("Eduardo", "Boss");
    Employee e2("Carlos", "Engineer");

    Client c1("Davi", "83 99999-8080");
    Client c2("Nasiasene", "83 88888-9898");
    Client c3("Amorim", "83 77777-6666");

    Vehicle v1("Honda", 2020, 11111);
    Vehicle v2("Fiat", 2022, 22222);
    Vehicle v3("volkswagen", 1998, 33333);


    Service s1("Changing tire", &c1, &v2, 200.00);
    s1.add_employee(e1);
    s1.get_service();

    Service s2("Change door", &c2, &v3, 2000.750);
    s2.add_employee(e2);
    s2.get_service();

    Service s3("Changw engine", &c3, &v1, 5000.750);
    s3.add_employee(e1);
    s3.add_employee(e2);
    s3.get_service();

}