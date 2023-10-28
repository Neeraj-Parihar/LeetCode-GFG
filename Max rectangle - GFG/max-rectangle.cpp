//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    private:
    
    vector<int> prevSmallerElement(int* M, int n){
        stack<int> s;
        vector<int> ans(n);
        s.push(-1);
        for(int i=0;i<n;i++){
            while(s.top()!=-1 && (M[s.top()]>=M[i])){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> nextSmallerElement(int* M, int n){
        stack<int> s;
        vector<int> ans(n);
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            while(s.top()!=-1 && (M[s.top()]>=M[i])){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangle(int* M,int n){
        vector<int> next;
        vector<int> prev;
        next=nextSmallerElement(M,n);
        prev=prevSmallerElement(M,n);
        int maxArea=0;
        for(int i=0;i<n;i++){
            int l=M[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int area=l*b;
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int area=largestRectangle(M[0],m);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]!=0)
                    M[i][j]+= M[i-1][j];
                else
                    M[i][j]=0;
            }
            area=max(area,largestRectangle(M[i],m));
        }
        return area;
    }
    
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends