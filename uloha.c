//
//  uloha.c
//  
//  Created by Jana on 10/10/2024.
//
//  Uloha c 1
//  Vytvorte jednorozmerne pole s velkostou 10 a naplnte ho nahodnymi celymi cislami.
//  Cisla generujte pomocou funkcie, ktora ako argumenty prijima minimalnu a maximalnu hodnotu.
//  Po naplneni pola vypiste kazdy prvok spolu s jeho indexom pricom na vypis pouzite samostatnu funkciu.


#include <stdio.h>                                                    
#include <stdlib.h>  

// ### Deklaracia funkcii ###

// Generuje nahodne cele cislo v r rozsahu min, max
int nahodneCislo(int min, int max);

// Vypise hodnoty prvkov pola pod seba
void vypisPole(int pole[], int pocet);

// Naplni prvky pola celociselnymi hodnotami v rozsahu min, max
void naplnPoleNahodnymiCislami(int pole[], int pocet, int minHodnota, int maxHodnota);

int main(void) {
    const int pocetPrvkov = 100;        // Velkost pola
    const int minNahodneCislo = 0;      // minimalna hodnota nahodneho cisla
    const int maxNahodneCislo = 200;    // maximalna hodnota nahodneho cisla

    int array[pocetPrvkov];             // pole prvkov

    naplnPoleNahodnymiCislami(array, pocetPrvkov, minNahodneCislo, maxNahodneCislo);

    vypisPole(array, pocetPrvkov);

    return 0;
}


// ### Definicie funkcii
int nahodneCislo(int min, int max) {
        return (rand () % (max - min + 1)) + min;
}

void vypisPole(int pole[], int pocet){
    for (int i = 0; i < pocet; i++) {
        printf("array[%d] = %d\n", i+1, pole[i]);
    }
}

void naplnPoleNahodnymiCislami(int pole[], int pocet, int minHodnota, int maxHodnota){
    for (int r = 0; r < pocet; r++) {
        pole[r]= nahodneCislo(minHodnota, maxHodnota);
    }
}
