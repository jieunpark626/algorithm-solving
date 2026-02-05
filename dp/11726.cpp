#include <iostream>

using namespace std;

int n;
int dp[1002];
int main(){
    cin>>n;

    // 블록을 쌓는 방법은 한칸 or 두칸 쓰기, 그러면 n-1, n-2 각각 하나씩이니까 더하면 댐
    dp[0]=1; dp[1]=1;
    for(int i=2; i<=n; i++){ 
        dp[i] = (dp[i-1] + dp[i-2])%10007; 
    }
    
    cout<<dp[n];
    return 0;
}