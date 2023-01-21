//general idea: greedy algorithm.
//implementation: define the base case as a single empty space, surrounded by walls or visited space.
//define preferential movements of the algorithm: down > right > left > up
//the algorithm will try to shrink down the room and will count a room as 1 when the base case is reached.

#include<stdio.h>

#define MAX 105
int T, M, N;
char arr[MAX][MAX];
int people = 0; 
int room = 0;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void input() {
    people = 0;
    scanf("%d %d ", &M, &N);

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%c ", &arr[i][j]);
            if (arr[i][j] == '*') {
                people++;
                arr[i][j] = '-';
            }
        }
    }
}

void print() {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    printf("ROOM: %d\n", room);
}

int isOutOfMatrix(int x, int y) {
    if (x < 0 || x >= M || y < 0 || y >= N) {
        return 1;
    }
    return 0;
}

void DFS(int x, int y) {
    int i, j;
    int tx, ty;

    arr[x][y] = '#';

    for (i = 0; i < 4; i++) {
        tx = x + dx[i];
        ty = y + dy[i];


        if (!isOutOfMatrix(tx, ty) && arr[tx][ty] != '#') {
            DFS(tx, ty);
        }
    }
}

void solve() {
    room = 0;
    int i, j;
    for (i = 0; i < M; ++i) {
        for (j = 0; j < N; j++) {
            if (arr[i][j] != '#') {
                room++;
                DFS(i, j);
            }
        }
    }
    printf("%.2f\n", (1.0 * people)/room);
}


int main(void) {

    freopen("input.txt", "r", stdin);

    scanf("%d ", &T);

    for (int t = 0; t < T; ++t) {
        input();
        //print();
        solve();
        //print();
    }
    return 0;
}