#include <iostream>
using namespace std;
template <class T>class linear{
    T a[10];
    int size,i;
    public :
        void enterarray();
        void findarray(T);
};
template <typename T>void linear<T> :: enterarray(){
    cout << "Enter the number of element\n";
    cin >> size;
    cout << "Enter the elements\n";
    for(i=0;i<size;i++){
        cin >> a[i];
    }
}
template <typename T>void linear<T>:: findarray(T data){
    for(i=0;i<size;i++){
        if(a[i]==data){
            cout << "Element found in position " << i+1 << endl;
            break;
        }
    }
    if(i==size){
        cout << "Element not found" << endl;
    }
}
int main(){
    linear <int> l;
    int data;
    l.enterarray();
    cout << "Enter the element to search\n";
    cin >> data;
    l.findarray(data);
}