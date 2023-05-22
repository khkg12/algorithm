#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
stack<pair<int, int>> st;
vector<int> answer(numbers.size(), -1);

    for(int i = 0; i < numbers.size(); i++){
        while(!st.empty()){
            pair<int, int> top = st.top();

            if(top.first >= numbers[i]){
                break;
            }

            answer[top.second] = numbers[i];
            st.pop();
        }
        st.push({numbers[i], i});
    }


    return answer;

}
