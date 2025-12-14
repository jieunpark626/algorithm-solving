#include <iostream>
#include <vector>

using namespace std;

int n;

int change(vector<int> num){
    int result=0;
    for(int i=0; i<num.size(); i++){
        result = result*10 + num[i];
    }
    return result;
}

bool is_prime(vector<int> arr){
    int num = change(arr);
    if(num==0||num==1) return false;
    if(num==2) return true;
    if(num%2==0) return false;
    for(int i=3; i<num; i+=2){
        if(num%i==0) return false;
    }
    return true;
}

void solve(vector<int> num){
    // if(num.size()!=0 && !is_prime(num)) 
    //     return;

    if(num.size()==n){
        for(int i=0; i<n; i++){
            cout<<num[i];
        }
        cout<<"\n";
        return;
    }

    for(int i=0; i<=9; i++){
        num.push_back(i);
        if(is_prime(num))
            solve(num);
        num.pop_back();
    }
}

int main(){
    cin>>n;
    vector<int> num;
    solve(num);
    return 0;
}