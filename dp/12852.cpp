#include <iostream>
#include <vector>

using namespace std;

struct node{
    int cnt=0;
    vector<int> list;
};
const int MAX = 987654321;
int n;
node dp[1000000*3+1];

int main(){
    cin>>n;

    for(int i=0; i<=n; i++){
        dp[i] = {MAX};
    }
    dp[1]={0};

    for(int i=1; i<=n; i++){
        int count = dp[i].cnt + 1;

        if(dp[i+1].cnt > count) {
            dp[i+1].cnt = count;
            dp[i+1].list = dp[i].list; dp[i+1].list.push_back(i);
        }

        if(dp[i*2].cnt > count){
            dp[i*2].cnt = count;
            dp[i*2].list = dp[i].list; dp[i*2].list.push_back(i);
        }

        if(dp[i*3].cnt > count){
            dp[i*3].cnt = count;
            dp[i*3].list = dp[i].list; dp[i*3].list.push_back(i);
        }
    }

    cout<<dp[n].cnt<<"\n"<<n<<" ";

    for(int i=dp[n].list.size()-1; i>=0; i--){
        cout<<dp[n].list[i]<<" ";
    }
    
    return 0;
}