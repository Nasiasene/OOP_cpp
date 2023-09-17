/*
Playing with variables and if/else stetments.

obs: This way i can comment multiple lines.
*/
#include <iostream>
#include <cmath> //math functions

using namespace std;

#define pi_constant 3.14  // to define a constant
float pi_global = 3.14;   // to define a global variable

void print_var(int var1, int var2){
    std::cout << "Variable1: " << var1 << "  /  Variable2: " << var2 << std::endl;
}

double area(double r){
    return pi_constant * pow(r, 2);  // r^2
}

int main(){
    int var1, var2  = 12, var3;
    int option;
    var1 = 21;
    
    print_var(var1, var2);

    cout << "Insert 1 to swap the variables or type anything else to not. " << endl;
    cin >> option;

    if (option == 1){
        var3 = var1;
        var1 = var2;
        var2 = var3;
    }

    print_var(var1, var2);

    double r = 22.4;
    cout << "\n\n\nArea of a circle with radius = 22.4: " << area(r);

    return 0;
} 