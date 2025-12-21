#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[200+1][200+1][200+1];
int cap[3];
vector<int> answer;

void dfs(int arr[3]){
    if(arr[2]!=cap[2] && arr[0]==0){
        //cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
        answer.push_back(arr[2]);
    }
    //cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
    for(int i=0; i<3; i++){
        int water = arr[i];
        if(arr[i]>0){
            for(int j=0; j<3; j++){
                if(i==j) continue;
                if(arr[j]!=cap[j]){
                    int origin = arr[j];
                    int remain = cap[j]-arr[j];
                    if(remain>water){
                        arr[j] = origin+water;
                        arr[i] = 0;
                    }else{
                        arr[j] = cap[j];
                        arr[i] = water-remain;
                    }
                    //cout<<"after "<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
                    if(visited[arr[0]][arr[1]][arr[2]]==false){
                        visited[arr[0]][arr[1]][arr[2]] = true;
                        dfs(arr);
                    }
                    arr[i] = water;
                    arr[j] = origin;
                }
            }
        }
    }
}

int main(){
    for(int i=0; i<3; i++){
        cin>>cap[i];
    }
    visited[cap[0]][cap[1]][cap[2]] = true;
    answer.push_back(cap[2]);
    int tmp[3] = {0,0,cap[2]};
    dfs(tmp);

    sort(answer.begin(), answer.end());
    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<" ";
    }
    return 0;
}