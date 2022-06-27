#include <iostream>
#include <vector>

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

void zameni(Tacka a1, Tacka a2){

    Tacka tmp = a1;
    a1 = a2;
    a2 = tmp;

}

int orijentacija(Tacka p, Tacka q, Tacka r){

    int vrednost = (q.get_y() - p.get_y()) * (r.get_x() - q.get_x()) - (q.get_x() - p.get_x()) * (r.get_y() - q.get_y());

    if(vrednost == 0)
        return 0;

    if(vrednost > 0)
        return 1;
    else
        return 2;

}

int razdaljina(Tacka &a1, Tacka &a2{

    return (a1.get_x() - a2.get_x()) * (a1.get_x() - a2.get_x()) +
            (a1.get_y() - a2.get_y()) * (a1.get_y() - a2.get_y())


}

bool uporedi(Tacka a1, Tacka a2){

    int orijent = orijentacija(a0, a1, a2);

    if(orijent == 2)
        return true;
    if(orijent == 1)
        return false;

    return razdaljina(a1, a0) < razdaljina(a2, a0);

}

int nadji_ekstremnu(vector<Tacka> tacke){

    int max_x = tacke[0].get_x();
    int min_y = tacke[0].get_y();

    int index = 0;

    int n = tacke.size();

    for(int i = 0; i<n; i++){

        if(tacke[i].get_x() > max_x){
            max_x = tacke[i].get_x();
            min_y = tacke[i].get_y();
            index = i;
        }else if(tacke[i].get_x() == max_x){
            if(tacke[i].get_y() < min_y){
                min_y = tacke[i].get_y();
                index = i;
            }
        }

    }
    return index;
}

void Graham(vector<Tacka>&tacke){

    int ekstremna = nadji_ekstremnu(tacke);

    zameni(tacke[0], tacke[ekstremna]);
    a0 = tacke[0];

    sort(tacke.begin() + 1, tacke.end(), uporedi);

    vector<Tacka>rezultat;

    rezultat.push_back(tacke[0]);
    rezultat.push_back(tacke[1]);

    int n = tacke.size();

    int k = 1;

    for(int i = 2; i<n; i++){

        while(rezultat.size() >= 2 && orijentacija(rezultat[k-1], rezultat[k], rezultat[i]) != 2){
            rezultat.pop_back();
            k--;
        }

        k++;
        rezultat.push_back(tacke[k]);
    }

    for(Tacka &p : tacke)
        cout << p.get_x() << " " << p.get_y() << '\n';

}

int main(){

    return 0;
}
