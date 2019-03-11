#include <iostream>

using namespace std;

int tabliczka(int wiersz, int kolumna)
{
    int **tab = new int *[wiersz];
    for(int i = 0; i < wiersz; i++)
    {
        tab[i] = new int [kolumna];
    for(int j = 0; j < kolumna; j++)
    {
        tab[i][j] = i*j;
        cout << tab[i][j] << " | ";
    }
        cout << endl;
    }
}
void usun(int wiersz, int kolumna)
{
    int **tab = new int *[wiersz];
    for(int i = 0; i < wiersz; i++)
    {
        tab[i] = new int [kolumna];
        for(int j = 0; j < kolumna; j++)
        {
            delete [] tab[i];
        }
        delete [] tab;

    }
    cout << "GOTOWE - Pamiec zostala uwolniona" << endl;
}

int main()
{
    int wiersz, kolumna;
    int wybor;
    while(true)
    {
    cout << "Ilosc wierszy: ";
    cin >> wiersz;
    cout << "Ilosc kolumn: ";
    cin >> kolumna;
    tabliczka(wiersz, kolumna);
    cout << "Czas zwolnic pamiec !";
    usun(wiersz, kolumna);
    cout << "Czy chcesz powtorzyc zabieg ?";
    cin >> wybor;
    if(wybor == 1)
    {
        continue;
    }
    else if(wybor == 2)
    {
        break;
    }
    }


}
