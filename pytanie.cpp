#include <iostream>
#include "pytanie.h"
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <windows.h>

using namespace std;

void Frage::lesen()
{
    fstream datei;
    datei.open("quizD.txt",ios::in);

    if (datei.good()==false) {cout<<"Diese Datei kann man nicht offnen!"<<endl; exit(0);}

    int nr_linie=(nr_frage-1)*6+1;
    int aktuell_nr=1;
    string linie;

    while (getline(datei,linie))
    {
        if (aktuell_nr==nr_linie) inhalt=linie;
        if (aktuell_nr==nr_linie+1) a=linie;
        if (aktuell_nr==nr_linie+2) b=linie;
        if (aktuell_nr==nr_linie+3) c=linie;
        if (aktuell_nr==nr_linie+4) d=linie;
        if (aktuell_nr==nr_linie+5) richtig=linie;
        aktuell_nr++;
    }
    datei.close();
}

void Frage::fragen()
{
    cout<<endl<<inhalt<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
    cout<<"--------------------------"<<endl;
    cout<<endl<<"Antwort: ";
    cin>>antwort;
    transform(antwort.begin(), antwort.end(), antwort.begin(), ::tolower);
}

void Frage::prufen()
{
    if (antwort==richtig)
    {
        cout<<"Richtig!"<<endl;
        punkt=1;
        Sleep(1000);
    }
    else
    {
        cout<<"Falsch! Richtige Antwort ist "<<richtig<<endl;
        punkt=0;
        Sleep(1000);
    }
}
