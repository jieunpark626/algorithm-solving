#include <iostream>
#include <string>
#include <map>
#include <vector>


using namespace std;

vector<int> alph[30];
void init(){
    for(int i=0; i<30; i++){
        alph[i].clear();
    }
}
int T;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;

    string line; int k;
    while(T--){
        cin>>line>>k;
        init();
        int minVal=100000; int maxVal=0;
        for(int i=0; i<line.size(); i++){
            char c = line[i];
            int idx=c-'a';
            alph[idx].push_back(i);
            if(alph[idx].size()>=k){
                for(int j=alph[idx].size()-1; j>=k-1; j--){
                    int val = alph[idx][j] - alph[idx][j-k+1] + 1;
                    if(val<minVal) minVal=val;
                    if(val>maxVal) maxVal=val;     
                }
            }
        }
        if(minVal==100000 && maxVal==0) cout<<-1<<"\n";
        else cout<<minVal<<" "<<maxVal<<"\n";
    }

    
    return 0;
}