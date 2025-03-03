class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> preArray;
        vector<int> postArray;
        vector<int> equalArray;

        for(int num : nums){
            if(num < pivot){
                preArray.push_back(num);
            } else if(num > pivot){
                postArray.push_back(num);
            } else{
                equalArray.push_back(num);
            }
        }

        vector<int> ans;
        for(int num : preArray){
            ans.push_back(num);
        }

        for(int num : equalArray){
            ans.push_back(num);
        }

        for(int num : postArray){
            ans.push_back(num);
        }

        return ans;
    }
};