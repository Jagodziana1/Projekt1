#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;


void rysujPlansze(char plansza[5][5], int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == x && j == y)
            {
                cout << "[@]";
            }
            else
            {
                cout << "[" << plansza[i][j] << "]";
            }
        }
        cout << endl;
    }
}


void losujLitery(char plansza[5][5], string slowo)
{
    char litery[26] =
    {
        'a','b','c','d','e','f','g','h','i','j','k','l','m',
        'n','o','p','q','r','s','t','u','v','w','x','y','z'
    };

    int liczbaLiter = 8;

    int x;
    int y;


  char potrzebnaLitera = slowo[rand() % slowo.length()];


    do
    {
        x = rand() % 5;
        y = rand() % 5;
    }
    while (plansza[x][y] != ' ');

    plansza[x][y] = potrzebnaLitera;



    for (int i = 1; i < liczbaLiter; i++)
    {
        do
        {
            x = rand() % 5;
            y = rand() % 5;
        }
        while (plansza[x][y] != ' ');

        plansza[x][y] = litery[rand() % 26];
    }
}

void dodajNowaLitere(char plansza[5][5])
{
    char litery[26] =
    {
        'a','b','c','d','e','f','g','h','i','j','k','l','m',
        'n','o','p','q','r','s','t','u','v','w','x','y','z'
    };

    int x;
    int y;

    do
    {
        x = rand() % 5;
        y = rand() % 5;
    }
    while (plansza[x][y] != ' ');

    plansza[x][y] = litery[rand() % 26];
}



void rysujwisielca(int bledy)
{
    cout << "\n";

    if (bledy == 1)
{
    cout << "     |\n";
    cout << "     |\n";
    cout << "     |\n";
    cout << "     |\n";
    cout << "     |\n";
    cout << "_____|____\n";
}

else if (bledy == 2)
{
    cout << "     |--------\n";
    cout << "     |\n";
    cout << "     |\n";
    cout << "     |\n";
    cout << "     |\n";
    cout << "_____|____\n";
}

else if (bledy == 3)
{
    cout << "     |--------\n";
    cout << "     |       |\n";
    cout << "     |       |\n";
    cout << "     |\n";
    cout << "     |\n";
    cout << "_____|____\n";
}

else if (bledy == 4)
{
    cout << "     |--------\n";
    cout << "     |       |\n";
    cout << "     |       O\n";
    cout << "     |\n";
    cout << "     |\n";
    cout << "_____|____\n";
}

else if (bledy == 5)
{
    cout << "     |--------\n";
    cout << "     |       |\n";
    cout << "     |       O\n";
    cout << "     |       |\n";
    cout << "     |       |\n";
    cout << "_____|____\n";
}

else if (bledy == 6)
{
    cout << "     |--------\n";
    cout << "     |       |\n";
    cout << "     |       O\n";
    cout << "     |      /|\\\n";
    cout << "     |       |\n";
    cout << "_____|____\n";
}

else if (bledy == 7)
{
    cout << "     |--------\n";
    cout << "     |       |\n";
    cout << "     |       O\n";
    cout << "     |      /|\\\n";
    cout << "     |       |\n";
    cout << "     |      / \\\n";
    cout << "_____|____\n";
}


}

int main()
{
    srand (time(0));

    string slowa[4] =
    {
        "informatyka",
        "kotek",
        "mieszkanie",
        "papuga"
    };
  int maxBledow = 7;
    int punkty = 1000;
    int runda = 1;

    bool koniecGry = false;


    for (runda = 1; runda <= 3; runda++)
{
    char plansza[5][5] =
{
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' '}
};

     int x = 2;
     int y = 2;

     int bledy = 0;
        int ruchy = 0;

        char ruch;


     int indeks = rand() % 4;

    string slowo = slowa[indeks];

    string zakryte (slowo.length(),'_');

    losujLitery(plansza, slowo);

{
    cout <<"\nautor:Jagoda Sobocinska " << endl;

    cout << "\n========================" << endl;
    cout << "          RUNDA" << endl;
    cout << "========================" << endl;

}
while (zakryte != slowo && bledy < maxBledow)
{
    rysujPlansze(plansza, x, y);
     rysujwisielca(bledy);

    cout << endl;
    cout << "W - gora | S - dol | A - lewo | D - prawo" << endl;
    cout << "Q - zakoncz gre" << endl;
    cout << "Poruszaj pionkiem @ i wejdz na litere." << endl;
    cout << "E - wybierz litere" << endl;

    cout << "Haslo: " << zakryte << endl;
    cout << "Punkty: " << punkty << endl;
    cout << "Ruchy: " << ruchy << endl;
    cout << "Bledy: " << bledy << "/" << maxBledow << endl;

    cout << "\nPodaj jeden ruch: ";
    cin >> ruch;

    if (ruch == 'q')
    {
        koniecGry = true;
        break;
    }

    if (ruch == 'w' && x > 0)
    {
        x--;
        ruchy++;
    }
    else if (ruch == 's' && x < 4)
    {
        x++;
        ruchy++;
    }
    else if (ruch == 'a' && y > 0)
    {
        y--;
        ruchy++;
    }
    else if (ruch == 'd' && y < 4)
    {
        y++;
        ruchy++;
    }

    if (ruch == 'e'|| ruch == 'E')
    {
        if (plansza[x][y] != ' ')
        {
            char wybranaLitera = plansza[x][y];

            cout << "\nWybrales litere: "
                 << wybranaLitera << endl;

            bool trafiono = false;

            for (int i = 0; i < slowo.length(); i++)
            {
                if (slowo[i] == wybranaLitera)
                {
                    zakryte[i] = wybranaLitera;
                    trafiono = true;
                }
            }

            if (trafiono)
            {
                cout << "Brawo! Dobra litera!" << endl;
                punkty += 100;
            }
            else
            {
                cout << "Niestety, tej litery nie ma w hasle."
                     << endl;

                bledy++;
                punkty -= 50;

                rysujwisielca(bledy);
            }

            plansza[x][y] = ' ';
            dodajNowaLitere(plansza);
        }
        else
        {
            cout << "Na tym polu nie ma litery." << endl;

            rysujwisielca(bledy);
        }
    }
}







        if (koniecGry)
        {
            break;
        }



        if (zakryte == slowo)
        {
            cout << "\n========================" << endl;
            cout << "      BRAWO! WYGRALAS!" << endl;
            cout << "========================" << endl;

            cout << "Haslo: " << slowo << endl;
            cout << "Punkty: " << punkty << endl;
            cout << "Liczba ruchow: " << ruchy << endl;
            cout << "Liczba bledow: " << bledy << endl;
        }
        else
        {
            rysujwisielca(bledy);

            cout << "\n========================" << endl;
            cout << "       KONIEC RUNDY" << endl;
            cout << "========================" << endl;

            cout << "Haslo: " << slowo << endl;
            cout << "Punkty: " << punkty << endl;
            cout << "Liczba ruchow: " << ruchy << endl;
            cout << "Liczba bledow: " << bledy << endl;
        }


        cout << "\nKoniec rundy " << runda << "!" << endl;

        if (runda < 3)
        {
            cout << "Za chwile rozpocznie sie kolejna runda!"
                 << endl;
        }
    }


    cout << endl;
    cout << "========================" << endl;
    cout << "       KONIEC GRY!" << endl;
    cout << "========================" << endl;
    cout << "Wynik koncowy: "
         << punkty << " punktow" << endl;

    cout << "Gratulacje!" << endl;


    return 0;
}
