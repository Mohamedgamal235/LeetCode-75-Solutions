class Trie {
public:
    Trie* chid[26];
    bool isLeaf ;
    Trie() {
        isLeaf = false ;
        memset(chid , 0 , sizeof(chid));
    }

    void insert(string word) {
        Trie* curr = this ;
        for (auto c : word) {
            int idx = c - 'a' ;
            if(curr->chid[idx] == nullptr)
                curr->chid[idx] = new Trie();
            curr = curr->chid[idx];
        }
        curr->isLeaf = true ;
    }

    void dfs(Trie* curr , string& str , vector<string>& res) {
        if (res.size() == 3) return;
        if (curr->isLeaf)
            res.push_back(str);
        for (int c = 'a' ; c <= 'z' ; c++) {
            int idx = c - 'a' ;
            if (curr->chid[idx]) {
                str.push_back(c);
                dfs(curr->chid[idx] , str , res);
                str.pop_back();
            }
            if (res.size() == 3) return;
        }
    }

    vector<string> getWordsStartingWith(string prefix) {
        Trie* curr = this ;
        for (auto c : prefix) {
            int idx = c - 'a' ;
            if (curr->chid[idx] == nullptr) return {};
            curr = curr->chid[idx];
        }
        vector<string> res ;
        string str = prefix ;
        dfs(curr , str , res);
        return res ;
    }

};

class Solution {
public:

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin() , products.end());

        Trie trie ;
        for (auto str : products)
            trie.insert(str);

        vector<vector<string>> ans ;
        string prefix = "";
        for (auto c : searchWord) {
            prefix += c ;
            ans.push_back(trie.getWordsStartingWith(prefix));
        }
        return ans ;
    }
};
