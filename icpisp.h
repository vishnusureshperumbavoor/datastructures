int icp(char ele){
    switch(ele){
        case '(':
            return 9;
            break;
        case '^':
            return 6;
            break;
        case '*':
        case '/':
            return 3;
            break;
        case '+':
        case '-':
            return 1;
            break;
    }
}
int isp(char ele){
    switch(ele){
        case '(':
            return 0;
            break;
        case '^':
            return 5;
            break;
        case '*':
        case '/':
            return 4;
            break;
        case '+':
        case '-':
            return 2;
            break;
    }
}