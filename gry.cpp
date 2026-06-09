 #include <iostream>
#include <string>

using namespace std;


int main()
{
    string slowo = "komputer";
    string zakryte = "________";

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
}
