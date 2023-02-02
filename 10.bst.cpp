#include <iostream>
using namespace std;
template <class T>
class BST{
    class treenode{
        friend class BST;
        int data;
        treenode *left,*right;
        treenode(T d,treenode *l= NULL,treenode *r=NULL){
            data = d;
            left = l;
            right = r;
        }
    }*root;
    public :
    BST();
    void insert(T);
    void delbst(treenode *,T);
    void del(T);
    void preorder();
    void postorder();
    void inorder(treenode *);
    void inord();
    void preorder(treenode *);
    void preord();
    void postorder(treenode *);
    void postord();
    int find(T);
    T findmin(treenode *);
};
template <typename T>
BST<T> :: BST(){
    root= NULL;
}
template <typename T>
void BST<T> :: insert(T value){
    if(root==NULL)
        root = new treenode(value);
    else{
        treenode *p = root, *q;
        while(p!=NULL){
            q=p;
            if(value < p->data)
                p = p->left;
            else
                p = p->right;
        }
        if(value< q->data)
            q->left = new treenode(value);
        else
            q->right = new treenode(value);
        }
}
template <typename T>
int BST<T> :: find(T value){
    treenode *p = root;
    while(p!=NULL){
        if(p->data==value)
            break;
        else if(value < p->data)
            p = p->left;
        else
            p = p->right;
    }
    if(p)
        return 1;
    else
        return 0;
}
template <typename T>
void BST<T> :: del(T value){
    if(find(value))
        delbst(root,value);
    else
        cout << "entered value doesnt exist" << endl;
}
template <typename T>
void BST<T> :: delbst(treenode *temp,T value){
    treenode *q;
    while(temp->data!=value){
    q=temp;
    if(value<temp->data)
        temp=temp->left;
    else
        temp=temp->right;
    }
    
    if(temp->left == NULL && temp->right == NULL){
        if(temp==root){
            delete root;
            root = NULL;
        }
        else{
            if(temp->data < q->data)
                q->left = NULL;
            else
                q->right = NULL;
            delete temp;
        }
    }
    else if(temp->left!=NULL && temp->right == NULL){
        if(temp==root){
            root = temp->left;
            delete temp;
        }
        else{
            if(temp->data<q->data)
                q->left=temp->left;
            else
                q->right=temp->left;
            delete temp;
        }
    }
    else if(temp->left==NULL && temp->right != NULL){
        if(temp==root){
            root = temp->right;
            delete temp;
        }
        else{
            if(temp->data<q->data)
                q->left=temp->right;
            else
                q->right=temp->right;
            delete temp;
        }
    }
    else{
        T temp2 = findmin(temp->right);
        delbst(temp,temp2);
        temp->data = temp2;
    }
}
template <typename T>
T BST<T> :: findmin(treenode *temp){
    if(temp == NULL){
        cout << "error";
        return 0;
    }
    while(temp->left!=NULL)
        temp = temp->left;
    return temp->data;
}
template <typename T>
void BST<T> :: inord(){
    if(root==NULL)
        cout << "BST is empty" << endl;
    else
        inorder(root);
}
template <typename T>
void BST<T> :: inorder(treenode *temp){
    if(temp){
        inorder(temp->left);
        cout << temp->data << "\t";
        inorder(temp->right);
    }
}
template <typename T>
void BST<T> :: preord(){
    if(root==NULL)
        cout << "BST is empty" << endl;
    else
        preorder(root);
}
template <typename T>
void BST<T> :: preorder(treenode *temp){
    if(temp){
        cout << temp->data << "\t";
        preorder(temp->left);
        preorder(temp->right);
    }
}
template <typename T>
void BST<T> :: postord(){
    if(root==NULL)
        cout << "BST is empty" << endl;
    else
        postorder(root);
}
template <typename T>
void BST<T> :: postorder(treenode *temp){
    if(temp){
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << "\t";
    }
}
int main(){
    BST<int> b ;
    int num, data;
    while(num!=6){
        cout << "1.insert\t2.delete\t3.preorder\t4.postorder\t5.inorder\t6.exit" << endl;
        cin >> num;
        switch(num){
            case 1:
                cout << "enter number to insert" << endl;
                cin >> data;
                b.insert(data);
                break;
            case 2:
                cout << "enter the data to delete" << endl;
                cin >> data;
                b.del(data);
                break;
            case 3:
                b.preord();
                break;
            case 4:
                b.postord();
                break;
            case 5:
                b.inord();
                break;
        }
    }
    
}