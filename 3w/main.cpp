#include <iostream>

using namespace std;


void tablica_trzeci_wymiar(int ***&tablica, int dlugosc, int szero, int wysokosc)
{
    tablica = new int**[dlugosc];
    for(int i = 0; i < dlugosc; i++)
    {
        tablica[i] = new int*[szero];
        for(int j = 0; j < szero; j++)
        {
            tablica[i][j] = new int[wysokosc];
        }
    }
    for(int i = 0; i < dlugosc; i++)
    {
        for(int j = 0; j < szero; j++)
        {
            for(int k = 0; k < wysokosc; k++)
            {
                tablica[i][j][k] = i*j*k;
            }

        }
    }



}
void wyswietl(int ***tablica, int dlugosc, int szero, int wysokosc)
{
     for(int i = 0; i < dlugosc; i++)
    {
        for(int j = 0; j < szero; j++)
        {
            for(int k = 0; k < wysokosc; k++)
            {
                tablica[i][j][k] = i*j*k;
                cout << tablica[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
void usun_tablice(int ***&tablica, int dlugosc, int szero, int wysoksc)
{
    for(int i = 0; i < dlugosc; i++)
    {
        for(int j = 0; j < szero; j++)
        {
            delete[] tablica[i][j];
        }
        delete[] tablica[i];
    }
    delete[] tablica;
}


int main()
{
    int wybor;
   int dlugosc;
   int szero;
   int wysokosc;
   int ***tablica;
   cout << "Podaj wielkosc tablicy - TRZY WYMIARY: ";
   cin >> dlugosc >> szero >> wysokosc;
   tablica_trzeci_wymiar(tablica, dlugosc, szero, wysokosc);
   cout << "obliczenia - wybierz: ";
   while(true)
   {
    cout << "[1] pokaz tablice. [2] usun tablice ";
    cin >> wybor;
   if(wybor == 1)
   {
       wyswietl(tablica, dlugosc, szero, wysokosc);
   }
   else if (wybor == 2)
   {
        usun_tablice(tablica, dlugosc, szero, wysokosc);
        if(tablica = NULL);
        {
            cout << "Tablica zostala usunieta";
        }
   }
   else
   {
       continue;
   }
   };

}
