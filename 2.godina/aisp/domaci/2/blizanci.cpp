#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int najmanjaRazlika(int n, int m, vector <int64_t> muski, vector <int64_t> zenski){
    
   sort(begin(muski), end(muski));
   sort(begin(zenski), end (zenski));

   int a = 0, b = 0;
   int64_t resenje = INT_MAX;

   while(a < n && b < m){
       if(abs(muski[a]-zenski[b]) < resenje)
            resenje = abs(muski[a] - zenski[b]);

        if(muski[a] < zenski[b])
            a++;
        else
            b++;
   }
   return resenje;
}

int main(){
    
    int n;
    cin >> n;
    vector <int64_t> muski(n);
    for(int i = 0; i<n; i++)
        cin >> muski[i];
    
    int m;
    cin >> m;
    vector <int64_t> zenski(m);
    for(int i = 0; i < m; i++)
        cin >> zenski[i];
   
    cout << najmanjaRazlika(n, m, muski, zenski) << '\n';
        
    return 0;
}
