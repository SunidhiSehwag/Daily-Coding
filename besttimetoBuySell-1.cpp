#include<iostream>
#include<vector>
using namespace std;
//tc:o(n2)
int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        for(int i=0;i<prices.size()-1;i++){
            int buy=prices[i];
            for(int j=i+1;j<prices.size();j++){
                maxProfit=max(maxProfit,prices[j]-buy);
            }
        }
        return maxProfit;
    }
//tc:o(n) choosing a price to buy only when it is less than earlier buy value and then evaluating the profit   
int maxProfit1(vector<int>& prices) {
       int maxProfit=0;
       int buy=prices[0];
       for(int i=1;i<prices.size();i++){
        if(buy>prices[i]){
            buy=prices[i];
        }
        if(prices[i]-buy>maxProfit){
            maxProfit=prices[i]-buy;
        }
       }
       return maxProfit;

}
int main(){
    vector<int>prices={7,1,5,3,6,4};
    cout<<maxProfit1(prices)<<endl;
}
