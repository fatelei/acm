#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
    int value;
    struct node *lchild;
    struct node *rchild;
};

int count;

Node *build_tree(Node *root, int value) {
    if (root == NULL) {
        root = (Node *)malloc(sizeof(Node));
        root->value = value;
        root->lchild = NULL;
        root->rchild = NULL;
        return root;
    }
    if (root->value > value) {
        root->lchild = build_tree(root->lchild, value);
        return root;
    }
    if (root->value < value) {
        root->rchild = build_tree(root->rchild, value);
        return root;
    }
}

void afterorder(Node *root) {
    if (root->lchild != NULL) {
        afterorder(root->lchild);
    }
    if (root->rchild != NULL) {
        afterorder(root->rchild);
    }
    if (count == 1) {
        printf("%d\n", root->value);
    } else {
        count--;
        printf("%d ", root->value);
    }
}

int main() {
    int cases;
    int num;
    int value;
    Node *root;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &num);
        root = NULL;
        count = num;
        while (num--) {
            scanf("%d", &value);
            root = build_tree(root, value);
        }
        afterorder(root);
    }
    return 0;
}
