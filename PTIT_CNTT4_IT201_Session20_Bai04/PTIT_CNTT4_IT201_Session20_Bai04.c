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
int countLeaves(Node* node) {
    if(node == NULL) {
        return 0;
    }
    if(node->left == NULL && node->right == NULL) {
        return 1;
    }
    return countLeaves(node->left) + countLeaves(node->right);
}
int main() {
    Node* root = NULL;
    root=createNode(2);
    Node* node1=createNode(3);
    Node* node2=createNode(5);
    Node* node3=createNode(4);
    root->left=node1;
    root->right=node3;
    node1->left=node2;
    printf("number of leaves: %d",countLeaves(root));
    free(root);
    return 0;
}