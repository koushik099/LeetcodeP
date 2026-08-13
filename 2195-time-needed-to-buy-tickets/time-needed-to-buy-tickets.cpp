class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int totaltime= 0;
        for(int i=0;i<=k;i++){
            totaltime += min(tickets[i],tickets[k]);
        }
        for(int i=k+1;i<tickets.size();i++){
          totaltime += min(tickets[i], tickets[k]-1) ; 
        }
        
   return totaltime;
    }
    
};