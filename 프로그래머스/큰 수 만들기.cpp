#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
string answer = "";

    int n= number.length()-k;

    for(int i=0,idx=-1; i<n;i++){
        char max='0';
        for(int j=idx+1;j<=k+i;j++){ // 처음에 i는 0이기 때문에 k+i는 k이고 맨 끝이 최댓값이라고 한다면 나머지를 다 버려도 n을 만족하는 자리수가 나온다. 최댓값을 구하고 그 값을 한자리에 넣으면 그다음에 만족해도 되는 자리수는 한개줄어들어서 i, 즉 1씩 더해줘도된다는 의미
            if(max<number[j]){
                max = number[j];
                idx=j;
            }
        }
        answer+=max;
    }
    return answer;

}
