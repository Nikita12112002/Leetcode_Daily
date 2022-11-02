class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
     
           
        queue<pair<string,int>>q;
        int steps=0;
        q.push({start,steps});
        unordered_set<string>s(bank.begin(),bank.end());
        s.erase(start);
        vector<char>v={'A','C','G','T'};
           
        while(!q.empty())
        {
            string word = q.front().first;
            steps = q.front().second;
             q.pop();
            if(word==end)
                return steps;
            
            for(int i=0 ;i<word.size();i++)
            {
                char original = word[i];
                
                for(int j=0 ; j<4 ;j++)
                {
                    word[i]=v[j];
                    
                    if(s.find(word)!=s.end())
                    {
                       s.erase(word);
                        q.push({word,steps+1});
                    }
                }
                
                word[i]=original;
            }
        }
        
        return -1;
    }
};