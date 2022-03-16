#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int akcije(int l, int d, vector<int> &v, int&vmax, int&vmin){
    
    if(l == d){
        vmax = vmin = v[l];
        return 0;
    }
    
    int s = l+ (d-l)/2;
    
    int maxL, minL;
    int resL = akcije(l, s, v, maxL, minL);
    
    int maxD, minD;
    int resD = akcije(s+1, d, v, maxD, minD);
    
    vmax = max(maxL, maxD);
    vmin = min(minL, minD);
    
    return max({resL, resD, maxD-minL});
    
}

int main (){
    
    int n;
    cin >> n;
    
    vector<int> niz(n);
    for(int i = 0; i<n; i++)
        cin >> niz[i];
    
    int vmax, vmin;
    
    cout << akcije(0, n-2, niz, vmax, vmin) << '\n';
    
    return 0;
}
