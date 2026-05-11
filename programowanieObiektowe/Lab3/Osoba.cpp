#include "Osoba.h"
#include <iostream>
#include <string>

//deklaracja klasy wedlug c++ 11

Osoba::Osoba() : imie(""), nazwisko(""), nrIndexu(0) {}
Osoba::Osoba(const std::string& imie, const std::string& nazwisko, int nrIndexu)
    :imie(imie), nazwisko(nazwisko), nrIndexu(nrIndexu) {}

//gettery const bez mozliwosci edycji
const std::string& Osoba::getImie() const{
    return imie;
}
const std::string& Osoba::getNazwisko() const{
    return nazwisko;
}
int Osoba::getIndex() const{
    return nrIndexu;
}
 void Osoba::wyswietl() const{
    std::cout<<"Imię: "<<imie<<" ,Nazwisko: "<<nazwisko<<" ,nr Indexu: "<<nrIndexu<<std::endl;
}


//settery - move dla optymalizacji (bez kopiowania) + walidacje dorob
void Osoba::setImie(std::string noweImie){
    imie=std::move(noweImie);
}
void Osoba::setNazwisko(std::string noweNazwisko){
    nazwisko = std::move(noweNazwisko);
}
void Osoba::setIndex(int nowyIndex){
    nrIndexu = nowyIndex;
}
