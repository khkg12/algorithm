#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check[101][101] = {false,};
int sum = 0;
void dfs(vector<string> maps, int x, int y, int r, int c){
    if(check[x][y] == true || maps[x][y] == 'X') return;
    else{
        check[x][y] = true;
        string s;
        s.push_back(maps[x][y]);
        sum += stoi(s);
        cout << maps[x][y] << " " << sum << " ";
        if(x + 1 < r) dfs(maps, x + 1, y, r, c);
        if(y + 1 < c) dfs(maps, x, y + 1, r, c);
        if(x - 1 >= 0) dfs(maps, x - 1, y, r, c);
        if(y - 1 >= 0) dfs(maps, x, y - 1, r, c);
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int r = maps.size();
    int c = maps[0].size();
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(maps[i][j] != 'X'){
                dfs(maps, i, j, r, c);
                if(sum > 0) answer.push_back(sum);                                
                sum = 0;
            }            
        }
    }
    sort(answer.begin(), answer.end(), less<>());
    
    if(answer.size() == 0) answer.push_back(-1);
    return answer;
}