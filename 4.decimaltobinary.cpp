#include <iostream>
#include "stack.h"
using namespace std;
void dectobin(int dec){
    stack <int> s;
    while(dec!=0){
        s.push(dec%2);
        dec /= 2;
    }
    while(!s.isEmpty()){
       cout << s.pop();
    }
}
int main(){
    int dec;
    cout << "enter the decimal number" << endl;
    cin >> dec;
    dectobin(dec);
}