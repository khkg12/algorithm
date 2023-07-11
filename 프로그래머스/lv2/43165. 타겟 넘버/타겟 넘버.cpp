#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v;
int answer = 0;

void dfs(vector<int> numbers, int cnt, int target, int sum){
    if(cnt == numbers.size()){
        if(sum == target) answer++;
        return;
    }
    
    dfs(numbers, cnt+1, target, sum + numbers[cnt]);
    dfs(numbers, cnt+1, target, sum - numbers[cnt]);
}

int solution(vector<int> numbers, int target) {
    
    
    dfs(numbers, 0, target, 0);
    
    return answer;
}