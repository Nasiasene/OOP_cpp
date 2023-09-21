#include <iostream>

using namespace std;

class Time{
    // Private members cannot be accessed outside the class, only inside it.
    //note: when creating a class it starts private.
    private:
        int hour, minute, second;

    // Public members can be accessed inside and outside classes.
    public:
        Time(int h = 0, int m = 0, int s = 0){
            hour = h;
            minute = m;
            second = s;
        } //Construct, called when starting a class
        void get_time(); //get PROTOTYPE
        void set_time(int h, int m, int s); //set PROTOTYPE
        ~Time(){} //Destructor. In this case it is unnecessary.
        //NOTE: all the methods mentioned (except constructor and destructor) above are only "initialized", they will be constructed after the class is defined.
};

void Time::set_time(int h = 0, int m = 0, int s = 0){
    hour = h;
    minute = m;
    second = s;
}
void Time::get_time(){cout << hour << ":" << minute << ":" << second << endl;}

int main(){
    Time t;

    t.set_time(10, 20);
    t.get_time();
}