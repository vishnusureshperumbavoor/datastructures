#include <iostream>
using namespace std;
template <class T>
class bubble{
    int arr[5],num,i,j;
    public:
        void enterelement();
        void bubblesort();
        void swap(T*,T*);
        void display();
};
template <typename T>void bubble<T> :: enterelement(){
    cout << "Enter the number of elements" << endl;
    cin >> num;
    cout << "Enter the elements" << endl;
    for(i=0;i<num;i++){
        cin >> arr[i];
    }
}
template <typename T>void bubble<T> :: bubblesort(){
    for(i=0;i<num-1;i++){
        bool flag=false;
        for(j=0;j<num-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                flag=true;
            }
        }
        if(flag==false){
            break;
        }
    }
}
template <typename T>void bubble<T> :: display(){
    cout << "Sorted List" << endl;
    for(i=0;i<num;i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
}
template <typename T>void bubble<T> :: swap(T* num1,T* num2){
    T temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
int main(){
    bubble<int>b;
    b.enterelement();
    b.bubblesort();
    b.display();
}