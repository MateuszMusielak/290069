#ifndef INTERFEJSUZYTKOWNIKA_H
#define INTERFEJSUZYTKOWNIKA_H
#include "ListaObecnosci.h"

class InterfejsUzytkownika{
private:
ListaObecnosci lista;
int wczytajLiczbe(const std::string& prompt);

    void wyswietlMenu();
    void obsluzDodawanie();
    void obsluzUsuwanie();
    void obsluzEdytowanie();
    void obsluzWyswietlanie();
    void obsluzZmienObecnosc();
    void obsluzZmienObecnoscWszytskim();
    

public:
    void uruchom();



};






#endif