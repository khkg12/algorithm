#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
vector<int> answer;

    for(long long i = left; i < right + 1; i++){
        int a = i / n;
        int b = i % n;

        if(b <= a) answer.push_back(a+1);
        else answer.push_back(b+1);
    }

    return answer;

}
