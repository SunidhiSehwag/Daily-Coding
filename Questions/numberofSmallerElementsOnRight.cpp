using namespace std;
#include <bits/stdc++.h>

//  TC : O(N^2)
vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        if(nums.size()==1){
            return {0};
        }
        for(int i=0;i<nums.size();i++){
            int count=0;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j] < nums[i]) {
                    count++;
                }
            }
            ans[i]=count;
        }
        return ans;
}
// ------------------------------------------------------------------------------------------------------// 

//aproach 2 : use merge sort algorithm 
void merge(int left, int mid, int right, vector<pair<int, int>>& arr,vector<int>& count)
{
    vector<pair<int, int>> temp(right - left + 1);
    
    int i = left;
    int j = mid + 1;
    int k = 0;
    
    while(i <= mid && j <= right)
    {
        if(arr[i].first <= arr[j].first)
        {
            temp[k++] = arr[j++]; 
        }
        else
        {
            count[arr[i].second] += (right - j + 1);
            
            temp[k++] = arr[i++];
        }
    }
    
    while(i <= mid)
    {
        temp[k++] = arr[i++];
    }
    
    while(j <= right)
    {
        temp[k++] = arr[j++];
    }
    
    for(int l = left; l <= right; l++)
    arr[l] = temp[l - left];
    
}
            
void mergeSort(int left, int right, vector<pair<int, int>>& arr, vector<int>& count)
{
    if(left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;
    
    mergeSort(left, mid, arr, count);
    mergeSort(mid + 1, right, arr, count);
    
    merge(left, mid, right, arr, count);
}

vector<int> countSmaller2(vector<int>& nums) {
    
    int n=nums.size();
    vector<pair<int, int>> arr;
    
    for(int i = 0; i < n; i++)
    {
        arr.push_back({nums[i], i});
    }
    
    vector<int> count(n, 0);
    
    mergeSort(0, n - 1, arr, count);
    
    return count;
}

// -----------------------------main---------------------------//
int main () {
    vector<int> nums={5,2,6,1};
    vector<int> ans1=countSmaller2(nums);
    for(int i=0;i<ans1.size();i++){
        cout<<ans1[i]<<" ";
    }
}