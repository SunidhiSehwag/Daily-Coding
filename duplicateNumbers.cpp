#include<iostream>
#include<vector>
using namespace std;
 vector<int> findDuplicates(vector<int>& nums) {
        //whenever find duplicates in 1 to n this technique is always used
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            int num=abs(nums[i]);
            int idx=num-1;
            if(nums[idx]<0){
                result.push_back(num);
            }else{
            nums[idx]*=-1;}
        }
        return result;
    }