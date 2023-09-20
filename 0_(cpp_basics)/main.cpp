#include <iostream>
#include <string>

using namespace std;

class BubuDudu{
    private:
        string name, amor;
    
    public:
        BubuDudu(string n){
            name = n;
            if (name == "Bubu" || name == "Maira"){
                amor = "Dudu";
            }
            else{
                amor = "Bubu";
            }
        };
        ~BubuDudu(){
            cout << "Nada destro'i o amor." << endl;
        }

        void amor_verdadeiro(){
            cout << "O amor verdadeiro de " << name << " e' " << amor << endl;
        };

};

int main(){ 
    BubuDudu bubu{"Maira"}, dudu{"Davi"};

    bubu.amor_verdadeiro();
    dudu.amor_verdadeiro();
}