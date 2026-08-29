#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:

    bool check(vector<vector<string>> &board,int x,int y){
        vector<int> arr=[1,-1,0];
        for(int a: arr){
            for(int b:arr){
                if(board[x+a][x+b]=="Q"){
                    return false;
                }
            }
        }
        return true;
    }
    void solve(int col,vector<vector<string>> &board,vector<vector<string>> &ans,int n,int QueenPlaced){
        if(col==n){
            ans.push_back(board);
            return;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n,vector<int>(n,"."));
        vector<vector<string>> ans;


    }
};