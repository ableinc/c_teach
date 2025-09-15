#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
char* multiplyStrings(char*, char*);
int traverseLinkedList(struct Node *, int);

struct Node {
    int value;
    struct Node *next;
};

int main(int argc, char** argv) {
    // Leetcode #1
    char* num1 = argv[1];
    char* num2 = argv[2];
    char* result = multiplyStrings(num1, num2);
    printf("Result: %s\n", result);
    free(result);
    // Leetcode #2
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    head->value = 1;
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    second->value = head->value * 5;
    second->next = NULL;
    head->next = second;
    int value = traverseLinkedList(head, 5);
    if (value != NULL) {
        printf("Found value in linked list: %d", value);
    }
    return 0;
}

/**
 * Given two non-negative integers num1 and num2 represented as strings,
 * return the product of num1 and num2, also represented as a string.
 */
char* multiplyStrings(char* num1, char* num2) {
    // Calculate the maximum possible length of the result
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = len1 + len2;

    // Allocate memory for the result
    char* output = (char*)malloc(maxLen + 1);
    if (!output) {
        return NULL; // Handle memory allocation failure
    }
    
    // Initialize the result array with zeros
    for (int i = 0; i < maxLen; i++) {
        output[i] = '0';
    }
    output[maxLen] = '\0';

    // Perform multiplication digit by digit
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + (output[i + j + 1] - '0');

            output[i + j + 1] = sum % 10 + '0';
            output[i + j] += sum / 10;
        }
    }

    // Remove leading zeros
    int startIndex = 0;
    while (startIndex < maxLen - 1 && output[startIndex] == '0') {
        startIndex++;
    }

    // Return the result string starting from the first non-zero digit
    char* result = strdup(output + startIndex);
    free(output);

    return result;
}

int traverseLinkedList(struct Node *head, int value) {
    struct Node *current = head;
    while (current != NULL) {
        // printf("%d\n", current->value);
        if (current->value == value) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}
