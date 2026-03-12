#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> nums;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>N;
    int input;
    for(int i=0; i<N; i++){
        cin>>input;
        nums.push_back(input);
    }
    sort(nums.begin(), nums.end(), greater<int>());


    int idx=0;
    while(true){
        if(idx>N-3){
            cout<<"-1";
            return 0;
        }

        if(nums[idx]<nums[idx+1]+nums[idx+2]){
            cout<<nums[idx]+nums[idx+1]+nums[idx+2];
            return 0;
        }
        idx++;
    }
    return 0;
}