#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
//approach:1
//tc:o(n)
//sc:o(n)
int duplicate(vector<int>&nums,unordered_map<int,int>&mp){
    for(auto i:nums){
        mp[i]++;
    }
    for(auto i:mp){
        if(i.second!=1){
            return i.first;
        }
    }
    return -1;
}
//approach:2
//tc:0(nlogn)
//sc:o(n)
int duplicate2(vector<int>&nums){
    sort(nums.begin(),nums.end());
  for(int i=0;i<nums.size()-1;i++){
      if(nums[i]==nums[i+1]){
        return nums[i];
      }
  }
  return -1;
}
//approach:3
//important
//slow &fast approach
//tc:o(n)
//sc:o(1)
 int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        slow=nums[slow];
        fast=nums[nums[fast]];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
int main(){
    unordered_map<int,int>mp;
    vector<int>nums={3,3,3,3,3,3};
    
    int a=duplicate(nums,mp);
    int b=duplicate2(nums);
    int c=findDuplicate(nums);
  
    cout<<"duplicate number is "<<c;
}