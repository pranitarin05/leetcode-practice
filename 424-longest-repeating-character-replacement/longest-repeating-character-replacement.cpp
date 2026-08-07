class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>f;
        int low=0;
        int maxfreq=0;
        int ans=0;

        for(int high=0;high<s.size();high++){
            f[s[high]]++;
            maxfreq=max(maxfreq,f[s[high]]);
            

            while(((high-low+1)-maxfreq)>k){
                f[s[low]]--;
                low++;
            }
            ans=max(ans,(high-low+1));

        }
        return ans;
        
    }
};