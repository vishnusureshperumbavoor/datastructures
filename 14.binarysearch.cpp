#include <iostream>
using namespace std;
template <class T>
class search{
    int data,size,i,mid;
    T arr[10];
    public:
        void enterelement();
        void binary(T);
        void binarysearch(int,int,int);
};
template <typename T>
void search<T> :: enterelement(){
    cout << "Enter the number of elements" << endl;
    cin >> size;
    cout << "Enter the elements" << endl;
    for(i=0;i<size;i++){
        cin >> arr[i];
    }
}
template <typename T>
void search<T> :: binary(T data){
    binarysearch(data,0,size-1);
}
template <typename T>
void search<T> :: binarysearch(int data,int low,int high){
    mid = (low+high)/2;
    if(low>high){
        cout << data << " does not found" << endl;
    }
    else if(data==arr[mid]){
        cout << "Element found in position " << mid+1 << endl;
    }
    else if(data<arr[mid]){
        binarysearch(low,mid-1,data);
    }
    else{
        binarysearch(mid+1,high,data);
    }
}
int main(){
    int data;
    search <int> b;
    b.enterelement();
    cout << "Search Element" << endl;
    cin >> data;
    b.binary(data);
}
