#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N,M;
vector<int> pinned;
int dp[43];

void fibo(int max){
    memset(dp,-1,sizeof(dp));
    dp[0] = 1; // 고정석이 맨 앞에 있거나 할 때 dp[0]
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=max; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
}

int main(){
    cin>>N>>M;

    int loc;
    for(int i=0; i<M; i++){
        cin>>loc;
        pinned.push_back(loc);
    }

    vector<int> nums;
    int prev = 0;
    int len = 0;
    int max = 0;
    for(int loc: pinned){
        len = loc-prev-1;
        nums.push_back(len);
        prev = loc;
        if(len>max) max = len;
    }   
    len = (N+1)-prev-1;
    nums.push_back(len);
    if(len>max) max = len;

    fibo(max);

    int ans = 1;
    for(int num: nums){
        // cout<<"num "<<num<<endl;
        ans *= dp[num];
    }

    cout<<ans;
    return 0;
}