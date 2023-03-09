#include <string>
#include <vector>

using namespace std;
int ans[60001];

int solution(int n) {
ans[1] = 1;
ans[2] = 2;
for(int i = 3; i <= n; i++){
ans[i] = (ans[i-1] + ans[i-2]) % 1000000007;
}
return ans[n];
}
