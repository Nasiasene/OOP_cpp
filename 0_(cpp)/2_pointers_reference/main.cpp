#include <iostream>

using namespace std;

void print_a(int *a){
    cout << "A value: "<< *a << endl;
    cout << "A memory adress: " << a << endl;
}

//reference
void soma_ref(int & a, int & b, int & c){  //I can do the same with ponters
    c = a + b;
}

int main(){
    int a = 50;

    cout << "A value: "<< a << endl;
    cout << "A memory adress: " << &a << endl;

    //Pointer:
    int *p = nullptr;
    p = &a;
    print_a(p);


    //Reference:
    int x=2, y=3, z=0;

    soma_ref(x, y, z);
    cout << "\n\nValor de c: " << z;


    string str="Ola Mundo";
    string & ref_str = str;

    cout << "\n\nString: " << str << endl << "Ref: " << ref_str;
    ref_str = ref_str + "Sou brasileiro";
    cout << "\n\nString: " << str << endl << "Ref: " << ref_str;


    //Array:
    string names[] = {"DAVI", "NASIASENE"};
    string names_2[2];

    names_2[0] = "davi";
    names_2[1] = "nasiasene";

    return 0;
}