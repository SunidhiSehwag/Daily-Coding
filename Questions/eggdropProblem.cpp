#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int helper(int k, int n, vector<vector<int>>& memo){
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;
        
        if(memo[k][n] != -1) return memo[k][n];
        
        int mn = INT_MAX, low = 0, high = n, temp = 0;
        
        while(low<=high){
            
            int mid = (low + high)/2;
            int left = helper(k-1, mid-1, memo);
            int right = helper(k, n-mid, memo);
            
            temp = 1 + max(left, right);
            
            if(left < right) 
                low = mid+1;
            else 
                high = mid-1;     
    
            mn = min(mn, temp); 
        }
        return memo[k][n] = mn;
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>> memo(k+1, vector<int>(n+1, -1));
        return helper(k, n, memo);
    }
};
int main(){
    int k=1,n=2;
    Solution s1;
    cout<<"The minimum number of moves are: "<<endl;
    cout<< s1.superEggDrop(k,n);
}