class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s) ;
        string str ;
        vector<string> strs ;

        while (ss >> str)
            strs.push_back(str);

        reverse(strs.begin() , strs.end());

        string ans ;
        for (int i = 0 ; i < strs.size() ; i++) {
            if (i > 0)
                ans += ' ' ;
            ans += strs[i];
        }

        return ans ; 
    }
};