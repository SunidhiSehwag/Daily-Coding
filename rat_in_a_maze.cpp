#include <iostream>
#include<vector>
#include<string>
using namespace std;
bool issafe(int i,int j,int row,int col,vector<vector<bool>>&visited,int arr[][4]){
  if(i>=0 && i<row && j>=0 && j<col && visited[i][j]==0 && arr[i][j]==1){
    return 1;
  }
  return 0;
}
void solvemaze(int arr[][4],vector<string>&path,string output,int &row,int &col,vector<vector<bool>>&visited,int i,int j){
  if(i==row-1 && j==col-1){
    path.push_back(output);
    return;
  }
  //down
  if(issafe(i+1,j,row,col,visited,arr)){
    visited[i+1][j]=1;
    solvemaze(arr,path,output+'D',row,col,visited,i+1,j);
     visited[i+1][j]=0;
  }
  //left
  if(issafe(i,j-1,row,col,visited,arr)){
    visited[i][j-1]=1;
    solvemaze(arr,path,output+'L',row,col,visited,i,j-1);
     visited[i][j-1]=0;
  }
  //right
  if(issafe(i,j+1,row,col,visited,arr)){
    visited[i][j+1]=1;
    solvemaze(arr,path,output+'R',row,col,visited,i,j+1);
     visited[i][j+1]=0;
  }
  //up
   if(issafe(i-1,j,row,col,visited,arr)){
    visited[i-1][j]=1;
    solvemaze(arr,path,output+'U',row,col,visited,i-1,j);
     visited[i-1][j]=0;
  }


}

int main() {
  int maze[4][4]={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
  if(maze[0][0]==0){
    cout<<"no path exist";
  }
  int row=4;
  int col=4;
  int i=0;
  int j=0;
  vector<string>path;
  vector<vector<bool>>visited(row,vector<bool>(col,0));
  visited[0][0]=1;
  string output="";
  solvemaze(maze,path,output,row,col,visited,i,j);
  for(int i=0;i<path.size();i++){
    cout<<path[i]<<endl;
  }
  
}