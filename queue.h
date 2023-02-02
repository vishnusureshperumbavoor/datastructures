template <typename T>
class queue{
    public :
    int front,rear,max;
    T arr[100];
    queue();
    void push(T);
    T pop();
    bool empty();
    T frontStack();
    T rearStack();
    void list();
    bool full();
};
template <typename T>
queue<T> :: queue(){
    front = rear = -1;
    max = 3;
}
template <typename T>
void queue<T> :: push(T ele){
    if(front == -1)
        front++;
    rear++;
    arr[rear] = ele;
}
template <typename T>
T queue<T> :: pop(){
    T x = arr[front];
    if(front == rear)
        front = rear = -1;
    else
        front++;
    return x;
}
template <typename T>
bool queue<T> :: empty(){
    if(front == -1)
        return true;
    else
        return false;
}
template <typename T>
bool queue<T> :: full(){
    if(front == 0 && rear == max-1)
        return true;
    else 
        return false;
}
template <typename T>
T queue<T> :: frontStack(){
    return arr[front];
}
template <typename T>
T queue<T> :: rearStack(){
    return arr[rear];
}
template <typename T>
void queue<T> :: list(){
    for(int i=front;i<=rear;i++){
        cout << arr[i] << "\t" ;
    }
    cout << endl;
}