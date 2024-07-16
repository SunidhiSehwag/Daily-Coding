#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//aproach 1: using 2 loops 
// TC : O(n^2)
// SC : O (n)

//Approach 2 : Using Map 
// TC : O(n)
// SC : O(n)
vector<int> twoSumUsingMap(vector<int>& arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}

// this approach can be used only when used to find if it exits or not
bool twoSumUsingPointer(vector<int>&nums, int target){
    sort(nums.begin(),nums.end());
    int i=0,j=nums.size()-1;
    while(i<j){
        int sum=nums[i]+nums[j];
        if(sum==target){
            return true;
        }
        else if(sum>target){
            j--;
        }
        else {
            i++;
        }
    }
    return false;
}
int main(){
    vector<int> nums={2,7,11,15};
    int target=9;
    cout<<twoSumUsingPointer(nums,target)<<endl;
    vector<int> ans=twoSumUsingMap(nums,target);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
}