#include <iostream>
#include <cmath>

using namespace std;

const string nl = "\n----------------------------------\n";

class Complex{
    double re, im;

    public:
        Complex(double rr = 0.0, double ii = 0.0) : re{rr}, im{ii}{}
        ~Complex() {}

        void print_info(){
            cout << re << " + (" << im << ")i" << endl;
        }
        Complex add(Complex& cc){
            float x = this->re + cc.re;
            float y = this->im + cc.im;
            return Complex(x, y);
        }
        Complex sub(Complex& cc){
            float x = re - cc.re;
            float y = this->im - cc.im;
            return Complex(x, y);
        }
        void set_nums(double rr, double ii){re=rr; im=ii;}

        //OVERLOAD (to do the same):
        //Binary:
        Complex operator+(Complex& cc){
            return Complex(this->re + cc.re, this->im + cc.im);
        }

        Complex operator-(Complex& cc){
            return Complex(re - cc.re, im - cc.im);
        }

        //Unary
        Complex& operator++(){  //Post increment  (++x)
            this->im = this->im + 1;
            re +=1;
            return *this;     //Reference to the self object, used in ++ and --.   //Is util only in case: x = ++y
        }

        bool operator!(){
            if(re == 0 && this->im == 0){
                return true;
            }
            return false;
        }

        friend void print(Complex& cc);          //FRIEND FUNCTION. IS NOT AN MEMBER.
        friend void print_re(Complex& cc){       //Can be declare inside the class, but still not an member.
            cout << cc.re;
        }
        friend Complex operator*(Complex& c1, Complex& c2);
        friend ostream& operator<<(ostream& o, Complex& cc);
        friend void operator>>(ostream& o, Complex& cc);
        operator int(){
           return sqrt(re * re + im * im); 
        }
};

void print(Complex& cc){                         
    cout << cc.re << " + (" << cc.im << ")i";
}

Complex operator*(Complex& c1, Complex& c2){
    return Complex(c1.re * c2.re, c1.im * c2.im);
}

ostream& operator<<(ostream& o, Complex& cc){
    o << cc.re << " + (" << cc.im << ")i";
    return o;
}

void operator>>(istream& in, Complex& cc){
    double rr, ii;
    in >> rr;
    in >> ii;
    cc.set_nums(rr, ii);
}

int main(){
    Complex n1(10, 20);
    Complex n2(5, 15);

    n1.print_info();
    n2.print_info();

    cout << nl;

    Complex n3, n4;

    n3 = n1.add(n2);
    n4 = n2.sub(n1);

    n3.print_info();
    n4.print_info();

    cout << nl;

    Complex n5, n6;

    n5 = n1.operator+(n2); //SAME AS: n5 = n1 = n2;

    n5.print_info();

    cout << nl;

    ++n5;
    n5.print_info();

    if(!n6)
        cout << nl << "n6 = 0" << endl;

    cout << nl << "N1: ";
    print(n1);
    cout << "\nReal N1: ";
    print_re(n1);



    Complex n7, n8;
    n7 = n1*n2;
    cout << nl << "n7: ";
    print(n7);

    n8 = n1.operator++();
    cout << nl << "n8: " << n8; //using operator ostream;

    Complex n9;
    cout << nl << "Input n9 Values: ";
    cin >> n9;
    cout << n9; 
    cout << "\nNew N9: " << int(n9);


}