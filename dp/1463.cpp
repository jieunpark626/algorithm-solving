#include <iostream>
#include <queue>

using namespace std;

int n;
bool visited[1000000+3];
int main(){
    cin>>n;
    queue<pair<int,int>> q; // {loc,cnt}

    q.push({1,0});

    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        int cur_loc = cur.first;
        int cur_cnt = cur.second;
        int nums[] = {cur_loc+1, cur_loc*2, cur_loc*3};
        
        if(cur_loc==n){
            cout<<cur_cnt;
            break;
        }

        for(int num : nums){
            if(num>n) continue;
            if(!visited[num]){
                visited[num] = true;
                q.push({num, cur_cnt+1});
            }
        }
    }

    return 0;
}