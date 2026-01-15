#include <iostream>
using namespace std;

#define MAX 12

int main() {
    int n = 11;
    int a[MAX][MAX] = {0};

    a[1][8] = a[8][1] = 1;
    a[1][4] = a[4][1] = 1;
    a[1][10] = a[10][1] = 1;
    a[1][9] = a[9][1] = 1;
    a[1][2] = a[2][1] = 1;

    a[2][11] = a[11][2] = 1;
    a[2][3]  = a[3][2]  = 1;

    a[9][5] = a[5][9] = 1;
    a[9][7] = a[7][9] = 1;

    a[5][6] = a[6][5] = 1;

    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    visited[1] = 1;
    queue[rear++] = 1;

    while (front < rear) {
        int u = queue[front++];
        cout << u << " ";

        for (int v = n; v >= 1; v--) {
            if (a[u][v] == 1 && visited[v] == 0) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    return 0;
}

