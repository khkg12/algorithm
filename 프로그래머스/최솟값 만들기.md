#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
int answer = 0;
int min = INT_MAX;
sort(A.begin(), A.end());
sort(B.rbegin(), B.rend());
for(int i = 0; i < A.size(); i++){
answer += A[i] \* B[i];
}

    return answer;

}
