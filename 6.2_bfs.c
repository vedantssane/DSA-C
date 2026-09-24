#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];

int front = -1, rear = -1;
int n;

void enqueue(int value)
{
    if (rear == MAX - 1)
        return;

    if (front == -1)
        front = 0;

    queue[++rear] = value;
}

int dequeue()
{
    if (front == -1 || front > rear)
        return -1;

    return queue[front++];
}

void BFS(int start)
{
    int i, vertex;

    visited[start] = 1;
    enqueue(start);

    while (front != -1 && front <= rear)
    {
        vertex = dequeue();

        printf("%d ", vertex);

        for (i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");

    BFS(start);

    return 0;
}