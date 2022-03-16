#include <iostream>
#include <vector>

using namespace std;


int main(){
    
    int n;
    cin >> n;
 
    vector<vector<int> > dp = vector <vector <int>>(n+1, vector<int>(n+1, 0));
    
    dp[0] = vector<int>(n+1, 1);
    for(int i = 1; i<=n; i++)
        for(int maxSabirak = 1; maxSabirak <=n; maxSabirak++){
            int br = 0;
            dp[i][maxSabirak] += dp[i][maxSabirak -1];
            if(maxSabirak <= i)
                br+= dp[i][maxSabirak] += dp[i - maxSabirak][maxSabirak];
            dp[i][maxSabirak] = br;
        }
    
    cout << dp[n][n] << '\n';
    
    return 0;
}
