#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


int main()
{
    const int ROZMIAR=5;
    int plansza [ROZMIAR][ROZMIAR]={0};

    srand(time(0));

    int ukrytywiersz = rand () % 5;
    int ukrytakolumna = rand () % 5;
}
