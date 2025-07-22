#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int main() {
    int num;
    scanf("%d", &num);
    Node* root=NULL;
    root=createNode(num);
    printf("node={\n"
           "  data: %d\n"
           "  left-> NULL\n"
           "  right-> NULL\n"
           "}",root->data);
    free(root);
    return 0;
}