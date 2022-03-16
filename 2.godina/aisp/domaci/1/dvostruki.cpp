#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 50000

using namespace std;

struct student {
    string ime;
    string prezime;
};

bool sortiraj(student a, student b){
    if(a.ime > b.ime)
        return true;
    else if(b.ime > a.ime)
        return false;
    else
        return true;
    
}

int main(){
    vector <student> a(MAX);
    int n = 0;
    student d;
    while(cin >> d.ime >> d.prezime){
        n++;
        a[n].ime = d.ime;
        a[n].prezime = d.prezime;
    }
    
    int m = n+1;
    vector <student> b(m);
    
    for(int i = 0; i<m; i++){
        b[i].ime = a[i].ime;
        b[i].prezime = a[i].prezime;
    }
    
    sort(begin(b), end(b), sortiraj);
    
    for(int i = 1; i<m; i++)
        if( (b[i].ime == b[i-1].ime) && (b[i].prezime == b[i-1].prezime) ){
            cout << b[i].ime << ' ';
            cout << b[i].prezime << '\n';
            break;
        }
        
    
  
    return 0;
}
