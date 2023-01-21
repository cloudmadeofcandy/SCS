#include <stdio.h>

#define MAX_SIZE 105
#define MAX_LEN 305

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int m, n, T;
int matrix[MAX_SIZE][MAX_SIZE];
char pacman[MAX_LEN], ghost[MAX_LEN];

int dir_pacman, dir_ghost;
long long gold_pacman, gold_ghost;

void input()
{
    scanf("%d %d ", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d ", &matrix[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%c ", &pacman[i]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%c ", &ghost[i]);
    }
}

int turn_left(int x)
{
    return (x + 3) % 4;
}

int turn_right(int x)
{
    return (x + 1) % 4;
}

void solve()
{
    dir_pacman = 3;
    dir_ghost = 1;
    gold_pacman = 0;
    gold_ghost = 0;
    int tx_pacman, ty_pacman;
    int tx_ghost, ty_ghost;
    tx_pacman = 0;
    ty_pacman = 0;
    tx_ghost = n - 1;
    ty_ghost = n - 1;
    int i;
    for (i = 0; i < m; i++)
    {
        if (pacman[i] == 'C')
        {
            tx_pacman = tx_pacman + dx[dir_pacman];
            ty_pacman = ty_pacman + dy[dir_pacman];
        }
        else if (pacman[i] == 'L')
        {
            dir_pacman = turn_left(dir_pacman);
            tx_pacman = tx_pacman + dx[dir_pacman];
            ty_pacman = ty_pacman + dy[dir_pacman];
        }
        else if (pacman[i] == 'R')
        {
            dir_pacman = turn_right(dir_pacman);
            tx_pacman = tx_pacman + dx[dir_pacman];
            ty_pacman = ty_pacman + dy[dir_pacman];
        }


        if (ghost[i] == 'C')
        {
            tx_ghost = tx_ghost + dx[dir_ghost];
            ty_ghost = ty_ghost + dy[dir_ghost];
        }
        else if (ghost[i] == 'L')
        {
            dir_ghost = turn_left(dir_ghost);
            tx_ghost = tx_ghost + dx[dir_ghost];
            ty_ghost = ty_ghost + dy[dir_ghost];
        }
        else if (ghost[i] == 'R')
        {
            dir_ghost = turn_right(dir_ghost);
            tx_ghost = tx_ghost + dx[dir_ghost];
            ty_ghost = ty_ghost + dy[dir_ghost];
        }

        if (tx_pacman == tx_ghost && ty_pacman == ty_ghost)
        {
            break;
        }
        else
        {
            gold_pacman += matrix[tx_pacman][ty_pacman];
            matrix[tx_pacman][ty_pacman] = 0;
            gold_ghost += matrix[tx_ghost][ty_ghost];
            matrix[tx_pacman][ty_pacman] = 0;
        }
    }
}

void output(int tc) {
    printf("#%d %lld %lld\n", tc, gold_pacman, gold_ghost);
}

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    scanf("%d ", &T);
    for (t = 1; t <= T; ++t) {
        input();
        solve();
        output(t);
    }
    return 0;
}