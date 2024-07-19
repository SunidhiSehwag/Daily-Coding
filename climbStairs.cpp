#include<iostream>
using namespace std;
#include<vector>
int topDown(int n,vector<int>&dp){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=topDown(n-1,dp)+topDown(n-2,dp);
    return dp[n];
}
int bottomUp(int n,vector<int>&dp){
    if(n<=0){
        return 0;
    }
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int helper(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    return helper(n-1)+helper(n-2);
}
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return bottomUp(n,dp);
    }
int main(){
    cout<<climbStairs(10);
}