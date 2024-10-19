#ifndef QUEUE_H
#define QUEUE_H

#include "binary_tree.h"

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Hàm tạo hàng đợi
Queue* createQueue();

// Hàm thêm node vào hàng đợi
void enqueue(Queue* queue, Node* treeNode);

// Hàm gỡ node ra khỏi hàng đợi
Node* dequeue(Queue* queue);

// Hàm kiểm tra xem hàng đợi có rỗng không
int isEmpty(Queue* queue);

#endif
