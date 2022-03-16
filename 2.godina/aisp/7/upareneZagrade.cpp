#include <iostream>
#include <stack>

using namespace std;

int main(){
        
    string s;
    cin >> s;
    
    stack<char> stack;
    
    for(char c : s){
        
        if(c == '(' || c == '[' || c == '{'){
            stack.push(c);
        }
            
        if(c == ')' || c == ']' || c == '}'){
            if(stack.empty() || 
                (c == ')' && stack.top() != '(') ||
                (c == ']' && stack.top() != '[') ||
                (c == '}' && stack.top() != '{')
            ){
                cout << "ne\n";
                exit(0);
            }
            else{
                stack.pop();
            }
        }
        
    }
    if(stack.empty())
        cout << "da\n";
    return 0;
}
