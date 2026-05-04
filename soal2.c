/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 04
 *   Hari dan Tanggal    : Senin, 4 Mei 2026
 *   Nama (NIM)          : M Agni Aulia Fadhly Saepudin (13224042)
 *   Nama File           : soal2.c
 *   Deskripsi           : 
 
    [SOAL 2]
    Menggabungkan dua linkedlist terurut naik dengan memenuhi kondisi:
    - Kedua list sudah terurut
    - Hasil merge juga terurut
    - Semua elemen harus muncul
    - Boleh ada duplikasi 

/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
*/

#include <stdio.h>
#include <stdlib.h>

// Struktur node untuk Linked List
typedef struct node {
    int data;
    struct node* next;
} node;

struct node* createNode(int newData){ //[1]
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = newData;
    node->next = NULL;
    return node;
}

void insert(struct node* header, int x) { // [1]
    struct node* curr = header;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    struct node* newNode = createNode(x);
    curr->next= newNode;
}

void printList(struct node* header) { // [1]
    struct node* curr = header->next;
    while (curr!=NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

struct node* sortMerge(struct node* a, struct node* b) { // [2]
    struct node* result = NULL;

    // base case
    if (a == NULL) {
        return (b);
    } else if (b == NULL) {
        return (a);
    }

    if (a->data <= b->data) {
        result = a;
        result->next = sortMerge(a->next, b);
    } else {
        result = b;
        result->next = sortMerge(a, b->next);
    }
    return result;
}

int main() {
    // Deklarasi Var.
    //node L1 = createNode(NULL);
    //node L2 = createNode(NULL);
    struct node* listN = createNode(0);
    struct node* listM = createNode(0);
    struct node* merge;
    
    int N, M; //banyak node pada list
    int temp;

    // INPUT
    //  input N
    scanf("%d", &N);
    //  loop input llist N dari node kedua
    for (int i=1; i<=N; i++) {
        scanf(" %d", &temp);
        insert(listN, temp);
    }
    // input M
    //  input M
    scanf("%d", &M);
    //  loop input llist M dari node kedua
    for (int i=1; i<=M; i++) {
        scanf(" %d", &temp);
        insert(listM, temp);
    }


    // PROCESS
    merge = sortMerge(listN, listM);

    // OUTPUT
    printf("MERGED ");
    printList(listM);

    return 0;
}

/*
    REFERENSI
    [1] https://www.geeksforgeeks.org/dsa/header-linked-list-in-c/
    [2] https://www.geeksforgeeks.org/c/c-program-for-merge-sort-for-linked-lists/

*/
