#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int solution(int k, vector<int> tangerine) {  
 int answer = 0;  
 int index = 0;
vector<int> Count; // 공간 0임 = [] -> Count[index] -> 없어서 에러 떠
//1. Count.push_back(1) -> [1]
//2. vector<int> Count(5) -> [0, 0, 0, 0, 0] -> Count.push_back(1) -> [1]
// [0, 0, 0, 0, 0, 1]
sort(tangerine.begin(), tangerine.end());
// (5, 5, 4, 3, 3, 2, 2, 1)
// sort(tangerine.begin(), tangerine.end())
// -> [1, 2, 2, 3, 3, 4, 5, 5]
int tmp = 1; // 같은 숫자 카운팅 변수
for(int i = 1; i < tangerine.size(); i++){
if(tangerine[i] != tangerine[i-1]){
//같은 숫자가 끝났다는 거
Count.push_back(tmp);
//각 숫자가 카운팅 된 걸 넣는 순간 ?
// i = 1 (ta = 5)
// i = 2 (ta = 4) -> if -> Count = [2]
// i = 7 (ta = 1) -> if -> Count = [2, 1, 2, 2]
tmp = 1;
}
else{
tmp++;  
 }
}

    //맨 마지막 값은 push back 처리 해줘야 함
    Count.push_back(tmp);



    sort(Count.begin(), Count.end(), greater<int>());

    // for(int i=0; i<Count.size(); i++) {
    //     cout<<Count[i]<<" ";
    // }
    // k = 6, Count = [2, 2, 2, 1, 1] -> answer = 5
    for(int i =0; i < Count.size(); i++){
        if(k - Count[i] > 0){
            answer += 1;
            k = k - Count[i];
        }
        else{
            answer += 1;
            break;
        }
    }
    return answer;
    }
