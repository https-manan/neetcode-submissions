class Solution {
public:
    bool isNumber(string &s){
        return !(s == "+" || s == "-" || s == "*" || s == "/");
    }
    int op(int a, int b, string oper){
        if(oper == "+") return a + b;
        if(oper == "-") return a - b;
        if(oper == "*") return a * b;
        return a / b;
    }
    int evalRPN(vector<string>& t){
        stack<int>s;
        for(int i=0;i<t.size();i++){
            if(isNumber(t[i])){
                s.push(stoi(t[i]));
            }else{
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int c=op(b,a,t[i]);
                s.push(c);
            }
        }
        return s.top();
    }
};
