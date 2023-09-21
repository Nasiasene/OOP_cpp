#include <iostream>
#include <string>

using namespace std;

class ShakipiyoGudetama{
    private:
        string name, amor;
    
    public:
        ShakipiyoGudetama(string n){
            name = n;
            if (name == "Shaki" || name == "Maira"){
                amor = "Gudetama";
            }
            else{
                amor = "Shaki";
            }
        };
        ~ShakipiyoGudetama(){
            cout << "Nada destro'i o amor." << endl;
        }

        void amor_verdadeiro(){
            cout << "O amor verdadeiro de " << name << " e' " << amor << endl;
        };

};

int main(){ 
    ShakipiyoGudetama shaki("Maira"), gudetama("Davi");

    shaki.amor_verdadeiro();
    gudetama.amor_verdadeiro();
}