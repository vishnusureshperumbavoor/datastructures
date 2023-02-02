#include <iostream>
using namespace std;
template <class T>class sort{
    T arr[5];
    int size,i,j;
    public :
        void enterelements();
        void quick();
        void quicksort(int,int);
        int partition(int,int);
        void swap(T*,T*);
        void display();
};
template <typename T>void sort<T> :: enterelements(){
    cout << "Enter the number of Elements" << endl;
    cin >> size;
    cout << "Enter the elements" << endl;
    for(i=0;i<size;i++){
        cin >> arr[i];
    }
}
template <typename T>void sort<T> :: quick(){
    quicksort(0,size-1);
}
template <typename T>void sort<T> :: quicksort(int low,int high){
    if(low<high){
        int pi = partition(low,high);
        quicksort(low,pi-1);
        quicksort(pi+1,high);
    }
}
template <typename T>int sort<T> :: partition(int low,int high){
    T pivot = arr[low];
    int down=low;
    int up=high;
    while(down<up){
        while(arr[down]<=pivot && down<up)
            down++;
        while(arr[up]>pivot)
            up--;
        if(down<up)
            swap(&arr[down],&arr[up]);
    }
    swap(&arr[low],&arr[up]);
    return up;
}
template <typename T>void sort<T> :: display(){
    cout << "Sorted List" << endl;
    for(i=0;i<size;i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
}
template <typename T>void sort<T> :: swap(T* num1,T* num2){
    T temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
int main(){
    sort<int> s;
    s.enterelements();
    s.quick();
    s.display();
}