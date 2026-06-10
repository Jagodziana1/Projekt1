#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;


int main()
{
    srand (time(0));

    string slowa[4] =
    {
        "informatyka"
        "kotek"
        "mieszkanie"
        "papuga"
    };
    int indeks = rand() % 4;
    string slowo = slowa[indeks];

    string zakryte = "";

    char litera;

    int bledy = 0;
    int maxBledow = 0;

    while (zakryte != slowo && bledy < maxBledow)
    {

        cout << "\nSlowo:" << zakryte << endl;
        cout << "pozostalo prob:" << maxBledow - bledy << endl;

        cout << "Podaj litere:";
        cin >> litera;

        bool trafiono=false;

        for (int i=0;i < slowo.lenght();i++)
            {
            if (slowo[i]==litera)
            {
                zakryte[i]==litera;
                trafiono = true;
            }
        }
        if (trafiono)
        {
            cout << "Brawo dobra litera!!\n";
        }
        else
        {
            cout << "Nie ma takiej litery... ";
            bledy++;

        }


    }
    if (zakryte==slowo){
        cout << "Brawo wygrales!!\n";
        cout << "Haslo:" << slowo << endl;
    }
    else{
        cout << "\nNiestety przegrales...";
        cout << "Haslo:" << slowo << endl;
    }
    return 0;
}
