//
//  main.cpp
//  PAMSI
//
//  Created by Gerard on 16/03/2019.
//  Copyright © 2019 Gerard. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "klasa.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    clock_t start,stop,start1,stop1;
    int Elementy[] = {10000, 50000, 100000, 500000, 1000000};
    double Posortowane[] = {0, 25, 50, 75, 95, 99, 99.7};
    double czas=0;
    srand( (int)time( NULL ) );
    
//    start1 = clock();
//    for(int i=0; i<sizeof(Posortowane)/sizeof(double); i++)
//	for(int j=0; j<sizeof(Elementy)/sizeof(int); j++)
//	    for(int k=0; k<100; k++)
//		{
//		    Tablica Tabliczka(Elementy[j]);
//		    Tabliczka.WypelnijLos(Elementy[j],Elementy[j],Posortowane[i]);
//		    start = clock();
//		    Tabliczka.Quicksort(0, Elementy[j]-1);
//		    stop = clock();
//		    czas = (double)(stop-start)/CLOCKS_PER_SEC;
//		    cout<<"czas sortowania dla "<<Elementy[j]<<" elementów i "<<Posortowane[i]<<"% posortowania wynosił "<<czas<<" s"<<endl;
//		};
//    stop1 = clock();
//    czas = (double)(stop1-start1)/CLOCKS_PER_SEC;
//    cout<<"czas wykonywania całego programy wynosił: "<<czas<<" s"<<endl;

    start1 = clock();
    for(int i=0; i<sizeof(Posortowane)/sizeof(double); i++)
	for(int j=0; j<sizeof(Elementy)/sizeof(int); j++) {
	    for(int k=0; k<100; k++)
	    {
		Tablica Tabliczka(Elementy[j]);
		Tabliczka.WypelnijLos(Elementy[j],Elementy[j],Posortowane[i]);
		//Tabliczka.WypelnijTyl(Elementy[j]);
		start = clock();
		Tabliczka.Quicksort(0, Elementy[j]-1);
		stop = clock();
		czas += (double)(stop-start)/CLOCKS_PER_SEC;
	    };
	    
	    czas = czas/100;
	    //cout<<" średni czas sortowania dla "<<Elementy[j]<<" elementów i "<<Posortowane[i]<<"% posortowania wynosił "<<czas<<" s"<<endl;
	    cout<<czas<<endl;
	    czas=0;
	}
    stop1 = clock();
    czas = (double)(stop1-start1)/CLOCKS_PER_SEC;
    cout<<"czas wykonywania całego programy wynosił: "<<czas<<" s"<<endl;
    return 0;
}
