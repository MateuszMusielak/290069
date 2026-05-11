#ifndef LISTAOBECNOSCI_H
#define LISTAOBECNOSCI_H
#include "Osoba.h"
#include <string>

#define MAX_OSOB 100

enum class WynikDodawania { 
    SUKCES,
    BRAK_MIEJSCA,
    DUPLIKAT_INDEKSU
};

enum class WynikUsuwania {
    SUKCES,
    NIE_ZNALAZIONO,
    PUSTA_LISTA
};

enum class WynikEdycji {
    SUKCES,
    NIE_ZNALAZIONO,
    DUPLIKAT_INDEKSU
};

enum class WynikPrzelaczenia {
    SUKCES,
    NIE_ZNALAZIONO
};


class ListaObecnosci{
private:
    Osoba osoby[MAX_OSOB];
    bool obecnosci[MAX_OSOB];
    int liczbaOsob;

    int znajdzPozycje(int nrIndexu) const;

public:
    ListaObecnosci();

    //~ListaObecnosci();

    WynikDodawania dodajOsobe(const std::string& imie, const std::string& nazwisko, int nrIndexu);
    WynikUsuwania usunOsobe(int nrIndexu);
    WynikEdycji edytujOsobe(int nrIndexu,const std::string& noweImie, const std::string& noweNazwisko, int nowyNrIndexu );
    WynikPrzelaczenia przelaczObecnosc(int nrIndexu);
    void wyswietlWszytskie() const;
    int getLiczbaOsob() const;
    bool czyIndexIstnieje(int nrIndexu) const;
    void wyswietlOsobe(int nrIndexu) const;
    WynikPrzelaczenia przelaczWszytskich(bool status);

    



};



#endif