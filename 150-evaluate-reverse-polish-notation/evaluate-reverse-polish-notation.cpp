class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto t : tokens){
            if(t=="+" || t=="-" || t=="*" || t=="/"){
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                if(t=="+")
                s.push(a+b);
                else if(t=="-")
                s.push(a-b);
                else if(t=="*")
                s.push(a*b);
                else{
                    if(b!=0){
                        s.push(a/b);
                    }
                }

            }
            else{
                int num;
                stringstream ss(t);
                ss >> num;
                s.push(num);
            }
        }
        return s.top();
    }
};