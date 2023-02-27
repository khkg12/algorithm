#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
vector<vector<int>> answer(arr1.size());
cout << arr1[0].size() << " " << arr2.size() << " ";
int k = 0;
for(int i = 0; i < arr1.size(); i++){
for(k = 0; k < arr2[0].size(); k++){
int sum = 0;
for(int j = 0; j < arr1[i].size(); j++){
sum += arr1[i][j] \* arr2[j][k];
}
answer[i].push_back(sum);
}
}

    return answer;

}
