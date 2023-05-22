using namespace std;

long long gcd(long long a, long long b){  
 while(b != 0){
long long c = a % b;
a = b;
b = c;
}
return a;
}

long long solution(int w,int h) {
long long answer = 1;
long long num;
long long W = w;
long long H = h;
if(W > H) num = gcd(W, H);
else if(W == H) return W\*H - w;
else num = gcd(H, W);

    int a = W / num, b = H / num;
    int sum = (a + b - 1) * num;
    answer = W * H - sum;
    return answer;

}
