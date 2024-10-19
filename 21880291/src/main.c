#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"

int main() {
    Node* root = NULL;
    processAllDictionaries(&root);

    // Nhập từ từ người dùng
    char word[100];
    while (1) {
        printf("Nhap tu de tra cuu (hoac '00' de thoat): ");
        fgets(word, sizeof(word), stdin);
        
        // Xóa ký tự xuống dòng nếu có
        word[strcspn(word, "\n")] = '\0';

        if (strcmp(word, "00") == 0) {
            break;
        }

        const char* meaning = search(root, word);
        if (meaning != NULL) {
            printf("Nghia cua tu '%s': %s\n", word, meaning);
        } else {
            printf("Khong tim thay tu '%s' trong tu dien.\n", word);
        }
    }

    // Giải phóng bộ nhớ
    freeTree(root);
    return 0;
}
