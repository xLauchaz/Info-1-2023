#include <stdio.h>

int main(void){
    char* frases[10] = {
        "El y su familia cantaban y bailaban...",
        "Podria haber hecho dulces.",
        "La musica habia destrozado a su familia",
        "Eres músico, ¿No?",
        "Me vas a meter en problemas, chico",
        "Hora del espectaculo, chamaco",
    };

    printf("%s\n", frases[3]);

    return 0;
}