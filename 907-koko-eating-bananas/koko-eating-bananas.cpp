class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int largestpile=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i] > largestpile){
                largestpile=piles[i];
            }
        }
        int low=1;
        int high=largestpile;

        while(low <= high){
            int mid=low+(high-low)/2;

            long long totalhours=0;
            for(int i=0; i<piles.size(); i++){
                int hoursforpile=(piles[i] +mid-1)/mid;
                totalhours = totalhours + hoursforpile;
            }
            if(totalhours <= h){
                high=mid-1;

            }
            else
            low=mid+1;
        }
        return low;
        
    }
};