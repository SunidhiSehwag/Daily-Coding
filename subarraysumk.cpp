#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
 int subarraySum(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int>mp;
        int sum=0;
        mp[sum]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end()){
                count+=mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
int main(){
    vector<int>nums={1,2,3};
    int k=3;
    cout<<subarraySum(nums,k);
}