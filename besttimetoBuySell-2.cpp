#include<iostream>
#include<vector>
using namespace std;
int helper(vector<int>&prices,int i,int buy,vector<vector<int>>&dp){
    int maxProfit=0;
    if(i>=prices.size()){
        return 0;
    }
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    if(buy){
        int buyprofit=-prices[i]+helper(prices,i+1,0,dp);
        int nobuyprofit=0+helper(prices,i+1,1,dp);
        dp[i][buy]=max(buyprofit,nobuyprofit);
    }
    else{
        int sellprofit=prices[i]+helper(prices,i+1,1,dp);
        int nosellprofit=0+helper(prices,i+1,0,dp);
        dp[i][buy]=max(sellprofit,nosellprofit);
    }
    return dp[i][buy];

}
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+2,vector<int>(3,-1));
        return helper(prices,0,1,dp);
    }
    int main(){
        //prices = [7,1,5,3,6,4]
        vector<int>prices={7,1,5,3,6,4};
        cout<<maxProfit(prices);
    }