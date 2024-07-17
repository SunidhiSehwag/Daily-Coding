#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
 int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
            if(mp[i]>nums.size()/2){
                return i;
            }
        }
        return -1;
    }
    //****important approach moores algorithm */
    //o(n)
    //o(1)
int majorityElement(vector<int>& nums) {
        int ele;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                ele=nums[i];
                count++;
            }
            else if(nums[i]==ele){
                count++;
            }
            else{
                count--;
            }
        }
        count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele){
                count++;
            }
            
        }
        if(count>nums.size()/2){
            return ele;
        }
        return -1;

    }
int main(){
    vector<int>nums={2,2,1,1,1,2,2};
    cout<<majorityElement(nums);
}