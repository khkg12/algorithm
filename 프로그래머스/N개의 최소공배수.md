#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
int answer = 0;

    sort(arr.begin(), arr.end());
    int num = arr.back();
    int idx;
    int mul = 1;
    while(1){
        idx = 0;
        for(int i = 0; i < arr.size(); i++){
            if(num % arr[i] == 0){
                idx++;
            }
        }
        if(idx == arr.size()){
            break;
        }
        else{
            mul++;
            num = arr.back() * mul;
        }
    }
    answer = num;
    return answer;

}
