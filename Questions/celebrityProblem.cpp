#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int> >& M, int n) {
    stack<int> st;
    for(int i=0;i<n;i++){
        st.push(i);
    }
    while(st.size() > 1){
        int a=st.top();
        st.pop();
        
        int b=st.top();
        st.pop();

        if(M[a][b]==1){
            //a knows b so a not a celebrity
            st.push(b);
        }
        else {
            st.push(a);
        }
    }
    int suspected=st.top();
    int row=0,col=0;
    for(int i=0;i<n;i++){
        row+=M[suspected][i];
        col+=M[i][suspected];
    }
    if(row==0 && col==(n-1)){
        return suspected;
    }
    else {
        return -1;
    }
}

int main() {
    vector<vector<int>> M = {{0,1,0},{0,0,0},{0,1,0}};
    cout<<"The celebrity is:"<<endl<<celebrity(M,3);
}