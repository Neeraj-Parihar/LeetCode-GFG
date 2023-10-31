class Solution{
    stack<pair<int,int>> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(s.empty()) return -1;
           return s.top().second;
           //Write your code here
       }
       
       /*returns poped element from stack*/
       int pop(){
            if(s.empty()) return -1;
            int a = s.top().first;
            s.pop();
            return a;
            //Write your code here
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(s.empty()) s.push({x,x});
           else s.push({x,min(s.top().second,x)});
           //Write your code here
       }
}
