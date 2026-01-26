#include "benchmark.h"
#include <stdlib.h>

typedef struct Node {
    struct Node *p1;
    struct Node *p2;
    int data;
} Node;

int Abilities_Sensitivity_Field_Struct_bad(Node *n, int a) {
    n->p1 = n;
    n->p2 = NULL;
    n->data = a;
    return n->p2->data;
}

int Abilities_Sensitivity_Field_Struct_good(Node *n, int a) {
    n->p1 = n;
    n->p2 = NULL;
    n->data = a;
    return n->p1->data;
}

int Abilities_Sensitivity_Field_Struct_bad_main() {
    int input;
    scanf("%d\n", &input);
    Node *n = (Node *)malloc(sizeof(Node));
    int r = Abilities_Sensitivity_Field_Struct_bad(n, input); 
    free(n);
    return r;
}

int Abilities_Sensitivity_Field_Struct_good_main() {
    int input;
    scanf("%d\n", &input);
    Node *n = (Node *)malloc(sizeof(Node));
    int r = Abilities_Sensitivity_Field_Struct_good(n, input); 
    free(n);
    return r;
}