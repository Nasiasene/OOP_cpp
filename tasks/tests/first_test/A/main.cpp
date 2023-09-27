#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Product{
    string name;
    double price;
    int validity;

    public:
        Product(string nn, double pp, int vv) : name{nn}, price{pp}, validity{vv} {}
        ~Product(){}

        //getters:
        string get_name(){return name;}
        double get_price(){return price;}
        int get_validity(){return validity;}
};

class Client{
    string name;
    string adress;

    public:
        Client(string nn, string adr) : name{nn}, adress{adr} {}
        ~Client(){}

        //getters:
        string get_name(){return name;}
        string get_adress(){return adress;}
};

class Supplier{
    string name;
    string adress;

    public:
        Supplier(string nn, string aa) : name{nn}, adress{aa} {}
        ~Supplier(){}

        //getters:
        string get_name(){return name;}
        string get_adress(){return adress;}

};

class Sell{
    string date;
    double total_value;
    vector<Product*> products;
    Client* client;

    public:
        Sell(string dd, Client* cc) : date{dd}, client{cc} {
            total_value = 0;

        }
        ~Sell(){products.clear();}

        //Creat an new sell
        void new_sell(Product* p, int amount){
            for(int i = 0; i < amount; i++){
                products.push_back(p);
                total_value += p->get_price();
            }
        }

        //getters:
        string get_date(){return date;}
        double get_total_value(){return total_value;}
        void get_products(){
            for(int i = 0; i < products.size(); i++){
                cout << "Product" << i << ": " << products[i]->get_name() << endl;
            }
            cout << "--------------------------------" << endl;
        }
        Client* get_client(){return client;}
};

int main(){
    Supplier sup1("Supplier A", "Adress 1");
    Supplier sup2("Supplier B", "Adress 2");

    Product p1("Bread", 0.50, 3);
    Product p2("Cheese", 0.25, 2);
    Product p3("Atum", 2.50, 6);

    Client c1("Davi", "Cabo Branco");
    Client c2("Nasiasene", "Bessa");

    //First sell
    Sell s1("27/09", &c1);
    s1.new_sell(&p1, 2);
    s1.new_sell(&p2, 5);

    //Prints
    cout << "First sell: " << "\nDate: " << s1.get_date() << "\nClient: " << s1.get_client()->get_name() << "\nTotal value: " << s1.get_total_value() << "\nProducts: ";
    s1.get_products();
    //End first sell


    //Second sell
    Sell s2("10/08", &c2);
    s2.new_sell(&p3, 10);
    s2.new_sell(&p2, 1);
    s2.new_sell(&p1, 1);

    //Prints
    cout << "Second sell: " << "\nDate:" << s2.get_date() << "\nClient: " << s2.get_client()->get_name() << "\nTotal value: " << s2.get_total_value() << "\nProducts: ";
    s2.get_products();
    //End Second sell
}