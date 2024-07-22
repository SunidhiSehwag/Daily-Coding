#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
     int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        mp[sum]=1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0){
                rem+=k;
            }
            if(mp.find(rem)!=mp.end()){
                count+=mp[rem];
            }
            mp[rem]++;
        }
        return count;
    }