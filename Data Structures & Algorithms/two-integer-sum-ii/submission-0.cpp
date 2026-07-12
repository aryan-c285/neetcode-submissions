class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
         int h = numbers.size() -1;
         while (l< h){
            int n =numbers[l] + numbers[h];
            if (n == target ) return {l+1, h+1};
            else if (n> target) h--;
            else l++;
         }
        return{};
    }
};
