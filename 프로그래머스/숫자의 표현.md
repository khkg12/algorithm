#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
int answer = 0;
int sum = 0;

    for(int i = 1 ; i <= n ; i ++){
        sum = 0;
        for(int j = i ; j <= n ; j++){
            if(sum < n){
                sum += j;
                if(sum == n){
                    answer++;
                    break;
                }
            }
            else{
                break;
            }
        }
    }


    return answer;

}
