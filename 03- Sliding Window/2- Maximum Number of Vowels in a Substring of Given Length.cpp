class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'o' || c == 'i' || c == 'u' || c == 'e';
    }
    int maxVowels(string s, int k) {
        int ans = 0;
        for (int i = 0; i < k; i++)
            if (isVowel(s[i]))
                ans++;
        int maxi = ans;
        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i - k]))
                ans--;
            if (isVowel(s[i]))
                ans++;
            maxi = max(maxi, ans);
        }
        return maxi;
    }
};
