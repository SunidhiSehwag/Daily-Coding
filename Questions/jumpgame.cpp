using namespace std;
#include <bits/stdc++.h>

bool canJump(vector<int>& nums) {
        int gas = 0;
        for (int i=0;i<nums.size();i++) {
            if (gas < 0) {
                return false;
            } 
            else if (nums[i] > gas) {
                gas = nums[i];
            }
            gas -= 1;
        }
    return true;
}
int main () { 
    vector<int> nums={3,2,1,0,4};
    cout<<canJump(nums);
}