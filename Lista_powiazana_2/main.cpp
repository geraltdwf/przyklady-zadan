#include <iostream>

using namespace std;

struct czlowiek
{
    string imie;
    string nazwisko;
    int wiek;
    czlowiek* nowy_osobnik;

};
czlowiek* lista_ludzi = NULL;
czlowiek* biezacy_element = lista_ludzi;

czlowiek* nowy_ludzik()
{
    czlowiek* osoba = new czlowiek;
    cout << "Podaj imie: ";
    cin >> osoba->imie;
    cout << "Podaj nazwisko: ";
    cin >> osoba->nazwisko;
    cout << "Podaj wiek: ";
    cin >> osoba->wiek;
    osoba->nowy_osobnik = lista_ludzi;
    lista_ludzi = osoba;
    return osoba;
}
void wyswietl(czlowiek* biezacy_element)
{
    cout << biezacy_element->imie<< ", ";
    cout << biezacy_element->nazwisko<< ", ";
    cout << biezacy_element->wiek << "\n";
    cout << "------------------\n";
}
void drukuj_liste()
{
    czlowiek* biezacy_element = lista_ludzi;
    while(biezacy_element != NULL)
    {
        wyswietl(biezacy_element);
        biezacy_element = biezacy_element->nowy_osobnik;
    }
}

int main()
{
    int i = 0;
  while(i < 2)
  {
      nowy_ludzik();
      i++;
  }
  drukuj_liste();


}
