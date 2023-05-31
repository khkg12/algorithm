#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
// 이진탐색 문제

bool Binary_search(int mid, vector<int> stones, int k){ // 여기서 mid는 단순히 돌의 숫자가 아닌 사람수를 의미 
    int count = 0;
    for(int i = 0; i < stones.size(); i++){
        if(stones[i] -mid <= 0){
            count++;
        }
        else count = 0;
        if(count >= k) return true;   // 연속된 0의 값이 k보다 크다면, 즉 강을 건널수 없다면, 즉 사람의 수가 이미 최대값
    }
    return false; 
}

int solution(vector<int> stones, int k) {
    int answer = 0; 
    int start = *min_element(stones.begin(), stones.end()); // 이진탐색은 정렬후 사용해야함, 따라서 시작과 끝 설정
    int end = *max_element(stones.begin(), stones.end()); // max_element는 인덱스를 반환하므로 포인터붙여서 값찾음
    int mid;
    
    while(start <= end){ // 이진탐색을 진행하면서 start가 end를 넘어가게 될때 종료되게끔 조건설정
        mid = (start + end) / 2;
        if(Binary_search(mid, stones, k)){
            end = mid - 1; // 건널수 없는 경우이니, mid값을 낮게 측정해야함으로 end값을 낮춰 mid를 낮춤
        }
        else{
            start = mid + 1;
        }
    }
    
    return start;
} 