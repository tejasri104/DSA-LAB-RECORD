#include <stdio.h>

int n, adj[20][20], visited[20];

void dfs(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

void bfs(int start) {
    int q[20], front = 0, rear = 0;
    int i, v;

    visited[start] = 1;
    q[rear++] = start;

    while (front < rear) {
        v = q[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                q[rear++] = i;
            }
        }
    }
}

int main() {
    int i, j, start;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    scanf("%d", &start);

    for (i = 0; i < n; i++) visited[i] = 0;
    dfs(start);
    printf("\n");

    for (i = 0; i < n; i++) visited[i] = 0;
    bfs(start);

    return 0;
}
