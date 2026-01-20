#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> nums;
int dp[10000+3];

int main(){
    cin>>n>>k;

    int num;
    for(int i=0; i<n; i++){
        cin>>num;
        nums.push_back(num);
    }

    dp[0]=1;
    for(int num: nums){
        for(int i=num; i<=k; i++){
            dp[i] = dp[i] + dp[i-num];
        }
    }

    cout<<dp[k];


    return 0;
}