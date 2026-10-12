class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        if (s.empty() || words.empty())
            return ans;

        int n = s.size();
        int wordLen = words[0].size();
        int totalWords = words.size();
        int windowLen = wordLen * totalWords;

        if (n < windowLen)
            return ans;

        unordered_map<string, int> wordCount;

        for (string word : words) {
            wordCount[word]++;
        }

        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> seen;

            for (int right = i; right + wordLen <= n; right += wordLen) {
                string word = s.substr(right, wordLen);

                if (wordCount.find(word) != wordCount.end()) {
                    seen[word]++;
                    count++;

                    while (seen[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == totalWords) {
                        ans.push_back(left);

                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return ans;
    }
};