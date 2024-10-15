#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Hàm tạo hàng đợi
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Hàm thêm node vào hàng đợi
void enqueue(Queue* queue, Node* treeNode) {
    QueueNode* newQueueNode = (QueueNode*)malloc(sizeof(QueueNode));
    newQueueNode->treeNode = treeNode;
    newQueueNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newQueueNode;
        return;
    }
    
    queue->rear->next = newQueueNode;
    queue->rear = newQueueNode;
}

// Hàm gỡ node ra khỏi hàng đợi
Node* dequeue(Queue* queue) {
    if (queue->front == NULL) return NULL;

    QueueNode* temp = queue->front;
    Node* treeNode = temp->treeNode;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return treeNode;
}

// Hàm kiểm tra xem hàng đợi có rỗng không
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}
