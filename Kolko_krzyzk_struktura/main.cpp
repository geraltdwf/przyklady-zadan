#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

enum Gracz{GRACZ_X = 0, GRACZ_O};
struct kolko_krzyzk
{

    char mapa[3][3];
    void pobierzRuch(int wiersz, int kolumna, Gracz ktory)
    {
        if(ktory == GRACZ_O)
        {
        mapa[wiersz][kolumna] = 'O';
        }
        else if(ktory == GRACZ_X)
        {
        mapa[wiersz][kolumna] = 'X';
        }
    }
    int sprawdz_miejsce(int wiersz, int kolumna, Gracz ktory);
    void wypelnij_mape();
    void stworz_mape();
    void rozgrywka();
    bool wygrana_dla_O();
    bool wygrana_dla_X();
};
int kolko_krzyzk::sprawdz_miejsce(int wiersz, int kolumna, Gracz ktory)
{
        if(mapa[wiersz][kolumna] != ' ')
        {
            cout << "Zajete miejsce, sprobj jeszcze raz: ";
            cin >> wiersz >> kolumna;
            sprawdz_miejsce(wiersz, kolumna,ktory);

        }
        else
        {
            pobierzRuch(wiersz, kolumna, ktory);
        }
}

bool kolko_krzyzk::wygrana_dla_O()
{
    if((mapa[0][0]  == 'O') && (mapa[0][1]  == 'O') && (mapa[0][2] == 'O'))
    {
        cout << "Gracz_O WIN ";
        return true;
    }
    else if((mapa[0][0]  == 'O') && (mapa[1][0]  == 'O') && (mapa[2][0] == 'O'))
    {
        cout << "Gracz_O WIN ";
        return true;
    }
    else if((mapa[0][0]  == 'O') && (mapa[1][1] == 'O') && (mapa[2][2] == 'O'))
    {
        cout << "Gracz_O WIN ";
        return true;
    }
    else if((mapa[0][2]  == 'O') && (mapa[1][1] == 'O') && (mapa[2][0]== 'O'))
    {
        cout << "Gracz_O WIN ";
        return true;
    }
    else if((mapa[1][0] == 'O') && (mapa[1][1] == 'O') && (mapa[1][2] == 'O'))
    {
        cout << "Gracz_O WIN ";
        return true;
    }
    else if((mapa[2][0]  == 'O') && (mapa[2][1]  == 'O') && (mapa[2][2] == 'O'))
    {
        cout << "Gracz_O WIN ";
        return true;
    }
    else if((mapa[0][1]  == 'O') && (mapa[1][1]  == 'O') && (mapa[2][1] == 'O'))
    {
        cout << "Gracz_O WIN ";
        return true;
    }
    else if((mapa[0][2]  == 'O') && (mapa[1][2]  == 'O') && (mapa[2][2]== 'O'))
    {
        cout << "Gracz_O WIN ";
        return true;
    }
    else
    {
        return false;
    }
}
bool kolko_krzyzk::wygrana_dla_X()
{
    if((mapa[0][0]  == 'X') && (mapa[0][1]  == 'X') && (mapa[0][2] == 'X'))
    {
        cout << "Gracz_X WIN ";
        return true;
    }
    else if((mapa[0][0]  == 'X') && (mapa[1][0]  == 'X') && (mapa[2][0] == 'X'))
    {
        cout << "Gracz_X WIN ";
        return true;
    }
    else if((mapa[0][0]  == 'X') && (mapa[1][1]  == 'X') && (mapa[2][2] == 'X'))
    {
        cout << "Gracz_X WIN ";
        return true;
    }
    else if((mapa[0][2]  == 'X') && (mapa[1][1]  == 'X') && (mapa[2][0] == 'X'))
    {
        cout << "Gracz_X WIN ";
        return true;
    }
    else if((mapa[1][0]  == 'X') && (mapa[1][1]  == 'X') && (mapa[1][2] == 'X'))
    {
        cout << "Gracz_X WIN ";
        return true;
    }
    else if((mapa[2][0]  == 'X') && (mapa[2][1]  == 'X') && (mapa[2][2] == 'X'))
    {
        cout << "Gracz_X WIN ";
        return true;
    }
    else if((mapa[0][1]  == 'X') && (mapa[1][1]  == 'X') && (mapa[2][1] == 'X'))
    {
        cout << "Gracz_X WIN ";
        return true;
    }
    else if((mapa[0][2]  == 'X') && (mapa[1][2]  == 'X') && (mapa[2][2] == 'X'))
    {
        cout << "Gracz_X WIN ";
        return true;
    }
    else
    {
        return false;
    }
}
void kolko_krzyzk::rozgrywka()
{
    int wiersz, kolumna;
    int runda = 0;
    while(runda < 9)
    {

        cout << "GRACZ_X \n" ;
        cin >> wiersz >> kolumna;
        sprawdz_miejsce(wiersz, kolumna, GRACZ_X);
        system("cls");
        stworz_mape();
        if(wygrana_dla_X() == true)
        {
            break;
        }
        runda++;
        GRACZ_O;
        cout << "GRACZ_O \n" ;
        cin >> wiersz >> kolumna;
        sprawdz_miejsce(wiersz, kolumna, GRACZ_O);
        system("cls");
        stworz_mape();
        if(wygrana_dla_O() == true)
        {
            break;
        }
        runda++;
    }
}
void kolko_krzyzk::wypelnij_mape()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3;j++)
        {
            mapa[i][j] = ' ';

        }
    }
}
void kolko_krzyzk::stworz_mape()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << mapa[i][j];
            if(j < 2)
            {
                cout << " | ";
            }

        }
        if(i < 2)
        {
            cout << "\n" << "--+---+--" << "\n";
        }
    }
    cout << endl;
}


int main()
{
    kolko_krzyzk gramy;
    gramy.wypelnij_mape();
    gramy.stworz_mape();
    gramy.rozgrywka();

}
