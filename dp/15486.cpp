#include <iostream>

using namespace std;

const int MAX = 1500000;
int n;
int t[MAX+2];
int p[MAX+2];
long long dp[MAX+2];

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t[i];
        cin>>p[i];
    }

    long long max = 0;
    dp[n] = 0;
    for(int i=n-1; i>=0; i--){
        if(i+t[i]>n) dp[i] = max;
        else{
            dp[i] = p[i] + dp[i+t[i]];
            if(dp[i]>max) max = dp[i];
            else dp[i] = max;
        }
    }
    cout<<max;
    return 0;
}