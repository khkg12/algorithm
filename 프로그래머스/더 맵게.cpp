#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> s, int k) {
int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq(s.begin(), s.end());

    while(pq.top() < k && pq.size() > 1){
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();
        int sum = f + s * 2;
        pq.push(sum);
        answer++;
    }

    if(pq.top() < k) return -1;
    return answer;

}
