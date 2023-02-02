#include <iostream>
using namespace std;
template <class T>
class list{
    public :
        int cnt,arr[10],i;
        list();
        T insert(T,T);
        void listDelete(T);
        void show();
        void find(T);
        void findkth(T);
        int isfull();
        int isempty();
};
template <class T>list<T> :: list(){
    cnt = 0;
}
template <class T>int list<T> :: isfull(){
    if(cnt==5)
        return 1;
    else 
        return 0;
}
template <class T>int list<T> :: isempty(){
    if(cnt==0)
        return 1;
    else 
        return 0;
}
template <class T>
T list<T> :: insert(T ele,T pos){
    if(pos>cnt+1){
        cout << "element cannot be inserted" << endl;
    }
    else{
        for(i=cnt-1;i>=pos-1;i--){
            arr[i+1] = arr[i];
        }
        arr[pos-1] = ele;
    }
}
template <class T>
void list<T> :: listDelete(T pos){
    cout << "Deleted element is " << arr[pos-1] << endl;
    for(i=pos;i<cnt;i++){
        arr[i-1] = arr[i];
    }
    cnt--;
}
template <class T>
void list<T> :: show(){
    for(i=0;i<cnt;i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
}
template <class T>
void list<T> :: find(T ele){
    for(i=0;i<cnt;i++){
        if(arr[i]==ele){
            cout << "Element is in position " << i+1 << endl;
            break;
        }
    }
    if(i==cnt){
        cout << "Entered element not found" << endl;
    }
}
template <class T>
void list<T> :: findkth(T ele){
    cout << "Element in position " << ele << " is " << arr[ele-1] << endl;
}
int main(){
    list <int> l;
    int num,ele,pos,fin,po2,po3;
    while(num!=6){
        cout << "1.Insert\n2.Delete\n3.List\n4.Find\n5.Find kth\n6.Exit" << endl;
        cout << "Enter your choice" << endl;
        cin >> num;
        switch(num){
            case 1:
                if(l.isfull()){
                    cout << "list is full" << endl;
                }else{
                    l.cnt++;
                    cout << "Enter the element and position" << endl;
                    cin >> ele >> pos;
                    l.insert(ele,pos);
                }
                break;
            case 2:
                if(l.isempty()){
                    cout << "list is empty" << endl;
                }else{
                    cout << "Enter the position" << endl;
                    cin >> po2;
                    l.listDelete(po2);
                }
                
                break;
            case 3:
                if(l.isempty()){
                    cout << "list is empty" << endl;
                }else{
                    cout << "Elements in the list - " << endl;
                    l.show();
                }
                break;
            case 4:
                if(l.isempty()){
                    cout << "list is empty" << endl;
                }else{
                    cout << "Enter the element to find" << endl;
                    cin >> fin;
                    l.find(fin);
                }
                break;
            case 5:
                if(l.isempty()){
                    cout << "list is empty" << endl;
                }else{
                    cout << "Enter the position" << endl;
                    cin >> po3;
                    l.findkth(po3);   
                }
                break;
            case 6:
                exit(0);
            default:
                cout << "Enter any valid number" << endl;
                break;
                
        }
    }
}