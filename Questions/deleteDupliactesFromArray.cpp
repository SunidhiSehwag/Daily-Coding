#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class solve {
    public: 

    // TC : O(n)
    // SC : o(1)
    int findduplicate(int nums[],int n){
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=nums[j]){
                j++;
                nums[j]=nums[i];
            }
        }
        return j+1;
    }
    // Approach 2 : using hashmap but its TC:O(n) and SC:O(n)
};
int main() {
    solve s1;
    int nums[5]={1,1,2,3,3};
    cout<<s1.findduplicate(nums,5);
}