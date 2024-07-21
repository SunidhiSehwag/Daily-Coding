#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&nums,int s,int mid,int e){
    int len1=mid-s+1;
    int len2=e-mid;
    int *left=new int[len1];
    int *right=new int[len2];
    int k=s;
    for(int i=0;i<len1;i++){
        left[i]=nums[k++];
    }
    k=mid+1;
    for(int i=0;i<len2;i++){
        right[i]=nums[k++];
    }
    int leftindex=0;
    int rightindex=0;
    int mainindex=s;
    while(leftindex<len1&&rightindex<len2){
        if(left[leftindex]<=right[rightindex]){
            nums[mainindex++]=left[leftindex++];
        }
        else{
            nums[mainindex++]=right[rightindex++];
        }
    }
    while(leftindex<len1){
        nums[mainindex++]=left[leftindex++];
    }
    while(rightindex<len2){
        nums[mainindex++]=right[rightindex++];
    }
}
int countPairs(vector<int>&nums,int s,int mid,int e){
    int right=mid+1;
    int count=0;
    for(int i=s;i<=mid;i++){
        while(right<=e&&nums[i]>2LL*nums[right]){
            right++;
            
        }
        count+=right-(mid+1);
    }
    return count;
}
int mergeSort(vector<int>&nums,int s,int e){
    int count=0;
    if(s>=e){

        return count;
    }
    
    int mid=s+(e-s)/2;
    count+=mergeSort(nums,s,mid);
    count+=mergeSort(nums,mid+1,e);
    count+=countPairs(nums,s,mid,e);
    merge(nums,s,mid,e);
    return count;
}
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);

    }
    