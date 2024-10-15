#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main() {
    Node* root = NULL;

    // Xử lý tất cả các file từ điển
    processAllDictionaries(&root);

    // Nhập từ từ người dùng
    char word[100];
    printf("Nhap tu de tra cuu: ");
    scanf("%s", word);

    // Tìm nghĩa của từ
    const char* meaning = search(root, word);
    if (meaning != NULL) {
        printf("Nghia cua tu '%s': %s\n", word, meaning);
    } else {
        printf("Khong tim thay tu '%s' trong tu dien.\n", word);

        // Gợi ý các từ chứa ký tự trong từ người dùng nhập
        char character = word[0]; // Gợi ý từ ký tự đầu tiên của từ
        printf("Cac tu chua ky tu '%c':\n", character);
        printWordsContainingChar(root, character);
    }

    // Giải phóng bộ nhớ
    freeTree(root);
    return 0;
}
