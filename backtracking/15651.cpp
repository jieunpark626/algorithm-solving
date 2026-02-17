#include <iostream>
#include <vector>

using namespace std;

int N,M;

vector<int> nums;

void dfs(){
    if(nums.size()==M){
        for(int num:nums) cout<<num<<" ";
        cout<<"\n";
        return;
    }
    for(int i=1; i<=N; i++){
        nums.push_back(i);
        dfs();
        nums.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cin>>N>>M;
    dfs();
    return 0;
}