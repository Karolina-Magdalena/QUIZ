#include <iostream>

using namespace std;

class Frage
{
public:
    string inhalt;
    string a,b,c,d;
    int nr_frage;
    string richtig;
    string antwort;
    int punkt; // 1 lub 0

    void lesen();
    void fragen();
    void prufen();

};
