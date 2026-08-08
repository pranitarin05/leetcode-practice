class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>need;
        unordered_map<char,int>window;
        for(char c:t){
            need[c]++;
        }
        int left=0;
        int formed=0;

        int minlen=INT_MAX;
        int start=0;

        for(int right=0;right<s.size();right++){
            char c= s[right];
            window[c]++;

            if(need.count(c) && window[c] <= need[c]){
                formed ++;
            }
            while(formed == t.size()){
                if((right-left+1)<minlen){
                    minlen=right-left+1;
                    start=left;
                }
                char ch=s[left];
                window[ch]--;

                if(need.count(ch) && window[ch] < need[ch]){
                    formed --;
                }
                left ++;
            }
        }
        if(minlen == INT_MAX){
            return "";
        }else{
            return s.substr(start,minlen);
        }
        
    }
};