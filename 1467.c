#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
    int value;
    struct node *left;
    struct node *right;
};

int n;

void insert_to_tree(Node *p, int value) {
    if (p == NULL) {
        p = (Node *)malloc(sizeof(Node));
        p->value = value;
        p->left = NULL;
        p->right = NULL;
        return;
    } else {
        if (p->value < value) {
            insert_to_tree
        }
    }
}

int main() {
    int n;
    int data;
    Node *tree = NULL;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &data);
        insert_to_tree(tree, data);
    }
    return 0;
}
