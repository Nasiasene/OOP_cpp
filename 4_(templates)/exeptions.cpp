#include <iostream>
#include <stdexcept>

using namespace std;

class DivideByZeroExeption : public runtime_error{ //Creating an new specific exeption.
    public:
        DivideByZeroExeption() : runtime_error("Attempt to divide by zero!") {}
};


int quotient(int n, int m){
    if (m==0){
        //throw std::runtime_error("Attempt to divide by zero!"); 
        throw DivideByZeroExeption(); //Throw return an error.
    }

    return n/m;
}


int main(){
    int x, y;
    cout << "Define the values of X e Y-\nX: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    try{
        cout << "Result: " << quotient(x, y);
    } catch(DivideByZeroExeption &e){ //Can be catch(runtime_error &ex), since DivideByZeroExeption inherits from runtime_error.
        cout << "ERROR: " << e.what();
    } catch(exception &e){
        cout << "ERROR: Run Time error (general error)!";
    }

    cout << "\n\nEND.";
}