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

    bool search(string word) {
        Trie* curr = this ;
        for (auto c : word) {
            int idx = c - 'a';
            if (curr->chid[idx] == nullptr)
                return false;
            curr = curr->chid[idx];
        }
        return curr->isLeaf;
    }

    bool startsWith(string prefix) {
        Trie* curr = this ;
        for (auto c : prefix) {
            int idx = c - 'a';
            if (curr->chid[idx] == nullptr)
                return false;
            curr = curr->chid[idx];
        }
        return true;
    }
};