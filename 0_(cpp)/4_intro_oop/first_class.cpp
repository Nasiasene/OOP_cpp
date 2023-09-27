#include <iostream>
#include <string>

using namespace std;

class ShakipiyoGudetama{
    private:
        string name, love;
    
    public:
        ShakipiyoGudetama(string n){
            name = n;
            if (name == "Shaki" || name == "Maira"){
                love = "Gudetama";
            }
            else{
                love = "Shaki";
            }
        };
        ~ShakipiyoGudetama(){
            cout << "Love is beautiful." << endl;
        }

        void true_love(){
            cout << "The true love of " << name << " is " << love << endl;
        };

};

int main(){ 
    ShakipiyoGudetama shaki("Maira"), gudetama("Davi");

    shaki.true_love();
    gudetama.true_love();
}