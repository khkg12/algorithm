#include<vector>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool check[101][101] = {0};
int dist[101][101] = {0};

int solution(vector<vector<int>> maps)
{
queue<pair<int, int>> q;
q.push(make_pair(0, 0));
dist[0][0] = 1;
check[0][0] = true;
int N = maps.size(); // 행사이즈
int M = maps[0].size(); // 열사이즈 범위

    while(!q.empty()){
        pair<int, int> x;
        x = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){ // 동서남북 방향 기준으로 이용가능한 경로인지 확인하는 루프문
            int curX = x.first + dx[i];
            int curY = x.second + dy[i];

            if(curX < 0 || curX >= N || curY < 0 || curY >= M) continue; // 범위를 벗어나는 경우
            if(maps[curX][curY] == 0) continue; // 경로가 벽인경우
            if(check[curX][curY]) continue; // 이미 체크된 경로인경우

            q.push(make_pair(curX, curY)); // 위의 경우가 다 해당되지 않는 경우 사용가능한 경로
            check[curX][curY] = true;
            dist[curX][curY] = dist[x.first][x.second] + 1; // 해당하는 경로의 최단경로는 그전까지의 경로 + 1
        }
    }

    if(!check[N-1][M-1]) return -1;
    else{
        return dist[N-1][M-1];
    }

}
