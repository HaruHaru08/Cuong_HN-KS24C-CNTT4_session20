#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;
typedef struct Queue {
    Node** data;
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
Queue* createQueue(int cap) {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->data = (Node**)malloc(sizeof(Node*) * cap);
    newQueue->cap = cap;
    newQueue->front = 0;
    newQueue->rear = -1;
    return newQueue;
}
int isEmpty(Queue* queue) {
    return queue->front>queue->rear;
}
int isFull(Queue* queue) {
    return queue->rear==queue->cap-1;
}
void enqueue(Queue* queue, Node* node) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->data[queue->rear] = node;
}
Node* dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return queue->data[queue->front++];
}
void preOrder(Node* root) {
    if (root==NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOder(Node* root) {
    if (root==NULL) {
        return;
    }
    inOder(root->left);
    printf("%d ", root->data);
    inOder(root->right);
}
void postOrder(Node* root) {
    if (root==NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
void levelOrder(Node* root) {
    if (root==NULL) {
        return;
    }
    Queue* queue = createQueue(10);
    enqueue(queue,root);
    while (!isEmpty(queue)) {
        Node* current=dequeue(queue);
        printf("%d ", current->data);
        if (current->left!=NULL) {
            enqueue(queue,current->left);
        }
        if (current->right!=NULL) {
            enqueue(queue,current->right);
        }
    }
}
int main() {
    Node* root = NULL;
    root = createNode(2);
    Node* node1=createNode(3);
    Node* node2=createNode(4);
    Node* node3=createNode(5);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    printf("PreOrder:\n");
    preOrder(root);
    printf("\n");
    printf("InOrder:\n");
    inOder(root);
    printf("\n");
    printf("PostOrder:\n");
    postOrder(root);
    printf("\n");
    printf("LevelOrder:\n");
    levelOrder(root);
    free(root);
    return 0;
}