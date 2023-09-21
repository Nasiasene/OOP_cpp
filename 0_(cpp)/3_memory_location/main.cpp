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
       //Strings
    str hello = "testing!", test_string;

    cout << "Insert an full name: ";
    std::getline(cin, test_string);  //this way i can can input an string with spaces, wihtou this function, its not possible.
    /*OBS: if you use this function after using an "cin" it will be an problem, to solve this,
           it's necessary to use getline(std::cin >> std::ws, <name_var>).
    */

   test_string = test_string + " " + hello;  // same as test_string.append(str);
   cout << test_string;


   //Dynamic Memory:
   string *pNames = nullptr;
   int size;
   cout << "\n\nPut the size of the array: ";
   cin >> size;

   pNames = new string[size];

   for (int i=0; i < size; i++){
       string new_str;
       cout << "Fill the array with strings: ";
       cin >> new_str;

       pNames[i] = new_str;
   }

   for ( int i = 0; i < size; i++){
       cout << pNames[i] << endl;
   }

   delete[] pNames;
   cout << endl << pNames[0] << endl;   //will be an randon value.

   int *pInt = nullptr;
   pInt = new int;

   *pInt = 22;           //Remember, when you work with pointers, his actual value is an memory position.

   cout << "Pointer memory: " << pInt << "\nPointer value: " << *pInt << endl;

   delete pInt;
    
   cout << "Pointer memory: " << pInt << "\nPointer value: " << *pInt << endl;

   

   
};
