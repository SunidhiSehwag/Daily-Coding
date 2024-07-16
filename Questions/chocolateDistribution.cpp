#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//TC : O(nlogn)
//SC : O(1)
class solve {
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        
       long long int mini = INT_MAX; 
       int i = 0; 
       int j = m-1; 
       while(j < n){
           long long int diff = a[j]- a[i]; 
           mini = min(mini , diff); 
           i++, j++; 
       }
       return mini;
    }
};
int main(){
    vector<long long>a={3, 4 ,1 ,9, 56, 7, 9, 12};
    int n=8,m=5;
    solve s1;
    cout<<s1.findMinDiff(a,n,m);
}