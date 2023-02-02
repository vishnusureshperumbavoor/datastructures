#include <iostream>
#include <ctype.h>
#include "stack.h"
using namespace std;
void evalpostfix(char postfix[]){
    stack <int> s;
    int val;
    for(int i=0;postfix[i]!='\0';i++){
        char data = postfix[i];
        if(isalnum(data)){
            s.push(data - '0');
        }
        else{
            int x = s.pop();
            int y = s.pop();
            switch(data){
                case '/':
                    val = y/x;
                    break;
                case '*':
                    val = y*x;
                    break;
                case '+':
                    val = y+x;
                    break;
                case '-':
                    val=y-x;
                    break;
            }
            s.push(val);
        }
    }
    cout << "Answer is " << s.pop();
}
int main(){
    char postfix[100];
    cout << "Enter the postfix expression" << endl;
    cin >> postfix;
    evalpostfix(postfix);
}