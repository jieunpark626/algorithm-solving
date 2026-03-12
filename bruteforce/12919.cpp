#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S,T;
int sz;
bool dfs(string str){
    if(str.size()==sz){
        if(str==S) { return true; }
        else return false;
    }

    if(str.back()=='A'){
        str.pop_back();
        if(dfs(str)) return true;
        str.push_back('A');
    }

    if(str[0]=='B'){
        reverse(str.begin(), str.end());
        str.pop_back();
        if(dfs(str)) return true;
    }
    return false;
}

int main(){
    cin>>S>>T;
    sz=S.size();
    if(dfs(T)) cout<<1;
    else cout<<0;
    return 0;
}