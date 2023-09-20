#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef string str;  //this way i can reduce my code and create a new type of data.
/*
or: using str = string;
*/

int main(){
    str hello = "testing!", test_string;

    cout << "Insert an full name: ";
    std::getline(cin, test_string);  //this way i can can input an string with spaces, wihtou this function, its not possible.
    /*OBS: if you use this function after using an "cin" it will be an problem, to solve this,
           it's necessary to use getline(std::cin >> std::ws, <name_var>).
    */

   test_string += hello;  // same as test_string.append(str);
   cout << test_string;




};
