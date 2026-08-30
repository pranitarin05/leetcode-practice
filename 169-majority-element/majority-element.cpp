class Solution {
public:
    int majorityElement(vector<int>& a) {
        int maj=a[0],votes=1;
        for(int i=1;i<a.size();i++){
            if(votes==0){
                votes++;
                maj=a[i];
            }
            else if(maj==a[i]){
                votes++;
            }
            else
            votes--;
        }
        return maj;
        
    }
};