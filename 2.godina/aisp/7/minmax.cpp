#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    stack <char> operacije;
    stack <char> brojevi;
    
    for(char c: s){
        if(c == 'm' || c == 'M')
            operacije.push(c);
        if(isdigit(c))
            brojevi.push(c);
        if(c == ')'){
            char op = operacije.top();
            operacije.pop();
            
            int operand1 = brojevi.top() - '0';
            brojevi.pop();
            int operand2 = brojevi.top() - '0';
            brojevi.pop();
            
            brojevi.push( op == 'm' ?
            (min(operand1,operand2) + '0') :
            max(operand1, operand2) + '0' );
            
        }
        
    }
    
    cout <<brojevi.top() << '\n'; 
    return 0;
}
