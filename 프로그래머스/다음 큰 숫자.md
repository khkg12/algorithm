#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
int answer = 0;
int tmp = 0;
int n2 = n;
int n3 = 0;

    while(n2 != 0){
        if(n2 % 2 == 1) tmp++;
        n2 /= 2;
        cout << n2 << " ";
    }

    while(1){
        n++;
        n3 = n;
        answer = 0;
        while(n3 != 0){
        if(n3 % 2 == 1) answer++;
        n3 /= 2;
        }
        if(tmp == answer) {
            answer = n;
            break;
        }

    }


    return answer;

}
