class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int pointer1 = 0;
        int pointer2 = 0;
        vector<vector<int>> ans;
        while(pointer1 < len1 && pointer2 < len2){
            int id1 = nums1[pointer1][0];
            int id2 = nums2[pointer2][0];
            
            if(id1 == id2){
                ans.push_back({id1, nums1[pointer1][1] + nums2[pointer2][1]});
                pointer1++;
                pointer2++;
            } else if(id1 < id2){
                ans.push_back(nums1[pointer1]);
                pointer1++;
            } else{
                ans.push_back(nums2[pointer2]);
                pointer2++;
            }
        }

        while(pointer1 < len1){
            ans.push_back(nums1[pointer1]);
            pointer1++;
        }

        while(pointer2 < len2){
            ans.push_back(nums2[pointer2]);
            pointer2++;
        }

        return ans;
    }
};