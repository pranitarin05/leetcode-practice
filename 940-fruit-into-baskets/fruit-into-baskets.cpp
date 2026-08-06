class Solution {
public:
    int totalFruit(vector<int>& f){
        unordered_map<int,int> p;
        int low=0;
        int ans=0;

        for(int high=0;high<f.size();high++){
            p[f[high]]++;

            while(p.size()>2){
                p[f[low]]--;

                if(p[f[low]]==0){
                    p.erase(f[low]);
                    

                }
                low++;
                
                

        

            }
            ans=max(ans,high-low+1);

            


        }
        return ans;
        
    }
};