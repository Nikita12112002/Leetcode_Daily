class Solution {
public:
    // BFS traversal
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string,int>>q;
        int steps=1 ;
        q.push({beginWord,steps});
        unordered_set<string>s(wordList.begin(),wordList.end());
        
           
        while(!q.empty())
        {
            string word = q.front().first;
            steps = q.front().second;
             q.pop();
            if(word==endWord)
                return steps;
            
            for(int i=0 ;i<word.size();i++)
            {
                char original = word[i];
                
                for(char ch='a' ; ch<='z' ; ch++)
                {
                    word[i]=ch;
                    
                    if(s.find(word)!=s.end())
                    {
                       s.erase(word);
                        q.push({word,steps+1});
                    }
                }
                
                word[i]=original;
            }
        }
        
        return 0;
    }
};