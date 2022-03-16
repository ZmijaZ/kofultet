#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

void napravi_stablo(vector<int>&niz, vector<int>&stablo, int x, int y, int i){
    
    if(x == y){
        niz[x] = stablo[i];
        return;
    }
    
    int s = (x+y)/2;
    

    napravi_stablo(niz, stablo, x, s, 2*i);
    napravi_stablo(niz, stablo, s+1, y, 2*i+1);
    
    stablo[i] = max(stablo[2*i], stablo[2*i+1]);
}

int max_element(vector<int>&stablo, int x, int y, int a, int b, int i){
    
    if(x > b || y < a)
        return INT_MIN;
    
    if(x >= a && y <=b)
        return stablo[i];
    
    int s = (x+y)/2;
    
    return max(max_element(stablo, x, s, a, b, 2*i), max_element(stablo, s+1, y, a, b, 2*i+1));
}

int main(){
    
    int n;
    cin >> n;
    vector<int>niz(n);
    
    for(int i = 0; i<n; i++)
        cin >> niz[i];
    
    int visina = ceil(log2(n));
    int velicina = 2*pow(2, visina);
    
    vector<int>stablo(velicina);
    
    napravi_stablo(niz, stablo, 0, n-1, 1);
    
    int a, b;
    cin >> a >> b;
    
    cout << max_element(stablo, 0, n-1, a, b, 1) << '\n';
    
    return 0;
}
