#include <iostream>
#include <cstdlib> //rand
#include <vector>
#include <string>

using namespace std;

template <typename T>
void print_vector(T v, int size){
    for(int i = 0; i<size; i++){
        cout << v[i] << ' ';
    }
}

template <typename TEM>
void sort_vector(TEM &v, int size){
    for(int i = 0; i < size; i++){
        for(int j=0; j < size -1 -i; j++){
            if (v[j+1] < v[j]){
                auto aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T, typename A>
T print_both(T a, A b) {
    cout << "A: " << a << endl << "B: " << b;
}


template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
template <> // specific template for variables of type const char*
const char* max(const char* a, const char* b) {
    return (strcmp(a,b) > 0) ? a : b;
}



template <typename T>
class Stack{

    vector<T> stack;

    public:
        Stack() { }
        ~Stack() {stack.clear();}

        bool is_empty() {return stack.empty();}
        void push(T elem) {stack.push_back(elem);}
        void pop() {
            if (!is_empty()) {
                stack.pop_back();
            }
        }
        T top() {
            if (!is_empty()) {
                return stack.back();
            }
            return (T) NULL;
        }
};


int main(){
    vector<float> vec_flo(10);
    vector<int> vec_int(10);

    for(int i = 0; i < 10; i++){
        vec_flo[i] = (float)(rand()%100)/100.0;
        vec_int[i] = rand() % 100;
    }

    cout << "Float Vector: ";
    print_vector(vec_flo, 10);
    cout << "\nInt Vector: ";
    print_vector(vec_int, 10);

    sort_vector(vec_flo, 10);
    sort_vector(vec_int, 10);
    cout << "\n\nAfter sorting:\n\n";
    cout << "Float Vector: ";
    print_vector(vec_flo, 10);
    cout << "\nInt Vector: ";
    print_vector(vec_int, 10);



    //CLASS:
    Stack<int> stack_int;
    Stack<string> stack_str;

    stack_int.push(10);
    stack_int.push(13);
    stack_int.push(6);
    stack_int.push(2);

    stack_str.push("hi");
    stack_str.push("oi");
    stack_str.push("bonjour");
    stack_str.push("konichua????????");

    stack_str.pop();



}