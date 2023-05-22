#include <string>
#include <vector>

using namespace std;
char map[31][31];

int solution(int m, int n, vector<string> board) {
    int answer = 0;  
    int new_ans = 0;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            map[i][j] = board[i][j];
        }
    }
    
    do{
        answer = new_ans;
        bool check[31][31] = {false,};
        
        for(int i = 0; i < m - 1; i++){ // 깨뜨릴 블록 체크
            for(int j = 0; j < n - 1; j++){
                char tmp = map[i][j];
                if(tmp == '-') continue;
                if(tmp == map[i+1][j] && tmp == map[i][j+1] && tmp == map[i+1][j+1]){
                    check[i][j] = true;
                    check[i+1][j] = true;
                    check[i][j+1] = true;
                    check[i+1][j+1] = true;
                }                
            }
        }
        
        for(int i = 0; i < m; i++){ // 블록 깨뜨리기
            for(int j = 0; j < n; j++){
                if(check[i][j]){
                    map[i][j] = '-';
                    new_ans++;
                }
            }
        }
        
        for(int i = 0; i < m; i++){ // 블록 채우기
            for(int j = 0; j < n; j++){
                if(map[i][j] == '-'){
                    int t = i;
                    while(t > 0){
                        map[t][j] = map[t-1][j];
                        map[t-1][j] = '-';
                        t--;
                    }
                }
            }
        }
        
        
    }while(answer != new_ans);    
    
    
    
    
    return answer;
}