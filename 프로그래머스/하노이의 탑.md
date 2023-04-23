#include <string>
#include <vector>

using namespace std;

void hanoi(vector<vector<int>>& answer, int n, int start, int next){
    if(n == 1){
        answer.push_back({start, next});
        return;
    }
    hanoi(answer, n-1, start, 6 - start - next);
    answer.push_back({start, next}); // 위에서 옮기려는 위치가 아닌 곳에 n-1개를 옮긴 뒤 마지막 원판을 옮기려는 위치로 이동
    hanoi(answer, n-1, 6 - start - next, next);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(answer, n, 1, 3);
    return answer;
}