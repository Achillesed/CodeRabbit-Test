#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;


int Abilities_Sensitivity_Flow_StrongUpdate_bad(Node *a, Node *b, Node *c) {
    a->next = c;
    a->next = b; // strong update
    a->next->data = 5;
    return 100 / (a->next->data - 5);
}

int Abilities_Sensitivity_Flow_StrongUpdate_good(Node *a, Node *b, Node *c) {
    a->next = c;
    a->next->data = 5;
    a->next = b; // strong update
    return 100 / (a->next->data - 5);
}

int Abilities_Sensitivity_Flow_StrongUpdate_bad_main() {
    Node *a = (Node *) malloc(sizeof(Node));
    Node *b = (Node *) malloc(sizeof(Node));
    Node *c = (Node *) malloc(sizeof(Node));
    int res = Abilities_Sensitivity_Flow_StrongUpdate_bad(a, b, c);

    free(a);
    free(b);
    free(c);
    return res;
}

int Abilities_Sensitivity_Flow_StrongUpdate_good_main() {
    Node *a = (Node *) malloc(sizeof(Node)); a->data = 1;
    Node *b = (Node *) malloc(sizeof(Node)); b->data = 1;
    Node *c = (Node *) malloc(sizeof(Node)); c->data = 1;
    int res = Abilities_Sensitivity_Flow_StrongUpdate_good(a, b, c);

    free(a);
    free(b);
    free(c);
    return res;
}