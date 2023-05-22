#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    int arr[size][size];
    for(int i = 0; i < size; i++){
        arr[size-1][i] = triangle[size-1][i];        
    }
    for(int i = size-2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            arr[i][j] = triangle[i][j] + max(arr[i+1][j], arr[i+1][j+1]);     
        }
        
    }        
    
    return arr[0][0];
}