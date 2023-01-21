#include<bits/stdc++.h>
 
#define fi first
#define se second
#define make_pair mp
using namespace std;
 
int test;
int n;
int type, r, c;
int matrix[105][105];
 
 
 
// first = y-axes, second = x-axes
int moving[10][50] = {
                        { 0, 0 },
                        { 0, 0, 0, 1 },
                        { 0, 0, 1, 0 },
                        { 0, 0, 0, 1, 1, -1 },
                        { 0, 0, 0, 1, 1, 0 },
                        { 0, 0, 1, 0, 0, 1 },
                        { 0, 0, 1, 0, 0, 1, -1, 0 },
                        { 0, 0, 1, 0, 1, 0, 0, 1, -1, 0, -1, 0, 0, 1, 1, 0, 1, 0 }
                    };
 
int len_moving[10] = { 1, 2, 2, 3, 3, 3, 4, 9};
 
int update_score_and_clear(int tmp_matrix[105][105]) {
    int score = 0;
    vector<int> full_column;
    vector<int> full_row;
 
    // check full row
    for(int i = 0;i < 8;i++) {
        bool check = true;
        for(int j = 0;j < 8;j++)
            if(tmp_matrix[i][j] == 0)
                check = false;
 
        if(check) {
            full_row.push_back(i);
            score = score + 1;
        }
    }
 
    // check full column
    for(int j = 0;j < 8;j++) {
        bool  check = true;
        for(int i = 0;i < 8;i++)
            if(tmp_matrix[i][j] == 0)
                check = false;
 
        if(check) {
            full_column.push_back(j);
            score = score + 1;
        }
    }
 
    // clear full row
    for(int it = 0;it < full_row.size();it++) {
        int row = full_row[it];
        for(int j = 0;j < 8;j++)
            tmp_matrix[row][j] = 0;
    }
 
    // clear full column
    for(int it = 0;it < full_column.size();it++) {
        int column = full_column[it];
        for(int i = 0;i < 8;i++)
            tmp_matrix[i][column] = 0;
    }
 
    return score;
}
 
void place_tile(int type, int cur_row, int cur_column, int tmp_matrix[105][105]) {
    for(int it = 0;it < len_moving[type-1];it++) {
        cur_row = cur_row + moving[type-1][it*2];
        cur_column = cur_column + moving[type-1][it*2+1];
 
        tmp_matrix[cur_row][cur_column] = 1;
    }
}
 
bool check_matrix(int type, int cur_row, int cur_column, int tmp_matrix[105][105]) {
    for(int it = 0;it < len_moving[type-1];it++) {
        cur_row = cur_row + moving[type-1][it*2];
        cur_column = cur_column + moving[type-1][it*2+1];
 
        if(tmp_matrix[cur_row][cur_column] == 1)
            return false;
 
        if(cur_column < 0 || cur_column > 7 || cur_row < 0 || cur_row > 7)
            return false;
 
    }
 
    return true;
}
 
int main() {
    
    freopen("input.txt", "r", stdin);
 
    cin >> test;
    for(int t = 1;t <= test;t++) {
        cin >> n;
 
        for(int i = 0;i < 8;i++)
            for(int j = 0;j < 8;j++)
                cin >> matrix[i][j];
 
 
 
        int total_score = 0;
        total_score = total_score + update_score_and_clear(matrix);
 
        for(int it = 0;it < n;it++) {
            cin >> type >> r >> c;
 
            if(check_matrix(type, r, c, matrix)) {
                place_tile(type, r, c, matrix);
                total_score = total_score + update_score_and_clear(matrix);
 
            }
           // cout << "Tile " << it << ' ' << type << ' ' << r << ' ' << c << endl;
          /*  for(int i = 0;i < 8;i++) {
                for(int j = 0;j < 8;j++)
                    cout << matrix[i][j] << ' ';
                cout << endl;
            }*/
        }
 
        cout << "#" << t << ' ' << total_score << endl;
    }
    return 0;
}