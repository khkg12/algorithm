#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> v[20001];
    queue<int> q;
    int dist[20001] = {0,};
    bool check[20001];    
    
    
    
    for(int i = 0; i < edge.size(); i++){
        v[edge[i][0]].push_back(edge[i][1]);        
        v[edge[i][1]].push_back(edge[i][0]);
    }
    q.push(1);
    check[1] = true;
    while(!q.empty()){
        int x = q.front();        
        
        q.pop();        
        
        for(int i = 0; i < v[x].size(); i++){
            int a = v[x][i];               
            if(check[a] == false){                
                check[a] = true;
                q.push(a);
                dist[a] = dist[x] + 1;                
            }
        }
    }    
    int max = *max_element(begin(dist), end(dist));    
    for(int i = 1; i <= n; i++){
        if(max == dist[i]) answer++;
    }
    
    return answer;
}