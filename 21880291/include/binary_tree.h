#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>

// Cấu trúc của một nút trong cây
typedef struct Node {
    char* word;         // Từ
    char* meaning;      // Nghĩa của từ
    struct Node* left;  // Con trái
    struct Node* right; // Con phải
} Node;

// Hàm tạo node mới
Node* createNode(const char* word, const char* meaning);

// Hàm chèn node vào cây
Node* insert(Node* root, const char* word, const char* meaning);

// Hàm tìm kiếm nghĩa của từ
const char* search(Node* root, const char* word);

// Hàm giải phóng bộ nhớ cây
void freeTree(Node* root);

// Hàm xử lý từ điển từ file
void processDictionary(Node** root, const char* filename);

// Hàm xử lý tất cả từ điển
void processAllDictionaries(Node** root);

#endif 
