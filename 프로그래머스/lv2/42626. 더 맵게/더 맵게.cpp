#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> s, int K) {
    int answer = 0;    
    priority_queue<int, vector<int>, greater<int>> q;
    
    for(int i = 0; i < s.size(); i++){
        q.push(s[i]);
    }
   
    while(q.top() < K && q.size() > 1){
        int f = q.top();
        q.pop();
        int s = q.top();
        q.pop();
        double x = f + s * 2;
        q.push(x);  
        answer++;
    }
    
    if(q.top() < K) return -1;
   
    
    return answer;
}