#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector <int> niz (n);
    
    for(int i = 0; i<n; i++)
        cin >> niz[i];
    
    int a,b;
    cin >> a >> b;
    
    int l = 0;
    int i = 0;
    int d  = n-1;
    
    while(i<d){
        if(niz[i] < a)
            swap(niz[i++], niz[l++]);
        else if(niz[i] <= b)
            i++;
        else
            swap(niz[i], niz[--d]);
    }
    for(int i = 0; i<n; i++)
        cout << niz[i] << ' ';
return 0;
}
