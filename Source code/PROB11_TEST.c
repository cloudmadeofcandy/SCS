#include <iostream>
 
#define MAX_SIZE 2005
#define MAX_K 100005
 
using namespace std;
 
int n, m, k;
int matrix[MAX_SIZE][MAX_SIZE];
int matrix2[MAX_SIZE][MAX_SIZE];
int cmd[MAX_K][3];
 
void input() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        cin >> cmd[i][0] >> cmd[i][1];
    }
}
 
void moveDown(int x) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int z = (i - x + n) % n;
            matrix2[i][j] = matrix[z][j];
        }
    }
}
 
void moveUp(int x) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int z = (i + x + n) % n;
            matrix2[i][j] = matrix[z][j];
        }
    }
}
 
void moveLeft(int x) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int z = (j + x + m) % m;
            matrix2[i][j] = matrix[i][z];
        }
    }
}
 
void moveRight(int x) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int z = (j - x + m) % m;
            matrix2[i][j] = matrix[i][z];
        }
    }
}
 
int calc() {
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            int sum = matrix2[i][j] + matrix2[i][j + 1] + matrix2[i + 1][j] + matrix2[i + 1][j + 1];
            if (sum % 4 == 0) {
                cnt++;
            }
        }
    }
    return cnt;
}
 
void solve() {
    for (int i = 0; i < k; i++) {
        switch (cmd[i][0]) {
            case 1:
                moveDown(cmd[i][1]);
                break;
            case 2:
                moveRight(cmd[i][1]);
                break;
            case 3:
                moveUp(cmd[i][1]);
                break;
            case 4:
                moveLeft(cmd[i][1]);
                break;
        }
        cmd[i][2] = calc();
    }
}
 
void output(int n) {
    cout << "#" << n << " ";
    for (int i = 0; i < k; ++i) {
        cout << cmd[i][2] << " ";
    }
    cout << endl;
}
 
int main() {
    int test;
    cin >> test;
    for (int i = 1; i <= test; i++) {
        input();
        solve();
        output(i);
    }
    return 0;
}