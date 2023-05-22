#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int sum, int index){
if(index == numbers.size()){ // 인덱스를 증가시키면서 결국 넘버즈의 사이즈와 동일하다면종료
if(target == sum) answer++;
return;
}
dfs(numbers, target, sum + numbers[index], index + 1);
dfs(numbers, target, sum - numbers[index], index + 1);
}
// dfs는 종료조건을 우선 생각 -> 다음부분을 재귀로 구현
int solution(vector<int> numbers, int target) {  
 dfs(numbers, target, 0, 0);
return answer;
}
