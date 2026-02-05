#include <iostream>
#include <vector>

using namespace std;

vector<int> num;
int dp[13];
int main(){
    int T; cin>>T;
    
    int n;
    int max_num = 0;
    for(int tc=0; tc<T; tc++){
        cin>>n;
        num.push_back(n);
        if(max_num<n) max_num = n;
    }
    dp[1]=1; dp[2]=2; dp[3]=4;
    for(int i=4; i<=max_num; i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    for(int n: num){
        cout<<dp[n]<<"\n";
    }
    return 0;
}