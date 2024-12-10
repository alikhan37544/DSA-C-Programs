#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// A queue node to store a word and its transformation level
typedef struct QueueNode {
    char* word;
    int level;
    struct QueueNode* next;
} QueueNode;

// Function to create a new queue node
QueueNode* createQueueNode(char* word, int level) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->word = strdup(word); // Duplicate the word to ensure it's safely stored
    node->level = level;
    node->next = NULL;
    return node;
}

// Function to free a queue node
void freeQueueNode(QueueNode* node) {
    if (node) {
        free(node->word); // Free the duplicated word
        free(node);       // Free the node itself
    }
}

// Function to push a word into the queue
void enqueue(QueueNode** front, QueueNode** rear, char* word, int level) {
    QueueNode* node = createQueueNode(word, level);
    if (*rear) {
        (*rear)->next = node;
    } else {
        *front = node;
    }
    *rear = node;
}

// Function to pop a word from the queue
QueueNode* dequeue(QueueNode** front) {
    if (!*front) return NULL;
    QueueNode* node = *front;
    *front = (*front)->next;
    return node;
}

// Function to check if two words differ by exactly one character
bool differByOneChar(char* word1, char* word2) {
    int diffCount = 0;
    for (int i = 0; word1[i] != '\0'; i++) {
        if (word1[i] != word2[i]) {
            diffCount++;
            if (diffCount > 1) return false;
        }
    }
    return diffCount == 1;
}

// Function to find the shortest transformation sequence
int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    // Check if endWord is in the wordList
    bool endWordInList = false;
    for (int i = 0; i < wordListSize; i++) {
        if (strcmp(wordList[i], endWord) == 0) {
            endWordInList = true;
            break;
        }
    }
    if (!endWordInList) return 0;

    // Visited array to track words already used in the transformation
    bool* visited = (bool*)calloc(wordListSize, sizeof(bool));

    // BFS queue
    QueueNode* front = NULL;
    QueueNode* rear = NULL;

    // Start BFS with the beginWord
    enqueue(&front, &rear, beginWord, 1);

    while (front) {
        QueueNode* currentNode = dequeue(&front);
        char* currentWord = currentNode->word;
        int currentLevel = currentNode->level;

        // Check adjacent words
        for (int i = 0; i < wordListSize; i++) {
            if (!visited[i] && differByOneChar(currentWord, wordList[i])) {
                // If the endWord is found, return the current level + 1
                if (strcmp(wordList[i], endWord) == 0) {
                    freeQueueNode(currentNode);
                    free(visited);
                    return currentLevel + 1;
                }

                // Otherwise, add the word to the queue and mark it as visited
                visited[i] = true;
                enqueue(&front, &rear, wordList[i], currentLevel + 1);
            }
        }

        freeQueueNode(currentNode); // Free the memory of the dequeued node
    }

    free(visited); // Free the visited array
    return 0; // No transformation sequence found
}

int main() {
    // Example 1
    char* wordList1[] = {"hot", "dot", "dog", "lot", "log", "cog"};
    int wordListSize1 = sizeof(wordList1) / sizeof(wordList1[0]);
    printf("Output for Example 1: %d\n", ladderLength("hit", "cog", wordList1, wordListSize1));

    // Example 2
    char* wordList2[] = {"hot", "dot", "dog", "lot", "log"};
    int wordListSize2 = sizeof(wordList2) / sizeof(wordList2[0]);
    printf("Output for Example 2: %d\n", ladderLength("hit", "cog", wordList2, wordListSize2));

    return 0;
}
