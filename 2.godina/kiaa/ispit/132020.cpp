#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Tacka{

public:

    Tacka(){}
    Tacka(int _x, int _y){

        x = _x;
        y = _y;

    }

    int get_x() const {return x;}
    int get_y() const {return y;}

private:

    int x;
    int y;

};

Tacka a0;

void zameni(Tacka &a1, Tacka &a2){

    Tacka tmp = a1;
    a1 = a2;
    a2 = tmp;

}

int orijentacija(Tacka p, Tacka q, Tacka r){

    int vrednost =  (q.get_y() - p.get_y()) * (r.get_x() - q.get_x()) -
            (q.get_x() - p.get_x()) * (r.get_y() - q.get_y());

    if(vrednost == 0)
        return 0;

    return (vrednost > 0) ? 1 : 2;

}

int razdaljina(Tacka a1, Tacka a2){

    return (a1.get_x() - a2.get_x()) * (a1.get_x() - a2.get_x()) +
        (a1.get_y() - a2.get_y()) * (a1.get_y() - a2.get_y());

}

bool uporedi(Tacka &a1, Tacka &a2){

    int orijent = orijentacija(a0, a1, a2);

    if(orijent == 2)
        return true;

    else if(orijent == 1)
        return false;

    return razdaljina(a0, a1) < razdaljina(a0, a2);

}

void Graham(vector<Tacka> &tacke){

    Tacka pocetak(0, 0);

    tacke.push_back(pocetak);

    zameni(tacke[tacke.size()-1], tacke[0]);

    a0 = tacke[0];

    sort(tacke.begin() + 1, tacke.end(), uporedi);

    int n = tacke.size();

    for(int i = 1; i<n; i++){

        cout << tacke[i].get_x() << " " << tacke[i].get_y() << '\n';

    }

}

int main(){

    int n;
    cin >> n;

    vector<Tacka>tacke;


    for(int i = 0; i<n; i++){

        int x, y;
        cin >> x >> y;

        Tacka tmp(x, y);
        tacke.push_back(tmp);
    }

    Graham(tacke);

    return 0;
}
