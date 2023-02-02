#include <iostream>
using namespace std;
template <class T>
class circular{
    T max,arr[3],i,rear,front;
    public :
        circular();
        void enqueue(T);
        int dequeue();
        void list();
        T full();
        T empty();
};
template <class T>
circular<T> :: circular(){
    max = 3;
    rear = front = -1;
}
template <class T>
T circular<T> :: full(){
    if((rear+1)%max == front){
        return 1;
    }else{
        return 0;
    }
}
template <class T>
T circular<T> :: empty(){
    if(front==-1){
        return 1;
    }else{
        return 0;
    }
}
template <class T>
void circular<T> :: enqueue(T ele){
    if(front==-1){
        front++;
    }
    rear = (rear+1)%max;
    arr[rear] = ele;
}
template <class T>
int circular<T> :: dequeue(){
    int k = arr[front];
    if(front==rear){
        front = rear = -1;
    }
    else{
        front = (front+1)%max;
    }
    return k;
}
template <class T>
void circular<T> :: list(){
    for(i=front;i!=rear;i=(i+1)%max){
        cout <<  arr[i] << "\t";
    }
    cout << arr[i] << endl;
}
int main(){
    int num,ele,ele2;
    circular<int> l;
    while(num!=4){
        cout << "1.insert\t2.delete\t3.list\t4.exit" << endl;
        cin >> num;
        switch(num){
            case 1:
                if(l.full()){
                    cout << "circular queue is full" << endl;
                }else{
                    cout << "enter the number to insert" << endl;
                    cin >> ele;
                    l.enqueue(ele);
                }
                break;
            case 2:
                if(l.empty()){
                    cout << "circular queue is empty" << endl;
                }else{
                    cout << "popped out element is " << l.dequeue() << endl;
                }
                break;
            case 3:
                if(l.empty()){
                    cout << "circular queue is empty" << endl;
                }else{
                    l.list();
                }
                break;
            case 4:
                exit(0);
            default:
                cout << "enter valid number" << endl;
                break;
        }
    }
}