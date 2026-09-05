class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans= 0, l=0, r=heights.size()-1, n= heights.size();
        while (l<r){
            int temp;

            temp = min(heights[l], heights[r])* (r-l);
            ans = max(ans, temp);

            if (heights[l] < heights[r]){
                l++;
            }else{
                r--;
            }

        }

        return ans;
    }
};
