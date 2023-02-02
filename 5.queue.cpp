#include<iostream>
using namespace std;
template <class T> 
class queue{
    public :
    T rear,front,max,arr[10];
    queue();
    void insert(T);
    void qudelete();
    void display();
    int isEmpty();
    int isFull();
};
template <class T>
int queue <T> :: isEmpty(){
    if(front == -1)
        return 1;
    else
        return 0;
    
}
template <class T>
int queue<T> :: isFull(){
    if(rear==max-1)
        return 1;
    else
        return 0;
}
template <class T>
queue <T> :: queue(){
    front = -1;
    rear = -1;
    max = 3;
}
template <class T>
void queue <T> :: insert(T ele){
    if(front == -1)
        front ++;
    rear++;
    arr[rear] = ele;
} 
template <class T>
void queue <T> :: display(){
    for(int i=front;i<=rear;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
template <class T>
void queue<T> :: qudelete(){
    cout << "Deleted element is " << arr[front] << endl;
    front++;
    if(front>rear){
        front = rear = -1;
    }
}
int main(){
    queue <int> q;
    int ch,ele;
    while(ch!=4){
        cout << "1.Insert\n2.Delete\n3.List\n4.Exit" << endl;
        cout << "Enter the choice" << endl;
        cin >> ch;
        switch(ch){
            case 1:
                if(q.isFull()){
                    cout << "Queue is full" << endl;
                }else{
                    cout << "Enter the element to insert" << endl;
                    cin >> ele;
                    q.insert(ele);
                }
                break;
        
            case 2:
                if(q.isEmpty()){
                    cout << "Queue is empty" << endl;
                }else{
                    q.qudelete();
                }
                break;
        
            case 3:
                cout << "Elements in the queue" << endl;
                q.display();
                break;
            
        }
    }
}