#include <iostream>
using namespace std;
template <typename T>
class stack{
    int top;
    public :
        T arr[100];
        stack();
        T isEmpty();
        T peek();
        T pop();
        void push(T);
        void display();
};
template <typename T>
stack<T> :: stack(){
    top = -1;
}
template <typename T>
T stack<T> :: isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}
template <typename T>
void stack<T> :: push(T ele){
    top++;
    arr[top] = ele;
}
template <typename T>
T stack<T> :: pop(){
    T x = arr[top];
    top--;
    return x;
}
template <typename T>
T stack<T> :: peek(){
    return arr[top];
}
template <typename T>
void stack<T> :: display(){
    for(int i=top;i>=0;i--){
        cout << arr[i];
    }
    cout << endl;
}
