#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

pair<int, int> d[4] = {{1,0},{-1,0},{0,1},{0,-1}};

int bfs(vector<string> m, char start, char end){
    bool check[101][101] = {false,};
    queue<pair<int, int>> q;
    
    for(int i = 0; i < m.size(); i++){ 
        for(int j = 0; j < m[0].size(); j++){
            if(m[i][j] == start){
                q.push({i,j});                                            
                break;
            } 
        }
    }
    int dist[101][101] = {0,};
    int a, b;
    while(!q.empty()){
        a = q.front().first, b = q.front().second;        
        q.pop();        
        check[a][b] = true;
        for(int i = 0; i < 4; i++){
            int aa = a + d[i].first, bb = b + d[i].second;            
            if((aa >= 0 && aa < m.size()) && (bb >= 0 && bb < m[0].size())){                                
                if(m[aa][bb] == end){ // 검색중인 값이 도착지라면                    
                    dist[aa][bb] = dist[a][b] + 1;
                    return dist[aa][bb];
                }
                else if(m[aa][bb] != 'X' && check[aa][bb] == false){
                    q.push({aa, bb});
                    check[aa][bb] = true;    
                    dist[aa][bb] = dist[a][b] + 1;
                }
            }            
        }                
    }    
    return 0;
}

int solution(vector<string> m) {    
    int a = bfs(m, 'S', 'L');
    int b = bfs(m, 'L', 'E');
    if(a == 0 || b == 0) return -1; 
    return a + b;            
}