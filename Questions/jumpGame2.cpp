using namespace std;
#include <bits/stdc++.h>


//TC : O(N^N)
//SC : O(N)
int recuJumps(int ind,int jumps,vector<int> nums){
    if(ind>=nums.size()-1){
        return jumps;
    }
    int mini=INT_MAX;
    for(int i=1;i<=nums[ind];i++){
        mini=min(mini,recuJumps(ind+i,jumps+1,nums));
    }
    return mini;
}
int IndexingJump(vector<int>& nums) {
        int near = 0, far = 0, jumps = 0;

        while (far < nums.size() - 1) {
            int farthest = 0;
            for (int i = near; i <= far; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            near = far + 1;
            far = farthest;
            jumps++;
        }

    return jumps;        
}
int main(){
    vector <int> nums={2,3,1,1,4};
    cout<<recuJumps(0,0,nums)<<endl;
    cout<<IndexingJump(nums);
}