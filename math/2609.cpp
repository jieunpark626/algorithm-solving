#include <iostream>

using namespace std;

int gcd(int a, int b){
    int c;
    while(b){
        c = a%b;
        a=b;
        b=c;
    }
    return a;
}

int main(){
    int n1,n2;
    cin>>n1>>n2;
    int g = gcd(n1,n2);
    int l = (n1*n2)/g;
    cout<<g<<"\n"<<l;
    return 0;
}