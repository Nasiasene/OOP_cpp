#include <iostream>
#include <vector>

using namespace std;

const string NL = "\n------------------\n";

class Client{
    string name, cpf, adress;

    public:
        //Constructot / Destructor
        Client(string nn, string cc, string aa) : name{nn}, cpf{cc}, adress{aa} {}
        ~Client() {}

        //gets / sets:
        string get_name(){return name;}
        string get_cpf(){return this->cpf;} //just tetsing this
        string get_adress(){return this->adress;}
        void print_info(){
            cout << NL << "Name: " << name << "\nCpf: " << this->cpf << "\nAdr: " << this->adress << endl;
        }

        void set_name(string nn){name = nn;}
        void set_cpf(string cc){this->cpf = cc;}
        void set_adress(string aa){adress = aa;}
};

class Operation{
    char type;     //w(withdraw), D(deposit)
    double value;

    public:
        //Constructot / Destructor
        Operation(char tt, double vv) : type{tt}, value{vv} {}
        ~Operation() {}

        //gets / sets:
        char get_type(){return type;}
        double get_value(){return value;}
        void print_info(){
            cout << "Type: " << this->type << "\nValue: " << this->get_value();
        }

        void set_type(char cc){type = cc;}
        void set_value(double vv){this->value = vv;}
};

class Account{
    int account_num;
    Client *client;
    double balance;
    vector<Operation> operations;

    public:
        //Constructot / Destructor
        Account(int nn, Client *cc, double bb) : account_num{nn}, client{cc}, balance{bb}{}
        ~Account(){operations.clear();}

        //gets / sets:
        int get_account_num(){return account_num;}
        Client get_client(){return *client;}
        double return_balance(){return balance;}
        void print_info(){
            cout << NL << "Account Num: " << account_num << "\nClient: " << client->get_name() << "\nBalance: " << balance << "\nOperations: " << endl;
            for(auto i = 0; i < operations.size(); i++){
                operations[i].print_info();
            }
        }

        void set_account_num(int nn){account_num = nn;}
        void set_balance(double bb){balance = bb;}
        void set_client(Client *cc){client = cc;}

        //Operations:
        void add_operation(Operation oo){
            operations.push_back(oo);

            if (oo.get_type() == 'W')
                this->balance -= oo.get_value();
            else
                balance += oo.get_value();
        }
};

class Bank{
    vector<Account> accounts;
    int code;

    public:
        //Constructot / Destructor
        Bank(int cc) : code{cc} {}
        ~Bank(){accounts.clear();}

        //gets
        int get_code(){return code;}
        Account* get_account(int n){
            for(auto i = 0; i < accounts.size(); i ++){
                if(accounts[i].get_account_num() == n)
                    return &accounts[i];
            }

            return nullptr;
        }

        void add_account(Account aa){accounts.push_back(aa);}
        void delete_account(int n){
            for (auto i = 0; i < accounts.size(); i++){
                if (accounts[i].get_account_num() == n){
                    accounts.erase(accounts.begin() + i);
                    break;
                }
            }
        }

        void transfer(Account *a1, Account *a2, double va){
            Operation op1('W', va);
            Operation op2('D', va);
            a1->add_operation(op1);
            a2->add_operation(op2);
        }

        void print_info(){
            cout << NL << "Bank: " << code << "\nAccounts: \n";
            for (auto i = 0; i < accounts.size(); i ++){
                accounts[i].print_info();
            }
        }
};

int main(){
    Client *c1 = new Client("Nasiasene", "123456789-00", "Street 1");
    Client *c2 = new Client("davi", "987654321-00", "Street 2");

    Account *acc1 = new Account(1, c1, 1000.0);
    Account *acc2 = new Account(2, c2, 2000.0);

    Bank *b = new Bank(1);

    b->add_account(*acc1);
    b->add_account(*acc2);

    b->print_info();

    char ch;
    
    cout << "Enter a key to continue( W[withdraw] D[deposit] )" << endl;

    cin >> ch;

    b->transfer(b->get_account(1), b->get_account(2), 100);

    b->print_info();

    return 0;
};