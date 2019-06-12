//
//  klasa.hpp
//  PAMSI
//
//  Created by Gerard on 16/03/2019.
//  Copyright © 2019 Gerard. All rights reserved.
//

#ifndef klasa_hpp
#define klasa_hpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

class Tablica{
    double *Tab;
    
    public:
    double &operator [] (unsigned i){return Tab[i];};
    const double &operator [] (const unsigned i)const{return Tab[i];};
    void WypelnijLos(int Rozmiar, int Limit, int Posortowanie);
    void WypelnijTyl(int Rozmiar);
    int Partycja(int lewy, int prawy);
    void Quicksort(int lewy, int prawy);
    void NajwiekszyKopiec(int lewy, int prawy, int index);
    void Kopcowanie(int lewy, int prawy);
    void Wstawianie(int wielkosc);
    void IntrospectiveSort(int lewy, int prawy);
    void IntroSort(int lewy, int prawy, int glebokosc);
    void Scal(int lewy, int srodek, int prawy);
    void Scalanie(int lewy, int prawy);
    Tablica(int Rozmiar) {Tab = new double [Rozmiar];};
    ~Tablica() {};
};
#endif /* klasa_hpp */
