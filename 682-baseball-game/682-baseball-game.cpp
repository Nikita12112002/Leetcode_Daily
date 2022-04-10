class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        vector<int>ans;
        int j=0;
        for(int i=0 ; i<ops.size() ;i++)
        {
            if(ops[i]=="D")
            {
                ans.push_back(ans.back()*2);
                j++;
            }
            
            else if(ops[i]=="C")
            {
                ans.pop_back();
                j--;
            }
            
            else if(ops[i]=="+")
            {
               ans.push_back(ans[j-1]+ans[j-2]);
                j++;
            }
            
            else 
            {
                ans.push_back(stoi(ops[i]));
                j++;
            }
        }
        int sum=0;
       for(int i=0 ;i<ans.size();i++)
       {
           sum = sum +ans[i];
       }
        return sum;
    }
};