#ifndef OSOBA_h
#define OSOBA_h

#include <iostream>
#include <string>

class Osoba {
    private:
    int nrIndexu;
    std::string imie,nazwisko;

    public:
    Osoba();
    Osoba(const std::string& imie, const std::string& nazwisko, int nrIndexu);

    //~Osoba();

    //getery, & tylko dla zwracanego pojdenycznej zmienne klasy
    const std::string& getImie() const;
    const std::string& getNazwisko() const;
    int getIndex() const;
    void wyswietl() const;

    //settery
    void setImie(std::string noweImie);
    void setNazwisko(std::string noweNazwisko);
    void setIndex(int nowyIndex);

    
};

#endif