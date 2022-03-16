#include <iostream>

using namespace std;

int f (string n){
    int brCifara = n.size();
    
    if(brCifara == 0)
        return 1;
    
    string devetke = string(brCifara-1, '9');
    string ostatak = n.substr(1);
    
    int c = n[0] - '0';
    if(c < 3)
        return c*f(devetke) + f(ostatak);
    else if(c==3)
        return c*f(devetke);
    else
        return (c-1) * f(devetke) + f(ostatak);
}

int main(){
    
    string n;
    cin >> n;
    
    cout << f(n) << '\n';
    
    return 0;
}
