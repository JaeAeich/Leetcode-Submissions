class Solution {
public:
    //calculates 
    int evaluate(int a, int b, string op){
        map<string,int> m;
        m["+"]=1;
        m["-"]=2;
        m["*"]=3;
        m["/"]=4;
        if(m[op]==1){
            return a+b;
        }
        else if(m[op]==2){
            return a-b;
        }
        else if(m[op]==3){
            return a*b;
        }
        else return a/b;
    }
    
    //returns if string is operator
    bool isOp(string c){
        map<string,int> m;
        m["+"]=1;
        m["-"]=2;
        m["*"]=3;
        m["/"]=4;
        return m[c];
    }
    
    //driver code
    int evalRPN(vector<string>& v) {
        int ans=0;
        stack<int> s;

        for(int i=0;i<v.size();i++){
            //if ele is not an operator, push the num to stack.
            if(!isOp(v[i])){
                s.push(stoi(v[i]));
            }
            //else operate on it and push onto stack.
            else{
                int a=(s.top());
                s.pop();
                int b=(s.top());
                s.pop();
                s.push(evaluate(b,a,v[i]));
            }
        }
        return (s.top());
    }
};