//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void middelete(stack<int>&s,int count, int sizeOfStack){
        if(count==sizeOfStack/2){
            s.pop();
            return;
        }
        int e=s.top();
        s.pop();
        count++;
        middelete(s,count,sizeOfStack);
        s.push(e);
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int count=0;
        middelete(s,count,sizeOfStack);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends