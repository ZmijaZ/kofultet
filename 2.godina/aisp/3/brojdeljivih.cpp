#include <iostream>

using namespace std;

int main(){
    int a;
    int b;
    int k;
    
    cin >> a;
    cin >> b;
    cin >> k;
    
    int deljiviDoB = b/k+1;
    int deljiviDoA = (a-1)/k +1;
    
    if(a>0)
        cout << deljiviDoB-deljiviDoA<< '\n';
    else
        cout << deljiviDoB<<'\n';
    
return 0;
}
