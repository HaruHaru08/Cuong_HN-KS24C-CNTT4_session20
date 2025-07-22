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
int findLevel(Node* root,int value) {
    if(root == NULL) {
        return -1;
    }
    if(root->data == value) {
        return 0;
    }
    int left=findLevel(root->left,value);
    if (left!=-1) return left+1;
    int right=findLevel(root->right,value);
    if(right!=-1) return right+1;
    return -1;
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
    int level = findLevel(root,3);
    if(level==-1) {
        printf("Not Found\n");
    }else {
        printf("Node level:  %d\n",level);
    }
    free(root);
    return 0;
}