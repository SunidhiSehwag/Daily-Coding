#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                ans += prices[i] - prices[i - 1];
            }
        }
    return ans;
}
int main(){
    vector<int> nums={7,1,5,3,6,4};
    cout<<maxProfit(nums);
}