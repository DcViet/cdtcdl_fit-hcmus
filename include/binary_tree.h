#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>

typedef struct Node {
    char word[100];
    char meaning[512];
    struct Node* left;
    struct Node* right;
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

// Hàm in ra các từ chứa ký tự
void printWordsContainingChar(Node* root, char character);

#endif 
