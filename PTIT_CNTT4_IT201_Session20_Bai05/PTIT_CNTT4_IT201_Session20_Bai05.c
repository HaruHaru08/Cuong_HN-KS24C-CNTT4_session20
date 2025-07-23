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
int findMaxValue(Node* root) {
    if(root == NULL) {
        return -99999999;
    }
    int leftMax=findMaxValue(root->left);
    int rightMax=findMaxValue(root->right);
    int max=root->data;
    if(leftMax > max) {
        max = leftMax;
    }
    if(rightMax > max) {
        max = rightMax;
    }
    return max;
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
    printf("max value: %d",findMaxValue(root));
    free(root);
    return 0;
}