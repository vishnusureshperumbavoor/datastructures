#include <iostream>
using namespace std;
template <class T> 
class stack{
    T arr[10];
    int top,max;
    public : 
        stack();
        void push(T);
        T pop();
        void list();
        int isfull();
        int isempty();
        T topstack();
};
template <class T> 
stack <T> :: stack(){
    top = -1;
    max = 3;
}
template <class T> 
void stack <T> :: push(T ele){
        top++;
        arr[top] = ele;
        cout << "pushed arr[" << top << "] = " << ele << endl;
}
template <class T> 
T stack <T> :: pop(){ 
    T data = arr[top];
    top--;
    return data;
}
template <class T> 
void stack <T> :: list(){
    cout << "Elements in the stack - " << endl;
    for(int i=0;i<=top;i++)
        cout << arr[i] << "\t";
    cout << endl;
}
template <typename T>
int stack<T> :: isfull(){
    if(top==max-1)
        return 1;
    else 
        return 0;
}
template <typename T>
int stack<T> :: isempty(){
    if(top==-1)
        return 1;
    else 
        return 0;
}
template <typename T>
T stack<T> :: topstack(){
        return arr[top];
}
int main(){
    stack <int> s;
    int num;
    while(num!=4){
        cout << "1.PUSH\t2.POP\t3.List\t4.Exit" << endl;
        cin >> num;
        switch(num){
            case 1:
                if(s.isfull())
                    cout << "stack is full" << endl;
                else{
                    cout << "Enter the element to push " << endl;
                    cin >> num;
                    s.push(num);
                }
                break;
            case 2:
                if(s.isempty())
                    cout << "stack is empty" << endl;
                else
                    cout << "popped out " << s.pop() << endl;;
                break;
            case 3:
                if(s.isempty())
                    cout << "stack is empty" << endl;
                else
                    s.list();
                break;
            case 4:
                exit(0);
            default :
                cout << "enter valid number" << endl;
                break;
        }
    }
}