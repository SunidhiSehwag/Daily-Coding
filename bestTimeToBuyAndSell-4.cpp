#include<iostream>
#include<vector>
using namespace std;
int helper(vector<vector<vector<int>>>&dp,vector<int>&prices,int i,int limit,int buy){
    if(i>=prices.size()||limit==0){
        return 0;
    }
    if(dp[i][limit][buy]!=-1){
        return dp[i][limit][buy];
    }
    if(buy){
        int buyProfit=-prices[i]+helper(dp,prices,i+1,limit,0);
        int nobuyProfit=0+helper(dp,prices,i+1,limit,1);
        dp[i][limit][buy]=max(buyProfit,nobuyProfit);
    }
    else{
        int sellProfit=prices[i]+helper(dp,prices,i+1,limit-1,1);
        int nosellProfit=0+helper(dp,prices,i+1,limit,0);
        dp[i][limit][buy]=max(sellProfit,nosellProfit);
    }
    return dp[i][limit][buy];
}
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(k+1,vector<int>(3,-1)));
        return helper(dp,prices,0,k,1);
        return 0;
    }
    int main(){
        int k=2;
        vector<int>prices={3,2,6,5,0,3};
        cout<<maxProfit(k,prices);
    }