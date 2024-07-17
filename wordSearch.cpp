#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
vector<vector<int>>direction{{-1,0},{0,1},{1,0},{0,-1}};
bool helper(vector<vector<char>>&board,string word,int i,int x,int y,map<pair<int,int>,bool>&visited){
    if(i>=word.size()){
        return 1;
    }
    if(x<0||x>=board.size()||y<0||y>=board[0].size()||board[x][y]!=word[i]||visited[{x,y}]==1){
        return 0;
    }
    
        visited[{x,y}]=1;
    
    for(auto &dir:direction){
        int newX=x+dir[0];
        int newY=y+dir[1];
        
            if( helper(board,word,i+1,newX,newY,visited)){
                return 1;
            }
        
    }
    visited[{x,y}]=0;
    return 0;

}
    bool exist(vector<vector<char>>& board, string word) {
       map<pair<int,int>,bool>visited;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]&&helper(board,word,0,i,j,visited)){
                 return 1;
                }
            }
        }
      return 0;
    }
int main(){
    vector<vector<char>>board{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word="SEE";
    if(exist(board,word)){
        cout<<"Word Found!!";
    }
    else{cout<<"Not found";}
}