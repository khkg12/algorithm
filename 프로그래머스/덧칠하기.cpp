#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int m, vector<int> section) {
int answer = 0;
int dis = 0;

    for(int i = 0; i < section.size(); i++){
        if(dis >= section[i]) continue;
        answer++;
        dis = section[i] + m - 1;
    }
    return answer;

}
