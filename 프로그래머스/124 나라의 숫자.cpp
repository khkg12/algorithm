#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    int remainder;
    
    while(n != 0){
        remainder = n % 3;
        n /= 3;
        
        if(remainder == 0){
            answer = '4' + answer;
            n--; // 나누어 떨어질경우엔 1이남기때문에 124나라에선 빼주어야함 3 = 20(3진법) 이므로 4만 나오려면 1을 빼주어야함
        }
        else if(remainder == 1){
            answer = '1' + answer;
        }
        else if(remainder == 2){
            answer = '2' + answer;
        }
    }
    
    return answer;
}