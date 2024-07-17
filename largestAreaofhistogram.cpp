#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int>nextsmallest(vector<int>&heights){
    stack<int>st;
    st.push(-1);
    vector<int>nextSmaller(heights.size(),-1);
    for(int i=heights.size()-1;i>=0;i--){
        while(st.top()!=-1&&heights[st.top()]>=heights[i]){
            st.pop();
        }
        nextSmaller[i]=st.top();
        st.push(i);
    }
    return nextSmaller;
}
vector<int>previoussmallest(vector<int>&heights){
    stack<int>st;
    st.push(-1);
    vector<int>previousSmaller(heights.size(),-1);
    for(int i=0;i<heights.size();i++){
        while(st.top()!=-1&&heights[st.top()]>=heights[i]){
            st.pop();
        }
        previousSmaller[i]=st.top();
        st.push(i);
    }
    return previousSmaller;
}
    int largestRectangleArea(vector<int>& heights) {
        vector<int>next=nextsmallest(heights);
        int maxArea=0;
        vector<int>previous=previoussmallest(heights);
        for(int i=0;i<heights.size();i++){
            if(next[i]==-1){
                next[i]=heights.size();

            }
            int width=next[i]-previous[i]-1;
            maxArea=max(maxArea,width*heights[i]);
        }
        return maxArea;
    }
int main(){
    vector<int>heights={2,1,5,6,2,3};
    cout<<"Largest area of histogram"<<largestRectangleArea(heights);
}