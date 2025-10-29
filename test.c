
#include <stdio.h>                                                    
#include <stdlib.h>
#include <time.h>  

// ### Deklaracia funkcii ###

// Generuje nahodne cele cislo v r rozsahu min, max
int nahodneCislo(int min, int max);

// Vypise hodnoty prvkov pola pod seba
void vypisPole(int pole[], int pocet);

// Naplni prvky pola celociselnymi hodnotami v rozsahu min, max
void naplnPoleNahodnymiCislami(int pole[], int pocet, int minHodnota, int maxHodnota);

//
int *obsahujeHodnotu(int pole[], int pocet, int hladanaHodnota);

int main(void) {

    const int pocetPrvkov = 100;   // Velkost pola
    int minNahodneCislo = 0;      // minimalna hodnota nahodneho cisla
    int maxNahodneCislo = 200;    // maximalna hodnota nahodneho cisla

    int array[pocetPrvkov];             // pole prvkov

    //generator nahodnych cisel
    srand(time(NULL));

    naplnPoleNahodnymiCislami(array, pocetPrvkov, minNahodneCislo, maxNahodneCislo);

    // Generovanie čísla, ktoré budeme hľadať
    int hladaneCislo = nahodneCislo(minNahodneCislo, maxNahodneCislo);
    printf("Hľadané číslo: %d\n\n", hladaneCislo);

    vypisPole(array, pocetPrvkov);

    int hladaneCislo;
    int *smernik;

    // Hľadanie hodnoty v poli
    if ((hladaneCislo = nahodneCislo(minNahodneCislo, maxNahodneCislo)) &&
    (smernik = obsahujeHodnotu(array, pocetPrvkov, hladaneCislo))) {
    
        printf("Hľadané číslo: %d\n\n", hladaneCislo);
        printf("Hodnota cez smerník: %d, index: %ld, adresa: %p\n\n",
        *smernik, smernik - array, (void *)smernik);

    } else {
        printf("Hľadané číslo: %d\n\n", hladaneCislo);
        printf("\nČíslo %d sa nenachádza v poli.\n\n", hladaneCislo);
    }

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

//Zisti, ci sa hodnota nachadza v poli
int obsahujeHodnotu(int pole[], int pocet, int hladanaHodnota){
    for (int i = 0; i < pocet; i++) {
        if (pole[i] == hladanaHodnota) {
            return &pole[i]; // našli sme hodnotu
        }
    }
    return NULL; // nenašli sme hodnotu
}
