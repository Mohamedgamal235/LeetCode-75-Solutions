class Solution {
    public:
        int compress(vector<char>& chars) {
            map<char , int> freq ; 
    
            for (auto c : chars)
                freq[c]++ ;
            string str = "" ; 
            for (auto [c , value] : freq) {
                if (freq[c] == 1)
                    str += c ;
                else if (freq[c] > 1) {
                    str += c ;
                    str += to_string(value);
                }
            }
    
            return str.size();
        }
    };