class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                sk.push(ch);
            }
            else{
                if(!sk.empty()){
                    char top=sk.top();
                    if((ch==')' && top=='(') || (ch==']' && top=='[') || (ch=='}' && top=='{')){
                        sk.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
    if(sk.empty())
        return true;
    else
        return false;
    }
    
};