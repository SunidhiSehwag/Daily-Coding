using namespace std;
#include <bits/stdc++.h>

int majorityElement(vector<int>& nums) {
        int ele=nums[0],cnt=0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0) {
                cnt=1;
                ele=nums[i];
            }
            else if(ele==nums[i]){ 
                cnt++;
            }
            else {
                cnt--;
            }
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele){
                count++;
            }
        }
    return (count>nums.size()/2)? ele : -1;
}
int main () {
    vector<int> nums={2,2,1,1,1,2,2};
    cout<<majorityElement(nums);
}
