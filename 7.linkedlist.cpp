#include <iostream>
using namespace std;
template <typename T>
class linkedlist{
    int size;
    class node{
        friend class linkedlist;
        T data;
        node *link;
        public:
        node(T _data, node *_link = NULL){
            data = _data;
            link = _link;
        }
    }*head,*tail;
    public:
        linkedlist();                                   
        void addhead(T);
        void addtail(T);
        void removeHead();
        void removeTail();
        void addNode(T,T);
        void removeNode(T);
        void find(T);
        void findkth(T);
        void list();
};
template <class T>linkedlist<T> :: linkedlist(){
    size=0;
    head= NULL;
    tail=NULL;
}
template <class T>void linkedlist<T> :: addhead(T data){
    head = new node(data,head);
    if(tail==NULL)
        tail = head;
    size++;
}
template <class T>void linkedlist<T> :: addtail(T data){
    // cout << data << endl;
    if(tail==NULL)
        addhead(data);
    else{
        node *temp = tail;
        tail = new node(data);
        temp->link = tail;
    }
    size++;
}
template <class T>void linkedlist<T> :: removeHead(){
    node *temp = head;
    head = head->link;
    delete temp;
    size--;
}
template <class T>void linkedlist<T> :: removeTail(){
    node *temp = head;  
    while(temp->link->link!=NULL){
        temp = temp->link;
    }
    node *temp2 = tail;
    temp->link = NULL;
    tail = temp;
    delete temp2;
    size--;
}
template <class T>void linkedlist<T> :: addNode(T data, T pos){
    if(pos==1){
        addhead(data);
    }
    else if(pos==size+1){
        addtail(data);
    }
    else{
        node *temp = head;
        node *temp2 = new node(data);
        while(pos!=2){
        temp = temp->link;
        pos--;
        }
        temp2->link = temp->link;
        temp->link = temp2;
        size++;
    }
}
template <class T>void linkedlist<T> :: removeNode(T pos){
    if(pos==1){
        removeHead();
    }
    else if(pos==size){
        removeTail();
    }
    else{
        node *temp = head;
        while(pos!=2){
        temp = temp->link;
        pos--;
        }
        node *temp2 = temp->link;
        temp->link = temp2->link;
        delete temp2;
        size--;
    }
}
template <class T>void linkedlist<T> :: find(T data){
    node *temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        if(temp->data==data){
            cout << "entered data found at node " << count << endl;
            break;
        }
        temp = temp->link;
    }
    if(temp==NULL){
        cout << "entered data not found" << endl;
    }
}
template <class T>void linkedlist<T> :: findkth(T pos){
    node *temp = head;
    while(pos!=1){
        temp=temp->link;
        pos--;
    }
    cout << "data at node  " << pos << " = " << temp->data << endl; 
}
template <class T>void linkedlist<T> :: list(){
    node *temp = head;
    while(temp!=NULL){
        cout << temp->data << "\t";
        temp = temp->link;
    }
    cout << endl;
    exit(0);
}
int main(){
    int num,head,tail,data,pos;
    linkedlist<int> l;
    while(num!=10){
        // cout << "1.Add Head\n2.Add Tail\n3.Remove Head\n4.Remove Tail\n5.Add a node\n6.Remove a node\n7.Find\n8.Find kth\n9.List\n10.Exit" << endl;
        cin >> num;
        switch(num){
            case 1:
                cin >> head;
                l.addhead(head);
                break;
            case 2:
                cin >> tail;
                l.addtail(tail);
                break;
             case 3:
                l.removeHead();
                break;
            case 4:
                l.removeTail();
                break;
            case 5:
                cin >> data >> pos;
                l.addNode(data,pos);
                break;
            case 6:
                cin >> pos;
                l.removeNode(pos);
                break;
            case 7:
                cin >> data;
                l.find(data);
                break;
            case 8:
                cin >> pos;
                l.findkth(pos);
                break;
            case 9:
                l.list();
                break;
            case 10:
                exit(0);
        }
    }
}