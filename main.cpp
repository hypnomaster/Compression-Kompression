/*
  Lauflaengenkodierung - RLE Runlength Encoding
  an einem Text-Beispiel
  P. Boeschen, 2015
*/

#include <iostream>
#include <fstream>

using namespace std;

void Komprimieren(string text);


int main(int argc, char *argv[])
{
    argv[0] = "test.txt";  // zum testen...

    fstream datei(argv[0]);
    if (!datei)
    {
        cerr << argv[0] << " kann nicht geoeffnet werden!" << endl;
    }
    else
    {
        while (datei)
        {
            string zeile;
            getline(datei, zeile);
            Komprimieren(zeile);
        }
    }

    return 0;
}

void Komprimieren(string text)
{
    string vorher = text.substr(0, 1);
    string nachher;
    int zaehler = 1;

    //cout << vorher;

    for (int i = 1; i <= text.length(); i++)
    {
        nachher = text.substr(i, 1);
        if (nachher == vorher)
        {
            zaehler++;
        }
        else
        {
            cout << zaehler << vorher;
            zaehler = 1;
        }
        vorher = nachher;
    }
}
