#include <iostream>
#include <vector>

using namespace std;

vector <vector<int>> memo;

int brParticija(int n, int maxS){
    
    if(memo[n][maxS] != -1)
        return memo[n][maxS];
    if(n==0)
        return memo[n][maxS] = 1;
    
    int br = 0;
    
    if(maxS > 1)
        br+= brParticija(n, maxS - 1);
    if(maxS <= n)
        br+= brParticija(n - maxS, maxS);
    
    return memo[n][maxS] = br;
    
}

using namespace std;

int main(){
    
    int n;
    cin >> n;
 
    memo = vector<vector<int>> (n+1, vector<int>(n+1, -1) );//-1 jer, tamo gde je -1, vr za te parametre se jos uvek nisu sracunali
    
    
    
    
    cout << brParticija(n, n) << '\n';
    
    return 0;
}
