/*
Uloha c 1
Vytvorte jednorozmerne pole s velkostou 10 a naplnte ho nahodnymi celymi cislami. Cisla generujte pomocou funkcie, ktora ako argumenty prijima minimalnu a maximalnu hodnotu. Po naplneni pola vypiste kazdy prvok spolu s jeho indexom pricom na vypis pouzite samostatnu funkciu.
 
 Autor: Jana Chytilova
 */

#include <stdio.h>                                                    
#include <stdlib.h>  

//funkcia generovania nahodneho cisla v rozsahu min, max
int nahodneCislo(int min, int max) {
        return (rand () % (max - min + 1)) + min;

}

int main(void) {

    //pole s 10 timi prvkami
    int array[10];
 
    // naplnenie pola nahodnymi cislami
    for (int i = 0; i < 10; i++) {
        array[i] = nahodneCislo(0, 9);  // ulozenie cisla do pola
    }

    // vypisanie obshau pola
    for (int i = 0; i < 10; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}
