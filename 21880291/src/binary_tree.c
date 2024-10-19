#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"
#include "queue.h"
#include <ctype.h>

// Hàm tạo node mới
Node *createNode(const char *word, const char *meaning)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->word = strdup(word);
    newNode->meaning = strdup(meaning);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm chèn node vào cây
Node* insert(Node* root, const char* word, const char* meaning) {
    if (root == NULL) {
        // Tạo node mới với từ đã chuyển sang chữ thường
        char* lowerWord = (char*)malloc(strlen(word) + 1);
        for (int i = 0; word[i]; i++) {
            lowerWord[i] = tolower(word[i]);
        }
        lowerWord[strlen(word)] = '\0'; 
        return createNode(lowerWord, meaning);
    }

    // So sánh với từ đã chuyển sang chữ thường
    char lowerNodeWord[100];
    for (int i = 0; root->word[i]; i++) {
        lowerNodeWord[i] = tolower(root->word[i]);
    }
    lowerNodeWord[strlen(root->word)] = '\0'; 

    char* lowerWord = (char*)malloc(strlen(word) + 1); 
    for (int i = 0; word[i]; i++) {
        lowerWord[i] = tolower(word[i]);
    }
    lowerWord[strlen(word)] = '\0';

    int cmp = strcmp(lowerWord, lowerNodeWord);
    if (cmp < 0) {
        root->left = insert(root->left, word, meaning);
    } else if (cmp > 0) {
        root->right = insert(root->right, word, meaning);
    } else {
       
        size_t newMeaningLength = strlen(root->meaning) + strlen(meaning) + 3;
        char* updatedMeaning = (char*)malloc(newMeaningLength);
        snprintf(updatedMeaning, newMeaningLength, "%s; %s", root->meaning, meaning);

        free(root->meaning); 
        root->meaning = updatedMeaning; 
    }

    free(lowerWord);
    return root;
}

// Hàm tìm kiếm nghĩa của từ
const char *search(Node *root, const char *word)
{
    if (root == NULL)
    {
        return NULL;
    }

    // Chuyển đổi từ tìm kiếm sang chữ thường
    char lowerWord[100];
    for (int i = 0; word[i]; i++)
    {
        lowerWord[i] = tolower(word[i]);
    }
    lowerWord[strlen(word)] = '\0';

    // So sánh với từ trong cây
    if (strcmp(lowerWord, root->word) == 0)
    {
        return root->meaning;
    }
    else if (strcmp(lowerWord, root->word) < 0)
    {
        return search(root->left, word);
    }
    else
    {
        return search(root->right, word);
    }
}

// Hàm giải phóng bộ nhớ cây
void freeTree(Node *root)
{
    if (root)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root->word);
        free(root->meaning);
        free(root);
    }
}

// Hàm xử lý từ điển từ file
void processDictionary(Node **root, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Failed to open file");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file))
    {
        char *wordStart = strstr(line, "<B>");
        char *wordEnd = strstr(line, "</B>");
        char *typeStart = strstr(line, "<I>");
        char *typeEnd = strstr(line, "</I>");
        char *meaningStart = typeEnd ? typeEnd + 4 : NULL;
        char *meaningEnd = strstr(line, "</P>");

        if (wordStart && wordEnd && meaningEnd)
        {

            wordStart += 3;
            size_t wordLength = wordEnd - wordStart;

            char word[100];
            strncpy(word, wordStart, wordLength);
            word[wordLength] = '\0';

            char type[50] = "";
            if (typeStart && typeEnd)
            {
                typeStart += 3;
                size_t typeLength = typeEnd - typeStart;
                strncpy(type, typeStart, typeLength);
                type[typeLength] = '\0';
            }

            char meaning[512];
            if (meaningStart && meaningEnd)
            {
                size_t meaningLength = meaningEnd - meaningStart;
                strncpy(meaning, meaningStart, meaningLength);
                meaning[meaningLength] = '\0'; 
            }
            else
            {
                strcpy(meaning, "Nghia khong co");
            }

            char fullMeaning[600];
            snprintf(fullMeaning, sizeof(fullMeaning), "%s: %s", type, meaning);
            *root = insert(*root, word, fullMeaning);
        }
    }
    fclose(file);
}

// Hàm xử lý tất cả từ điển
void processAllDictionaries(Node **root)
{
    for (char letter = 'A'; letter <= 'Z'; letter++)
    {
        char filename[50];
        sprintf(filename, "fileOPTED/%c.html", letter);
        processDictionary(root, filename);
    }
}
