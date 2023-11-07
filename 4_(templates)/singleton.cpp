#include <iostream>

using namespace std;

class Singleton{
    private:
        Singleton() {}
        static Singleton *_instance;

    public:
        static Singleton *get_instance(){
            if(_instance == NULL)
                _instance = new Singleton();
            return _instance;
        }

        void test_print(){
            cout << "hi" << endl;
        }
};
Singleton *Singleton::_instance = NULL;


class Random{
    Random () {}
    static Random *_instance;

    public:
        static Random *get_instance(){
            if (_instance == NULL)
                _instance = new Random();
            return _instance;
        }

        void test_print(){
            cout << "hi" << endl;
        }
};
Random *Random::_instance = NULL;


int main(){
    Random *r = Random::get_instance();

    r->test_print();
    Random::get_instance()->test_print(); //SAME
}