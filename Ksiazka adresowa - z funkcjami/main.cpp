#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct ksiazka_adresowa
{
    int id;
    string nazwa_email;
};

void rozmiar_mapy(map<int, string>email_adresy)
{
    cout << email_adresy.size() << "\n";
}
void zniszcz(map<int, string>&email_adresy)
{
    cout << endl;
    email_adresy.clear();
}
void zniszcz_element(map<int, string>&email_adresy, int liczba)
{
    cout << "Element nr: " << liczba << " zostal zniszczony \n";
    email_adresy.erase(liczba);
}
int dodaj(map<int, string>&email_adresy)
{
    int id;
    string adres;
    cout << "Podaj ID: ";
    cin >> id;
    cout << "Podaj adres email: ";
    cin >> adres;
    email_adresy.insert({id, adres});
}
void zmien(map<int, string>&email_adresy, map<int, string>::iterator koniec, int pozycja)
{
    map<int, string>::iterator wyszukane;
    int id;
    string adres;
    wyszukane = email_adresy.find(pozycja);
    if(wyszukane != koniec)
    {
        cout << "Podaj  adres: ";
        cin >> adres;
        cout << wyszukane->second;
        wyszukane->second = adres;
    }
}
void znajdz(map<int, string>email_adresy, map<int, string>::iterator koniec, map<int,string>::iterator itr, int id)
{
    map<int, string>::iterator wyszukane;
    wyszukane = email_adresy.find(id);
    if(wyszukane != koniec)
    {
        cout << wyszukane->second;
    }

}
void wyswietl_liste(map<int, string>email_adresy)
{
    map<int, string>::iterator itr = email_adresy.begin();
    map<int, string>::iterator koniec = email_adresy.end();
    for(itr,koniec; itr != koniec; ++itr )
    {
        cout << itr->first << "--->" << itr->second << "\n";
    }
}

int main()
{
    int wybor, liczba, pozycja,id;
    map<int, string>email_adresy;
    map<int, string>::iterator itr = email_adresy.begin();
    map<int, string>::iterator koniec = email_adresy.end();
    cout << "MAPA \n";
    cout << "----------------------------- \n";
    cout << "[1] Rozmiar mapy \n";
    cout << "[2] Zniszcz mape \n";
    cout << "[3] Zniszcz element \n";
    cout << "[4] Dodaj element \n";
    cout << "[5] Wyswietl liste \n";
    cout << "[6] Zamien element \n";
    cout << "[7] Znajdz element \n";
    cout << "----------------------------- \n";
    while(true)
    {
        cin >> wybor;
        switch(wybor)
        {
        case 1:
            rozmiar_mapy(email_adresy);
            break;
        case 2:
            zniszcz(email_adresy);
            break;
        case 3:
            cout << "Podaj element: ";
            cin >> liczba;
            zniszcz_element(email_adresy, liczba);
            break;
        case 4:
            dodaj(email_adresy);
            break;
        case 5:
            wyswietl_liste(email_adresy);
            break;
        case 6:
            cout << "Ktory elemen chcesz zmienc: ";
            cin >> pozycja;
            zmien(email_adresy,koniec, pozycja);
            break;
        case 7:
            cout << "Ktory elemen chcesz znalezc, podaj ID: ";
            cin >> id;
            znajdz(email_adresy, koniec,itr, id);
            break;
        default:
            cout << "error";
            break;
        }

    }
}
