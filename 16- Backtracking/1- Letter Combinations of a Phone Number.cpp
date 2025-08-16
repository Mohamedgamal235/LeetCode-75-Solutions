class Solution {
public:
    vector<string> ans ;
    unordered_map<char, string> mp = {
        {'2',"abc"}, {'3',"def"},
        {'4',"ghi"}, {'5',"jkl"},
        {'6',"mno"}, {'7',"pqrs"},
        {'8',"tuv"}, {'9',"wxyz"}
    };

    void backtrack(string &digits , int idx , string str) {
        if (idx == digits.size()) {
            ans.push_back(str);
            return;
        }

        for (auto c : mp[digits[idx]])
            backtrack(digits , idx + 1 , str + c);
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {} ;
        backtrack(digits , 0 , "");
        return ans ; 
    }
};