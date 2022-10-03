class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        priority_queue<int,vector<int>,greater<int>>q;
        int n = colors.size();
        int time=0;
        if(n==1)
            return neededTime[0];
        
        for(int i=0 ;i<n ;i++)
        {
            while(colors[i]==colors[i+1])
            {
                q.push(neededTime[i]);
                i++;
            }
            q.push(neededTime[i]);
            
            while(q.size()>1)
            {
                time=time+q.top();
                q.pop();
            }
            q.pop();
        }
        return time;
    }
};