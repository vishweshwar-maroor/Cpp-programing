#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(string& str,int i,vector<string> &Keymap,string temp,vector<string>& ans){
    if(i>=str.length()){
        ans.push_back(temp);
        return;
    }

    int num= str[i]-'0';
    string value=Keymap[num];
    
    for(int j=0;j<value.length();j++){
        temp.push_back(value[j]);
        solve(str,i+1,Keymap,temp,ans);
        temp.pop_back();
    }
}
vector<string> keypad(string& str){
    vector<string> Keymap;
    Keymap.push_back("");
    Keymap.push_back("");
    Keymap.push_back("abc");
    Keymap.push_back("def");
    Keymap.push_back("ghi");
    Keymap.push_back("jkl");
    Keymap.push_back("mno");
    Keymap.push_back("pqrs");
    Keymap.push_back("tuv");
    Keymap.push_back("wxyz");
    int i=0;
    string temp;
    vector<string> ans;
    solve(str,i,Keymap,temp,ans);
    return ans;
}
int main(){
    string str="34";
    vector<string> set=keypad(str);
    for(string i:set){
        cout<<"["<<i<<"]"<<endl;
    }

}