// Implementing BFS in graphs


#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int graph[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE];
int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue more elements.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = vertex;
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        int vertex = queue[front++];
        if (front > rear) {
            front = rear = -1;
        }
        return vertex;
    }
}

void bfs(int start, int vertices) {
    visited[start] = true;
    printf("BFS Traversal: %d ", start);
    enqueue(start);
    while (front != -1) {
        int current = dequeue();
        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                printf("%d ", i);
                enqueue(i);
            }
        }
    }
}

int main() {
    int vertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int start;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);
    bfs(start, vertices);
    printf("\n");
    return 0;
}
