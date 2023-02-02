#include <iostream>
#include "stack.h"
#include "queue.h"
using namespace std;

template <class T>class graph{
    int nodes,i,j,eno,efrom,eto,weight;
    bool visited[5];
    T arr[5][5];
    public :
        void readgraph();
        void adjacencymatrix();
        void bfs();
        void dfs();
};
template <typename T>void graph<T>::readgraph(){
    cout << "Enter the number of nodes" << endl;
    cin >> nodes;
    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
            arr[i][j]=0;
        }
    }
    cout << "Enter the number of edges" << endl; 
    cin >> eno;
    cout << "Enter the edges" << endl; 
    for(i=0;i<eno;i++){
        cin >> efrom >> eto;
        arr[efrom][eto] = arr[eto][efrom] = 1;
    }
}
template <typename T>void graph<T>::adjacencymatrix(){
    cout << "Adjacency Matrix\n";
    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
template <typename T>void graph<T>::dfs(){
    cout << "DFS\n";
    T temp;
    stack<int> s;
    for(i=0;i<nodes;i++){
        visited[i]=false;
    }
    s.push(0);
    visited[0]=true;
    while(!s.isEmpty()){
        temp = s.pop();
        cout << temp << "\t";
        for(i=0;i<nodes;i++){
            if(arr[temp][i]==1){
                if(visited[i]==false){
                    s.push(i);
                    visited[i]=true;
                }
            }
        }
    }
    cout << endl;
}
template <typename T>void graph<T>::bfs(){
    cout << "BFS\n";
    T temp;
    QueueADT<int>q;
    for(i=0;i<nodes;i++){
        visited[i]=false;
    }
    q.Insert(0);
    visited[0]=true;
    while(!q.isEmpty()){
        temp=q.Delete();
        cout << temp << "\t";
        for(i=0;i<nodes;i++){
            if(arr[temp][i]==1){
                if(visited[i]==false){
                    q.Insert(i);
                    visited[i]=true;
                }
            }
        }
    }
    cout << endl;
    exit(0);
}
int main(){
    int num;
    graph <int> g;
    while(num!=5){
        cout << "1. Read Matrix\n2. Display Matrix\n3. DFS\n4. BFS\n5. Exit\n";
        cout << "Enter the choice\n";
        cin >> num;
        switch(num){
            case 1:
                g.readgraph();
                break;
            case 2:
                g.adjacencymatrix();
                break;
            case 3:
                g.dfs();
                break;
            case 4:
                g.bfs();
                break;
        }
    }
    
}