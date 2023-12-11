#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/***** SEARCH *****/
int sequential_search(int key, int a[], int n) {
    int i = 0;
    while ((i < n) && (a[i] != key)) {
        i++;
    }
    return i;
}

int sequential_sorted_search(int key, int a[], int n) {
    int i = 0;
    while ((i < n) && (a[i] < key)) {
        i++;
    }
    return (a[i] == key) ? i : n;
}

int binary_sorted_search(int key, int a[], int n) {
    int high = n - 1;
    int low = 0;
    int mid = (high - low) / 2;
    while ((low < high) && (a[mid] != key)) {
        if (key < a[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (high + low) / 2;
    }
    return (a[mid] == key) ? mid : n;
}

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void select_sort(int a[], int n) {
    for (; n > 0; n--) {
        for (int i = 0; i < n; i++) {
            if (a[n - 1] < a[i]) {
                swap(&a[n - 1], &a[i]);
            }
            printf(".");
        }
    }
    printf("\n");
}

/*void bubble_sort_v1(int a[], int n) {
    for (; n > 0; n--) {
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                swap(&a[i - 1], &a[i]);
            }
            printf(".");
        }
    }
    printf("\n");
}*/

void bubble_sort_v2(int a[], int n) {
    char swapped = 1;
    while ((swapped != 0) && (n > 0)) {
        swapped = 0;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                swap(&a[i - 1], &a[i]);
                swapped = 1;
            }
            printf(".");
        }
        n--;
    }
    printf("\n");
}


int compare (int a, int b) {
    return a - b;
}

int compare_inv (int a, int b) {
    return b - a;
}

void bubble_sort_func(int a[], int n, int cmp (int, int) ) {
    char swapped = 1;
    while ((swapped != 0) && (n > 0)) {
        swapped = 0;
        for (int i = 1; i < n; i++) {
            if (cmp(a[i - 1],a[i]) > 0) {
                swap(&a[i - 1], &a[i]);
                swapped = 1;
            }
        }
        n--;
    }
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
