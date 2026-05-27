class PrefixTree {
public:
    PrefixTree *children[26];
    bool isWord;

    PrefixTree() 
    {
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isWord = false;
    }
    
    void insert(string word) 
    {
        PrefixTree *cur = this;
        int k = 0;
        
        while(word[k] != '\0')
        {
            if (!cur->children[word[k] - 'a'])
                cur->children[word[k] - 'a'] = new PrefixTree();
            cur = cur->children[word[k] - 'a'];
            k++;
            
            if (word[k] == '\0')
                cur->isWord = true;
        }
        
    }
    
    bool wrapper(PrefixTree *root, string word, int k)
    {
        
        if (!root) return false;
        if (word[k] == '\0') return root->isWord;
        
        return wrapper(root->children[word[k] - 'a'], word, k+1);
    }

    bool search(string word) 
    {
        PrefixTree *cur = this;
        return wrapper(cur, word, 0);
    }
    
    bool startsWith(string prefix) 
    {
        PrefixTree *cur = this;
        int x = prefix.length();

        int k = 0;
        while(k != x)
        {
            if(cur->children[prefix[k] - 'a'])
                cur = cur->children[prefix[k] - 'a'];
            else
                return false;
            k++;
        }
        return true;
    }
};
