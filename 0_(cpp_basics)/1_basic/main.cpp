/*
Playing with variables and if/else stetments.

obs: This way i can comment multiple lines.
*/
#include <iostream>
#include <cmath> //math functions

using namespace std;

/*OTHER WAY:
using std::cout;
using std::cin;
using std::endl;
using std::string;
*/


typedef string str;  //this way i can reduce my code and create a new type of data.
/*OTHER WAY:
using str = string;
*/

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
    const double PI_CONST_MAIN = 3.14;
    var1 = 21;
    
    print_var(var1, var2);

    cout << "Insert 1 to swap the variables or type anything else to not. " << endl;
    cin >> option;


    //If/Else/Switch 
    if (option == 1){
        var3 = var1;
        var1 = var2;
        var2 = var3;
    }

    print_var(var1, var2);

    double r = 22.4;
    cout << "\n\n\nArea of a circle with radius = 22.4: " << area(r);


    //Loops:
    int x = 0;
    while(x < 2){
        cout << x << endl;
        x++;
    };

    do{
        cout << x << endl;
        x++;
    }while(x < 4);


    for (int i = 0; i < x; i++){
        cout << "\nx= " << x << "\ni= " << i;
    };


    //Vectors:
    int vet[] = {0, 1, 2, 3 ,4};

    for (int x : vet){        //iterates the vector
        cout << x << endl;
    };


    //Type Conversion:
    int i = 8, x = 10;
    double j = i/x, z = x;

    cout << j << endl;
    cout << i/x << endl;
    cout << (double) i/x << endl;
    cout << i/z << endl; 
    j = i/z;                            
    cout << j << endl;
    //OBS: [double]*, +, -, /[int] = [double]


    //String:
    str hello = "testing!", test_string;

    cout << "Insert an full name: ";
    std::getline(cin, test_string);  //this way i can can input an string with spaces, wihtou this function, its not possible.
    /*OBS: if you use this function after using an "cin" it will be an problem, to solve this,
           it's necessary to use getline(std::cin >> std::ws, <name_var>).
    */

    test_string += hello;  // same as test_string.append(str);
    cout << test_string;


    return 0;
} 