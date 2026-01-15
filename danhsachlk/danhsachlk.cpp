#include <iostream>
using namespace std;

#define MAX 12

int adj[MAX][MAX] = { 0 };
int deg[MAX] = { 0 };

void addEdge(int u, int v) {
    adj[u][deg[u]++] = v;
    adj[v][deg[v]++] = u;
}

int main() {
    int n = 11;

    addEdge(1, 8);
    addEdge(1, 4);
    addEdge(1, 10);
    addEdge(1, 9);
    addEdge(1, 2);

    addEdge(2, 11);
    addEdge(2, 3);

    addEdge(9, 5);
    addEdge(9, 7);

    addEdge(5, 6);

    int visited[MAX] = { 0 };
    int queue[MAX];
    int front = 0, rear = 0;

    visited[1] = 1;
    queue[rear++] = 1;

    while (front < rear) {
        int u = queue[front++];
        cout << u << " ";

        for (int i = 0; i < deg[u]; i++) {
            for (int j = i + 1; j < deg[u]; j++) {
                if (adj[u][i] < adj[u][j]) {
                    int t = adj[u][i];
                    adj[u][i] = adj[u][j];
                    adj[u][j] = t;
                }
            }
        }

        for (int i = 0; i < deg[u]; i++) {
            int v = adj[u][i];
            if (visited[v] == 0) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    return 0;
}
