class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (isVowel(s[l]) && isVowel(s[r])) {
                char c = s[l];
                s[l] = s[r];
                s[r] = c;
                l++;
                r--;
            } else if (!isVowel(s[l])) {
                l++;
            } else if (!isVowel(s[r])) {
                r--;
            }
        }
        return s;
    }
};
