#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string line;

bool isPalindrome(int left, int right){
    while(left<right){
        if(line[left]!=line[right]) return false;
        left++; right--;
    }
    return true;
}

int check(){
    int left=0; int right=line.size()-1;
    while(left<right){
        if(line[left]==line[right]){ 
            left++; right--; 
        }else{
           if(isPalindrome(left, right-1) || isPalindrome(left+1, right)) return 1;
           else return 2;
        }
    }
    return 0;   
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin>>T;
    while(T--){
        cin>>line;
        cout<<check()<<'\n';
    }

    return 0;
}