#include<bits/stdc++.h>
 vector<int> prevSmallerElement(vector<int>& heights,int n){
   stack<int> s;
   vector<int> ans(n);
   s.push(-1);
   for(int i=0;i<n;i++){
     int curr=heights[i];
     while(s.top()!=-1 && heights[s.top()]>=curr){
       s.pop();
     }
     ans[i]=s.top();
     s.push(i);
   }
   return ans;
 }
 vector<int> nextSmallerElement(vector<int>& heights,int n){
   stack<int> s;
   vector<int> ans(n);
   s.push(-1);
   for(int i=n-1;i>=0;i--){
     int curr=heights[i];
     while(s.top()!=-1 && heights[s.top()]>=curr){
       s.pop();
     }
     ans[i]=s.top();
     s.push(i);
   }
   return ans;
 }
 
 int largestRectangle(vector < int > & heights) {
   int n=heights.size();
   vector<int> next(n);
   next=nextSmallerElement(heights,n);
   vector<int> prev(n);
   prev=prevSmallerElement(heights,n);
   int area=0;
   for(int i=0;i<n;i++){
     int length=heights[i];
     if(next[i]==-1){
       next[i]=n;
     }
     int breadth=next[i]-prev[i]-1;
     int newArea=length*breadth;
      area=max(newArea,area);
   }
   return area;
 }
