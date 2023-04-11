#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 다익스트라 알고리즘

vector<pair<int, int>> v[51];
vector<int> dist;

void dijkstra(){
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // 오름차순 정렬
int pos, dis, npos, ndis; // pos는 현재 노드, dis는 현재 누적 가중치, n은 다음
q.push({1, 0});
while(!q.empty()){
pos = q.top().first;
dis = q.top().second;
q.pop();
for(int i = 0; i < v[pos].size(); i++){
npos = v[pos][i].first;
ndis = v[pos][i].second;
if(dist[npos] > dist[pos] + ndis){ // 만약 다음 노드의 가중치값이 현재까지 누적노드 가중치에 다음 노드의 가중치값을 더한것보다 크다면, 즉 현재노드에 연결된 모든 노드를 돌면서 가중치 합이 가장낮은 값을 찾아내는 과정
dist[npos] = dist[pos] + ndis;
q.push({npos, ndis}); // 연결값은 우선순위큐에 저장
}
}
}
}

int solution(int N, vector<vector<int> > road, int K) {
int answer = 0;
dist.resize(N+1,500001);
dist[1] = 0; // 첫번째 노드, 노드 1의 가중치값은 0

    for(int i = 0; i < road.size(); i++){
        int a = road[i][0], b = road[i][1], c = road[i][2];
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    dijkstra();
    for(int i = 1; i < dist.size(); i++){
        if(dist[i] <= K) answer++;
    }

    return answer;

}
