#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<vector<int>> combi;
vector<vector<int>> peoples;
void dfs(vector<int> nums, int idx){
    if(nums.size()==3){
        combi.push_back(nums);
        return;
    }

    for(int i=idx; i<M; i++){
        nums.push_back(i);
        dfs(nums,i+1);
        nums.pop_back();
    }
}

int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++){
        vector<int> input;
        for(int j=0; j<M; j++){
            int n; cin>>n;
            input.push_back(n);
        }
        peoples.push_back(input);
    }

    dfs({},0);
    int ans=0;
    for(vector<int> nums: combi){
        int sum=0;
        for(int i=0; i<N; i++){
            int val=0;
            for(int n: nums){
                val = max(val, peoples[i][n]);
            }
            sum += val;
        }
        ans = max(ans,sum);
    }

    cout<<ans<<endl;
    return 0;
}