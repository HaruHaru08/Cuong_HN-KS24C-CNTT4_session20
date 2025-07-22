#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;
typedef struct Queue {
    Node** arr;
    int cap;
    int front;
    int rear;
}Queue;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* createQueue(int cap) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->arr = (Node**)malloc(sizeof(Node*) * cap);
    queue->cap = cap;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}
int isEmpty(Queue* queue) {
    return queue->front>queue->rear;
}
int isFull(Queue* queue) {
    return queue->rear==queue->cap-1;
}
void enQueue(Queue* queue,Node* node) {
    if(isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = node;
}
Node* deQueue(Queue* queue) {
    if(isEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return queue->arr[queue->front++];
}
void addTree(Node* root,int numAdd) {
    if (root == NULL) {
        return;
    }
    Queue* queue=createQueue(100);
    enQueue(queue,root);
    while (!isEmpty(queue)) {
        Node* current=deQueue(queue);
        if (current->left==NULL) {
            current->left=createNode(numAdd);
            return;
        }else {
            enQueue(queue,current->left);
        }
        if (current->right==NULL) {
            current->right=createNode(numAdd);
            return;
        }else {
            enQueue(queue,current->right);
        }
    }
}
void levelOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    Queue* queue=createQueue(100);
    enQueue(queue,root);
    while (!isEmpty(queue)) {
        Node* current=deQueue(queue);
        printf("%d ",current->data);
        printf("\n");
        if (current->left!=NULL) {
            enQueue(queue,current->left);
        }
        if (current->right!=NULL) {
            enQueue(queue,current->right);
        }
    }
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
    int numAdd;
    printf("Nhap so can them: ");
    scanf("%d",&numAdd);
    addTree(root, numAdd);
    levelOrder(root);
    free(root);
    return 0;
}