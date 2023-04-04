#include <string>
#include <vector>
#include <iostream>

using namespace std;
int arr[110][110];
int Min(int a, int b) {return a < b ? a : b;}

int rotate(int x, int y, int xx, int yy){
int temp = arr[x][y];
int Min_num = temp;
for(int i = x; i < xx; i++){
Min_num = Min(Min_num, arr[i][y]);
arr[i][y] = arr[i+1][y];
}
for(int i = y; i < yy; i++){
Min_num = Min(Min_num, arr[xx][i]);
arr[xx][i] = arr[xx][i+1];
}
for(int i = xx; i > x; i--){
Min_num = Min(Min_num, arr[i][yy]);
arr[i][yy] = arr[i-1][yy];
}
for(int i = yy; i > y; i--){
Min_num = Min(Min_num, arr[x][i]);
arr[x][i] = arr[x][i-1];
}
arr[x][y + 1] = temp;
return Min_num;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
vector<int> answer;  
 int num = 1;
for(int i = 0; i < rows; i++){
for(int j = 0; j < columns; j++){
arr[i][j] = num++;
}
}

    for(int i = 0; i < queries.size(); i++){
        int x = queries[i][0]; x--;
        int y = queries[i][1]; y--;
        int xx = queries[i][2]; xx--;
        int yy = queries[i][3]; yy--;
        answer.push_back(rotate(x, y, xx, yy));
    }

    return answer;

}
