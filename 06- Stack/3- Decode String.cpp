class Solution {
public:
    string decodeString(string s) {
        stack<int> nums ;
        stack<string> st ;
        string ans = "" ;
        int times = 0 ;
        for (auto c : s) {
            if (isdigit(c))
                times = times * 10 + (c - '0');
            else if (c == '[') {
                nums.push(times);
                st.push(ans);
                ans = "" ;
                times = 0 ;
            }
            else if (c == ']') {
                int n = nums.top();
                nums.pop();
                string curr = st.top();
                st.pop();
                while (n--)
                    curr += ans ;
                ans = curr ; 
            }
            else
                ans += c ;
        }
        return ans ; 
    }
};