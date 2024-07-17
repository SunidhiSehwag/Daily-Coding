using namespace std;
#include <bits/stdc++.h>

int solution(vector<int> prices){
    int ans=INT_MIN;
        int minpri=prices[0];
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minpri){
                minpri=prices[i];
            }
            int temp=prices[i]-minpri;
            ans=max(temp,ans);
        }
    return ans;
}
int main(){
    vector<int> nums={7,1,5,3,6,4};
    cout<<solution(nums);
    
}