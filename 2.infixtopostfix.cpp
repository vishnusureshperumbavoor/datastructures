#include <iostream>
#include <ctype.h>
#include "stack.h"
#include "icpisp.h"
using namespace std;
void infixpeekostfix(string infix){
    stack <char> s;
    s.push('(');
    char data;
    cout << "Postfix expression" << endl;
    for(int i=0;infix[i]!='\0';i++){
        data = infix[i];
        if(isalnum(data)){
            // isalnum = is alnum = alnum = alphabet or number
            // isalpha = is alpha = alphabet
            // isdigit = is digit = digit 
            cout << data ;
        }
        else if(data == ')'){
            while(s.peek() != '('){
                cout << s.pop();
            }
            s.pop();
        }
        else if(icp(data) > isp(s.peek())){
            s.push(data);
        }
        else if(icp(data) < isp(s.peek())){
            while(icp(data) < isp(s.peek())){
                cout << s.pop();
            }
            s.push(data);
        }
    }
    while(s.peek()!='('){
        cout << s.pop();
    }
    s.pop();
}
int main(){
    string infix;
    cout << "enter an infix operation" << endl;
    cin >> infix;
    infixpeekostfix(infix);
}