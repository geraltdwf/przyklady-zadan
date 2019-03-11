#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


struct firma
{
    string produkt;
    int cena;
    string rodzaj_podatku;
    float podatek;
    firma* kolejny_produkt;
};

firma* lista_produktow = NULL;
firma* dodaj_produkt()
{
    firma* nowy_produkt = new firma;
    cout << "Podaj produkt: ";
    cin >>  nowy_produkt->produkt;
    nowy_produkt->cena = rand()%50+1;
    cout << "Rodzaj podatku: ";
    cin >> nowy_produkt->rodzaj_podatku;
    nowy_produkt->podatek = rand()% 23+1;
    nowy_produkt->kolejny_produkt = lista_produktow;
    lista_produktow = nowy_produkt;
    return nowy_produkt;

}
firma* biezacy = lista_produktow;

void wyswietlanie_listy_produktow(firma *biezacy)
{
    biezacy = lista_produktow;

    while(biezacy != NULL)
    {
        cout << "Produkt " << biezacy->produkt << ", ";
        cout << "Cena " << biezacy->cena << " PLN, ";
        cout << "Rodzaj " << biezacy->rodzaj_podatku << ", ";
        cout << "podatek 0," << biezacy->podatek << " % \n";
        biezacy = biezacy->kolejny_produkt;
    }
}
void usun(int liczba, firma *biezacy)
{
    biezacy = lista_produktow;
    if(liczba == 1)
    {
        lista_produktow = biezacy->kolejny_produkt;
    }
    else if(liczba >= 2)
    {
        int j = 1;
        while(biezacy != NULL)
        {
        if((j+1)==liczba)
        {
            break;



        }

        biezacy = biezacy->kolejny_produkt;
        j++;
        }
    }
}




int main()
{
    int wybor;
    int liczba;
    while(true)
    {
    cout << "[1] Produkt: \n";
    cout << "[2] Lista: \n";
    cout << "[3] USUN: \n";
    cin >> wybor;
    srand(time(NULL));
    switch(wybor)
    {
        case 1:
        dodaj_produkt();
        break;
        case 2:
        wyswietlanie_listy_produktow(biezacy);
        break;
        case 3:
        cin >> liczba;
        usun(liczba, biezacy);
        break;
        default:
            cout << "ERROR \n";

    }
}
}
