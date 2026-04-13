class Solution {
public:
    int evalRPN(vector<string>& t) {
     stack<int> st;
        for (auto &tok : t) {
            if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int res;
                if (tok == "+") res = a + b;
                else if (tok == "-") res = a - b;
                else if (tok == "*") res = a * b;
                else { 
                     res = a / b;
                }
                st.push(res);
            } else {
                st.push(stoi(tok));
            }
        }
        return st.top();
    }
};
