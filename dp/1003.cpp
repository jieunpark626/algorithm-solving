#include <iostream>
#include <vector>

using namespace std;

int T;
int max_num;
int dp[41][2];
vector<int> nums;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>T;
    int N;
    for(int i=0; i<T; i++){
        cin>>N;
        nums.push_back(N);
        if(N>max_num) max_num = N;
    }

    dp[0][0] = 1; dp[0][1] = 0; dp[1][0] = 0; dp[1][1] = 1;
    for(int i=2; i<=max_num; i++){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }

    for(int num: nums){
        cout<<dp[num][0]<<" "<<dp[num][1]<<"\n";
    }

    return 0;
}