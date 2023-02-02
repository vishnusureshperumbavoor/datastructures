#include <iostream> 
using namespace std;
template <class T>
class graph{
    T gra[5][5],i,j,k;
    int nodes,efrom,eto,weight,edges;
    public :
        void readgraph();
        void displaygraph();
        void warshall();
};
template <typename T>void graph<T> :: readgraph(){
    cout << "Enter the number of nodes" << endl;
    cin >> nodes;
    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
            if(i==j){
                gra[i][j]=0;
            }
            else{
                gra[i][j]=999;
            }
        }
    }
    cout << "Enter the number of edges" << endl;
    cin >> edges;
    cout << "Enter the edges\n";
    for(i=0;i<edges;i++){
        cin >> efrom >> eto >> weight;
        gra[efrom][eto]= weight;
    }
}
template <typename T>void graph<T> :: displaygraph(){
    cout << "Entered Matrix" << endl;
    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
            cout << gra[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
template <typename T>void graph<T> :: warshall(){
    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
            for(k=0;k<nodes;k++){
                if(gra[j][k]>gra[j][i]+gra[i][k]){
                    gra[j][k]=gra[j][i]+gra[i][k];
                }
            }
        }
    }
    cout << "Shortest path" << endl;
    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
            cout << gra[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    exit(0);
}
int main(){
    int num;
    graph<int>g;
    while(num!=4){
        cout << " 1. Read Matrix\n2. Display Matrix\n3. Shortest Path\n4. Exit\n" ;
        cout << "Enter the choice" << endl;
        cin >>  num;
        switch(num){
            case 1:
                g.readgraph();
                break;
            case 2:
                g.displaygraph();
                break;
            case 3:
                g.warshall();
                break;
        }
    }
    
}