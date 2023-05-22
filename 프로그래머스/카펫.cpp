#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
vector<int> answer;

    for(int i = 1; i <= (int)sqrt(yellow); i++){
        if(yellow % i == 0){
            int tmp = (2 * i + 4) + (2 * (yellow / i));
            cout << tmp << " ";
            if(tmp == brown){
                answer.push_back(yellow / i + 2);
                answer.push_back(i + 2);
                break;
            }
        }
    }
    return answer;

}
