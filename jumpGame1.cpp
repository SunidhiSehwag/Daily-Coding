#include<iostream>
#include<vector>
using namespace std;
bool possible(vector<int>&jumps){
    int maxJump=0;
    for(int i=0;i<jumps.size();i++){
        if(i>maxJump){
            return 0;
        }
        maxJump=max(maxJump,i+jumps[i]);
    }
    return 1;
}
int main(){
    vector<int>jumps={2,3,1,1,4};
    cout<<possible(jumps);
}