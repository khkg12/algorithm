#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
long long answer = 0;
long long arr[n];
arr[0] = 1;
arr[1] = 2;
for(int i = 2; i < n; i++){
arr[i] = (arr[i-1] + arr[i-2]) % 1234567;
}
answer = arr[n-1];

    return answer;

}
