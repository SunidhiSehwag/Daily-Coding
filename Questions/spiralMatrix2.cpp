using namespace std;
#include <bits/stdc++.h>

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>>ans(n,vector<int>(n));
    int left = 0;
    int right = n - 1;
    int top = 0;
    int bottom = n - 1;
    int val=1;

    while(top <= bottom && left <= right){

        for(int i = left; i <= right; i++){
            ans[top][i]=val;
            val++;
        }
        top++;

        for(int i = top; i <= bottom; i++){
            ans[i][right]=val;
            val++;
        }
        right--;

        if(top <= bottom){
            for(int i = right; i >= left; i--){
                ans[bottom][i]=val;
                val++;
            }
            bottom--;
        }

        if(left <= right){
            for(int i = bottom; i >= top; i--){
                ans[i][left]=val;
                val++;
            }
            left++;
        }

    }
    return ans;
}

int main(){
    vector<vector<int>> ans= generateMatrix(3);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}