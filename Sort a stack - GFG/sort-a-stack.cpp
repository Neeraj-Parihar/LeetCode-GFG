//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void getsorted(stack<int>& s,int N){
    if(s.empty() || (!s.empty() && s.top() <N)){
        s.push(N);
        return;
    }
    int cmp=s.top();
    s.pop();
    getsorted(s,N);
    s.push(cmp);
}
void SortedStack :: sort()
{
   if(s.empty()){
       return;
   }
   int N=s.top();
   s.pop();
   sort();
   getsorted(s,N);
}