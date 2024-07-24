using namespace std;
#include <bits/stdc++.h>

void rotate(vector<vector<int>>& matrix) {
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<i;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    int n=matrix[0].size();
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<n/2;j++){
            swap(matrix[i][j],matrix[i][n-1-j]);
        }
    }
}
int main() {
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}