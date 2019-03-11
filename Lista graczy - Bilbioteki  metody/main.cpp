#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

struct lista_graczy
{
    string nick;
    string liga;
    string dywizija;
    int lp;
    int honor_points;

};
lista_graczy aktyw(vector<lista_graczy>&tabela_wynikow, int wielkosc)
{
    cout << "Pobieram najnowsza wersje listy: \n";
    for(int i = 0; i < wielkosc; i++)
    {
        tabela_wynikow[i].lp = rand()%100+1;
        tabela_wynikow[i].honor_points =rand()%10;
    }
}

int main()
{
    int wielkosc;
    cout << "Jakiej wielkosc ranking chcesz utworzyc: ";
    cin >> wielkosc;
    vector<lista_graczy>tabela_wynikow(wielkosc);
    vector<lista_graczy>::iterator itr = tabela_wynikow.begin();
    vector<lista_graczy>::iterator koniec = tabela_wynikow.end();
    srand(time(NULL));
    for(int i = 0; i < wielkosc; i++)
    {
        cout << "Podaj nick: ";
        cin >> tabela_wynikow[i].nick;
        cout << "Podaj lige: ";
        cin >> tabela_wynikow[i].liga;
        cout << "Podaj dywizje: ";
        cin >> tabela_wynikow[i].dywizija;
        tabela_wynikow[i].lp = rand()%100+1;
        cout << "Ilosc LP: " << tabela_wynikow[i].lp << " ";
        tabela_wynikow[i].honor_points =rand()%10;
        cout << "Punkt honoru: " << tabela_wynikow[i].honor_points;
        cout << endl;

    }
    for(int i = 0; i < wielkosc; i++)
    {
        cout << tabela_wynikow[i].nick << ", ";
        cout << "LIGA: " << tabela_wynikow[i].liga<< ", ";
        cout << "DYWIZJA: "<< tabela_wynikow[i].dywizija<< ", ";
        cout << "LP: "<<tabela_wynikow[i].lp<< ", ";
        cout << "PUNKTY HONORU: "<<tabela_wynikow[i].honor_points << endl;
    }
    aktyw(tabela_wynikow, wielkosc);
        for(int i = 0; i < wielkosc; i++)
    {
        cout << tabela_wynikow[i].nick << ", ";
        cout << "LIGA: " << tabela_wynikow[i].liga<< ", ";
        cout << "DYWIZJA: "<< tabela_wynikow[i].dywizija<< ", ";
        cout << "LP: "<<tabela_wynikow[i].lp<< ", ";
        cout << "PUNKTY HONORU: "<<tabela_wynikow[i].honor_points << endl;
    }
    /*for(itr, koniec; itr!=koniec; ++itr)
    {

    }
    */


}

