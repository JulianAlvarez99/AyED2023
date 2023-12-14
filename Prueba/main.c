#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct {
    char *word;
    int count;
} word_count_t;

void crear(word_count_t *wc, char *word) {
    wc->word = strdup(word);
    wc->count = 1;
}

void liberar(word_count_t *wc) {
    free(wc->word);
}

int buscar(word_count_t vector[], int tam, char *word) {
    for (int i = 0; i < tam; i++) {
        if (strcmp(vector[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void agregar(word_count_t vector[], int *tam, char *word) {
    int index = buscar(vector, *tam, word);
    if (index == -1) {
        // La palabra no existe, crear un nuevo elemento
        word_count_t wc;
        crear(&wc, word);

        // Agregar el nuevo elemento al vector
        vector[*tam] = wc;
        *tam += 1;
    } else {
        // La palabra ya existe, incrementar count
        vector[index].count++;
    }
}

void eliminar(word_count_t vector[], int *tam, char *word) {
    int index = buscar(vector, *tam, word);
    if (index != -1) {
        vector[index].count--;
        if (vector[index].count == 0) {
            liberar(&vector[index]);

            // Mover los elementos restantes hacia la izquierda
            for (int i = index; i < (*tam)-1; i++) {
                vector[i] = vector[i+1];
            }

            // Reducir el tamaño del vector
            *tam -= 1;
        }
    }
}

int main() {
    // Crear el array de word_count_t
    word_count_t vector[MAX_WORDS];
    int tam = 0;

    // Agregar algunas palabras
    agregar(vector, &tam, "hola");
    agregar(vector, &tam, "mundo");
    agregar(vector, &tam, "hola");

    // Mostrar el contenido del vector
    for (int i = 0; i < tam; i++) {
        printf("%s: %d\n", vector[i].word, vector[i].count);
    }

    // Eliminar algunas palabras
    eliminar(vector, &tam, "hola");
    eliminar(vector, &tam, "adios");

    // Mostrar el contenido del vector actualizado
    printf("\n");
    for (int i = 0; i < tam; i++) {
        printf("%s: %d\n", vector[i].word, vector[i].count);
    }

    // Liberar la memoria utilizada
    for (int i = 0; i < tam; i++) {
        liberar(&vector[i]);
    }
}
