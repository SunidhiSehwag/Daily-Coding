#include<iostream>
#include<vector>
#include<deque>
using namespace std;
//cost is distance
int canCompleteCircuit(vector<int>&gas,vector<int>&cost){
   deque<int>dq;
   vector<int>netgas(gas.size());
   for(int i=0;i<gas.size();i++){
    netgas[i]=gas[i]-cost[i];
    if(netgas[i]>=0){
        dq.push_back(i);
    }
   }
   if(dq.empty()){
    return -1;
   }
   while(!dq.empty()){
    int start=dq.front();
    dq.pop_back();
    int total_gas=0;
    bool can_complete=1;
    for(int i=0;i<gas.size();i++){
        int idx=(start+i)%gas.size();
        total_gas+=netgas[idx];
        if(total_gas<0){
            can_complete=0;
            break;
        }
    }
    if(can_complete==1){
        return start;
    }

   }
   return -1;

}
//without any data structure
int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int balance=0;
        int deficit=0;
        for(int i=0;i<gas.size();i++){
            balance+=(gas[i]-cost[i]);
            if(balance<0){
                deficit+=balance;
                balance=0;
                start=i+1;
            }

        }
        if(balance+deficit>=0){
            return start;
        }
        return -1;
    }
int main(){
    vector<int>gas={1,2,3,4,5};
    vector<int>cost={3,4,5,1,2};
    cout<<canCompleteCircuit(gas,cost);
}