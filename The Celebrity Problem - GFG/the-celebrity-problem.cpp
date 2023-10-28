//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    private:
    bool knows(vector<vector<int>>& M,int A,int B){
        if(M[A][B]==1){
            return true;
        }
        return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        while(s.size()>1){
            int A=s.top();
            s.pop();
            int B=s.top();
            s.pop();
            if(knows(M,A,B)){
                s.push(B);
            }
            else{
                s.push(A);
            }
        }
        int C=s.top();
        //single element in the stack is the potential candidate
        // check rows if zero and then check if all knows celebrity or not
        int rowcount=0;
        for(int i=0;i<n;i++){
            if(M[C][i]==0){
                rowcount++;
            }
        }
        if(rowcount!=n){
            return -1;
        }
        //column check
        int onecount=0;
        for(int i=0;i<n;i++){
            if(M[i][C]==1){
                onecount++;
            }
        }
        if(onecount!=n-1){
            return -1;
        }
        return C;
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends