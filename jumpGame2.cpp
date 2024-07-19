#include<iostream>
#include<vector>
using namespace std;
int minJumps(vector<int>&jumps){
    int current=0;
    int farthest=0;
    int jump=0;
    for(int i=0;i<jumps.size()-1;i++){
        farthest=max(farthest,i+jumps[i]);
        if(i==current){
            current=farthest;
            jump++;
        }
    }
    return jump;
}
int main(){
    vector<int>jumps={2,3,1,1,4};
    cout<<minJumps(jumps);
}