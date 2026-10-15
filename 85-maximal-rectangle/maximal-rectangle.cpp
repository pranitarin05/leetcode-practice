class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()){
            return 0;
        }
        int rows=matrix.size();
        int cols=matrix[0].size();

        vector<int> heights(cols,0);
        int maxarea=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                }else{
                    heights[j]=0;
                }
            }
            stack<int> st;

            for(int j=0; j<=cols;j++){
                int currheight=(j==cols)? 0:heights[j];

                while(!st.empty() && currheight < heights[st.top()]){
                    int height=heights[st.top()];
                    st.pop();

                    int width=st.empty()
                            ? j
                            : j-st.top()-1;

                    maxarea=max(maxarea,height*width);
                }
                st.push(j);
            }
        }
        return maxarea;
        
    }
};