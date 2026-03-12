#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
string line;

vector<string> split() {
    vector<string> result;
    string buffer="";
    bool inTag=false;

    for(char c: line){
        if(c=='<') inTag = true;
        if(c=='>') inTag = false;

        if(c==' '&&!inTag){
            if(!buffer.empty()){
                result.push_back(buffer);
                buffer="";
            }
        }else{
            buffer += c;
        }
    }
    if(!buffer.empty()) result.push_back(buffer);
    return result;
}

string rev(string words){
    string result = "";
    int idx=0;

    string w="";
    while(idx<words.size()){
        if(words[idx]=='<'){
            if(w.size()>0){
                reverse(w.begin(), w.end());
                result += w;
                w="";
            }
            while(words[idx]!='>'){
                result.push_back(words[idx]);
                idx++;
            } 
            result.push_back('>');
            idx++;
        }else{
            w.push_back(words[idx]);
            idx++;
        }
    }

    if(w.size()>0){
        reverse(w.begin(), w.end());
        result += w;
        w="";
    }
    
    return result;
}

int main(){
    getline(cin,line);
    vector<string> words = split(); // 공백 기준으로 자르기
    
    for(string word: words){
        cout<<rev(word)<<" ";
    }

    return 0;
}