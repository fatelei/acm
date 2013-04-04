#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node Node;

struct node {
    struct node *left;
    struct node *right;
    int value;
};

Node n[1000];

Node *build_tree(Node *tree, Node *item) {
    if (tree == NULL) {
        tree = (Node *)malloc(sizeof(Node));
        tree->left = NULL;
        tree->right = NULL;
        tree->value = item->value;
        printf("-1\n");
        return tree;
    }
    if (item->value > tree->value && tree->right == NULL) {
        tree->right = item;
        printf("%d\n", tree->value);
        return tree;
    } else if (item->value < tree->value && tree->left == NULL) {
        tree->left = item;
        printf("%d\n", tree->value);
        return tree;
    } else if (item->value > tree->value && tree->right != NULL) {
        tree->right = build_tree(tree->right, item);
        return tree;
    } else if (item->value < tree->value && tree->left != NULL) {
        tree->left = build_tree(tree->left, item);
        return tree;
    }
}

int main() {
    int nums;
    int i;
    int j;
    int path;
    Node *tree;
    while (scanf("%d", &nums) != EOF) {
        tree = NULL;
        for (i = 0; i < nums; i++) {
            scanf("%d", &n[i].value);
            n[i].left = NULL;
            n[i].right = NULL;
            tree = build_tree(tree, &n[i]);
        }
    }
    return 0;
}
