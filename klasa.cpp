//
//  klasa.cpp
//  PAMSI
//
//  Created by Gerard on 16/03/2019.
//  Copyright © 2019 Gerard. All rights reserved.
//

#include "klasa.hpp"

using namespace std;

void Tablica::WypelnijLos(int Rozmiar, int Limit, int Posortowanie)
{
    int iloscPosortowanych = (Rozmiar * Posortowanie)/100;
    for(int i=0;i<iloscPosortowanych;i++) {
        Tab[i]=i;
    }
    for (int i=iloscPosortowanych; i<Rozmiar; i++) {
        Tab[i]=rand()%Limit+iloscPosortowanych;
    };
};

void Tablica::WypelnijTyl(int Rozmiar)
{
    for(int i=0;i<Rozmiar;i++)
        Tab[i]=Rozmiar-i;
}

int Tablica::Partycja(int lewy, int prawy){
    int pivot = Tab[(lewy+prawy)/2];
    int temp;
    int i = lewy;
    
    for (int j = lewy; j < prawy; ++j)
    {
        if (Tab[j] <= pivot)
        {
            temp = Tab[j];
            Tab[j] = Tab[i];
            Tab[i] = temp;
            i++;
        }
    }
    
    Tab[prawy] = Tab[i];
    Tab[i] = pivot;
    
    return i;
}


void Tablica::NajwiekszyKopiec(int lewy, int prawy, int index) {
    int lewy1 = (index + 1) * 2 - 1 + lewy;
    int prawy1 = (index + 1) * 2 + lewy;
    int największy = lewy;
    
    if (lewy1 < prawy+1 && Tab[lewy1] > Tab[index+lewy])
        największy = lewy1;
    else
        największy = index+lewy;
    
    if (prawy1 < prawy+1 && Tab[prawy1] > Tab[największy])
        największy = prawy1;
    
    if (największy != (index+lewy))
    {
        int temp = Tab[index+lewy];
        Tab[index+lewy] = Tab[największy];
        Tab[największy] = temp;
        
        NajwiekszyKopiec(lewy, prawy, największy);
    }
}

void Tablica::Kopcowanie(int lewy, int prawy) {
    int prawy2 = prawy;
    
    for (int p = (prawy2-lewy - 1) / 2; p >= 0; --p)
        this->NajwiekszyKopiec(lewy, prawy2, p);
    
    for (int i = prawy - 2; i > lewy; --i)
    {
        int temp = Tab[i];
        Tab[i] = Tab[lewy];
        Tab[lewy] = temp;
        
        --prawy2;
        this->NajwiekszyKopiec(lewy, prawy2, 0);
    }
}

void Tablica::Wstawianie(int wielkosc) {
    for (int i = 1; i < wielkosc; i++)
    {
        int j = i;
    
        while (j > 0)
        {
            if (Tab[j - 1] > Tab[j])
                {
                    int temp = Tab[j];
                    Tab[j]=Tab[j-1];
                    Tab[j-1]=temp;
                    --j;
                }
            else
            {
                break;
            }
        }
    }
}

void Tablica::Quicksort(int lewy, int prawy) {
    if (lewy < prawy)
    {
        int q = this->Partycja(lewy, prawy);
        this->Quicksort(lewy, q-1);
        this->Quicksort(q+1, prawy);
    }
};

void Tablica::IntrospectiveSort(int lewy, int prawy) {
    int glebokosc=1.4 * log2(prawy+1);
    this->IntroSort(lewy, prawy, glebokosc);
}


void Tablica::IntroSort(int lewy, int prawy, int glebokosc) {
    if (lewy < prawy) {
        int q = this->Partycja(lewy, prawy);
        if (glebokosc == 0) {
            this->Kopcowanie(lewy, prawy);
        }
        else {
            //cout<<"intro ";
            this->IntroSort(lewy, q-1, glebokosc-1);
            this->IntroSort(q+1, prawy, glebokosc-1);
        }
    }
}

void Tablica::Scal(int lewy, int srodek, int prawy)
{
    double *Pom = new double[prawy+1];
    int i,j,q;
    for (i=lewy; i<=prawy; i++) Pom[i]=Tab[i];
    i=lewy; j=srodek+1; q=lewy;
    while (i<=srodek && j<=prawy) {
        if (Pom[i]<Pom[j])
            Tab[q++]=Pom[i++];
        else
            Tab[q++]=Pom[j++];
    }
    while (i<=srodek) Tab[q++]=Pom[i++];
    delete [] Pom;
}

void Tablica::Scalanie(int lewy, int prawy)
{
    int srodek;
    if (lewy<prawy) {
        srodek=(lewy+prawy)/2;
        Scalanie(lewy, srodek);    // Dzielenie lewej części
        Scalanie(srodek+1, prawy);   // Dzielenie prawej części
        Scal(lewy, srodek, prawy);
    }
}
