#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
int answer = -1;

    sort(dungeons.begin(), dungeons.end());

    while(next_permutation(dungeons.begin(), dungeons.end())){
        int cnt = 0;
        int now_k = k;
        for(int i = 0; i < dungeons.size(); i++){
            if(now_k >= dungeons[i][0]){
                now_k -= dungeons[i][1];
                cnt++;
            }
            else{
                break;
            }
            answer = max(cnt, answer);
        }
    }


    return answer;

}
