#include <string>
#include <vector>

using namespace std;

vector<int> v[101];

int dfs(int next, int now, int sum){ // next는 분단될 노드, 즉 예시의 4와 7에서 4
for(int i = 0; i < v[now].size(); i++){
if(v[now][i] != next){
sum = dfs(now, v[now][i], sum+1); // 다음 조건 : sum은 카운트 개념으로 1더해주고 이제는 next는 그전의 now가 됨
}
}
return sum;
}

int solution(int n, vector<vector<int>> wires) {
int answer = 1000;

    for(auto w : wires){ // v에 간선정보 저장
        v[w[0]].push_back(w[1]);
        v[w[1]].push_back(w[0]);
    }

    for(auto w : wires){
        int a = dfs(w[0], w[1], 1);
        int b = n - a;
        answer = min(answer, abs(a - b));
    }

    return answer;

}
