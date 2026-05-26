class WordDictionary {
public:
    WordDictionary *next[26];
    bool isWord;

    WordDictionary() 
    {
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
        isWord = false;
    }
    

    int findIdx(char letter)
    {
        return letter - 'a';
    }

    void addWord(string word) 
    {
        int k = 0;
        WordDictionary *cur = this;
        while (word[k] != '\0')
        {
            int idx = findIdx(word[k]);
            if (!cur->next[idx])
                cur->next[idx] = new WordDictionary();
            
            cur = cur->next[idx];
            k++;
            if (word[k] == '\0')
                cur->isWord = true;
        }
    }



    bool wrapper(WordDictionary *root, string word, int k)
    {
        if (!root) return false;
        if (word[k] == '\0') 
            return root->isWord; 

        if (word[k] == '.')
            for (int i = 0; i < 26; i++)
            {
                bool cur = wrapper(root->next[i], word, k+1);
                if (cur) return true;
                if (i == 25) return false;
            }
        return wrapper(root->next[word[k] - 'a'], word, k+1);
    }

    bool search(string word) 
    {
        return wrapper(this, word, 0);
    }
};
