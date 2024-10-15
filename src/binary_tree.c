#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"
#include "queue.h"

// Hàm tạo node mới
Node* createNode(const char* word, const char* meaning) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm chèn node vào cây
Node* insert(Node* root, const char* word, const char* meaning) {
    if (root == NULL) {
        return createNode(word, meaning);
    }
    
    if (strcmp(word, root->word) < 0) {
        root->left = insert(root->left, word, meaning);
    } else if (strcmp(word, root->word) > 0) {
        root->right = insert(root->right, word, meaning);
    }
    return root;
}

// Hàm tìm kiếm nghĩa của từ
const char* search(Node* root, const char* word) {
    if (root == NULL) {
        return NULL;
    }
    
    if (strcmp(word, root->word) == 0) {
        return root->meaning;
    } else if (strcmp(word, root->word) < 0) {
        return search(root->left, word);
    } else {
        return search(root->right, word);
    }
}

// Hàm giải phóng bộ nhớ cây
void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Hàm xử lý từ điển từ file
void processDictionary(Node** root, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char word[100], meaning[512];

        if (strstr(line, "<P>") != NULL) {
            while (fgets(line, sizeof(line), file) && strstr(line, "</P>") == NULL) {
                if (sscanf(line, "<B>%[^<]</B> (<I>%*[^<]</I>) %[^\n]", word, meaning) == 2) {
                    *root = insert(*root, word, meaning);
                }
            }
        }
    }
    fclose(file);
}

// Hàm xử lý tất cả từ điển
void processAllDictionaries(Node** root) {
    for (char letter = 'A'; letter <= 'Z'; letter++) {
        char filename[50];
        sprintf(filename, "fileOPTED/%c.html", letter);
        processDictionary(root, filename);
    }
}

// Hàm in ra các từ chứa ký tự
void printWordsContainingChar(Node* root, char character) {
    if (root == NULL) return;

    Queue* queue = createQueue(); // Khởi tạo hàng đợi
    enqueue(queue, root); // Thêm nút gốc vào hàng đợi

    while (!isEmpty(queue)) { // Trong khi hàng đợi không rỗng
        Node* current = dequeue(queue); // Lấy nút ra từ hàng đợi
        
        // Kiểm tra xem từ có chứa ký tự không
        if (strchr(current->word, character) != NULL) {
            printf("Word: %s, Meaning: %s\n", current->word, current->meaning);
        }

        // Thêm các nút con vào hàng đợi
        if (current->left != NULL) {
            enqueue(queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(queue, current->right);
        }
    }

    free(queue); // Giải phóng bộ nhớ cho hàng đợi
}

