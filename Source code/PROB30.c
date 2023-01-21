#include <stdio.h>
#include <string.h>

int T, N;

int tabl[8][8];

int bricks[1000][3];

int check_lines()
{
    int clc[8];
    int clr[8];
    int ret = 0;

    for (int i = 0; i < 8; i++)
    {
        clc[i] = 1;
        clr[i] = 1;
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            clr[i] = clr[i] & tabl[i][j];
            clc[i] = clc[i] & tabl[j][i];
        }
    }

    for (int i = 0; i < 8; i++)
    {
        if (clr[i] == 1)
        {
            for (int j = 0; j < 8; j++)
            {
                tabl[i][j] = 0;
            }
            ret++;
        }

        if (clc[i] == 1)
        {
            for (int j = 0; j < 8; j++)
            {
                tabl[j][i] = 0;
            }
            ret++;
        }
    }
    return ret;
}

void input()
{
    memset(tabl, 0, 8 * 8 * 4);
    memset(bricks, 0, 1000 * 3 * 4);
    scanf("%d ", &N);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            scanf("%d ", &tabl[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d ", &bricks[i][0], &bricks[i][1], &bricks[i][2]);
    }
}

void print()
{
    printf("Table:\n");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d ", tabl[i][j]);
        }
        printf("\n");
    }
    printf("Bricks:\n");

    for (int i = 0; i < N; i++)
    {
        printf("%d %d %d\n", bricks[i][0], bricks[i][1], bricks[i][2]);
    }
}

void diag()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d ", tabl[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isOutOfMatrix(int x, int y)
{
    if (x < 0 || x >= 8 || y < 0 || y >= 8)
        return 1;
    else
        return 0;
}

void check_able(int type, int x, int y)
{
    int ap = 0;
    int io = 0;
    switch (type)
    {
    case 1:
    {
        if (!isOutOfMatrix(x, y) && tabl[x][y] == 0)
        {
            tabl[x][y] = 1;
        }
        break;
    }

    case 2:
    {
        if (!isOutOfMatrix(x, y) && !isOutOfMatrix(x, y + 1) && (tabl[x][y] | tabl[x][y + 1]) == 0)
        {
            tabl[x][y] = 1;
            tabl[x][y + 1] = 1;
        }
        break;
    }
    case 3:
    {
        if (!isOutOfMatrix(x, y) && !isOutOfMatrix(x + 1, y) && (tabl[x][y] | tabl[x + 1][y]) == 0)
        {
            tabl[x][y] = 1;
            tabl[x + 1][y] = 1;
        }
        break;
    }

    case 4:
    {
        if (!isOutOfMatrix(x, y) && !isOutOfMatrix(x + 1, y) && !isOutOfMatrix(x, y + 1) && (tabl[x][y] | tabl[x + 1][y] | tabl[x][y + 1]) == 0)
        {
            tabl[x][y] = 1;
            tabl[x + 1][y] = 1;
            tabl[x][y + 1] = 1;
        }
        break;
    }

    case 5:
    {
        if (!isOutOfMatrix(x, y) && !isOutOfMatrix(x + 1, y + 1) && !isOutOfMatrix(x, y + 1) && (tabl[x][y] | tabl[x + 1][y + 1] | tabl[x][y + 1]) == 0)
        {
            tabl[x][y] = 1;
            tabl[x + 1][y + 1] = 1;
            tabl[x][y + 1] = 1;
        }
        break;
    }

    case 6:
    {
        if (!isOutOfMatrix(x, y) && !isOutOfMatrix(x + 1, y) && !isOutOfMatrix(x + 1, y + 1) && (tabl[x][y] | tabl[x + 1][y] | tabl[x + 1][y + 1]) == 0)
        {
            tabl[x][y] = 1;
            tabl[x + 1][y] = 1;
            tabl[x + 1][y + 1] = 1;
        }
        break;
    }

    case 7:
    {
        if (!isOutOfMatrix(x + 1, y) && !isOutOfMatrix(x, y + 1) && !isOutOfMatrix(x + 1, y + 1) && (tabl[x + 1][y] | tabl[x][y + 1] | tabl[x + 1][y + 1]) == 0)
        {
            tabl[x + 1][y] = 1;
            tabl[x][y + 1] = 1;
            tabl[x + 1][y + 1] = 1;
        }
        break;
    }

    case 8:
    {
        ap = 0;
        io = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                ap = ap | tabl[x + i][y + j];
                io = io | isOutOfMatrix(x + i, y + j);
                if (io || ap)
                    break;
            }
            if (io || ap)
                break;
        }
        if (io || ap)
            break;
        else
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    tabl[x + i][y + j] = 1;
                }
            }
            break;
        }
    }

    default:
        break;
    }
}

void solve(int t)
{
    int ret = 0;
    ret += check_lines();
    for (int i = 0; i < N; i++)
    {
        check_able(bricks[i][0], bricks[i][1], bricks[i][2]);
        ret += check_lines();
        // diag();
    }
    printf("#%d %d\n", t, ret);
}

int main()
{
    freopen("input.txt", "r", stdin);

    scanf("%d ", &T);

    for (int i = 0; i < T; i++)
    {
        input();
        // print();
        solve(i + 1);
    }

    return 0;
}