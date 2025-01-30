class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        if(digits[n-1] != 9){
            digits[n-1]++;
            return digits;
        } else{
            bool isAllNine = true;
            int nonNineIndex = 0;
            for(int index = n - 1; index >= 0; index--){
                int i = digits[index];
                if(i != 9){
                    isAllNine = false;
                    nonNineIndex = index;
                    break;
                }
            }

            if(isAllNine){
                ans.push_back(1);
                for(int i = 0; i < n; i++){
                    ans.push_back(0);
                }
                return ans;
            } else{
                for(int i = 0; i < n; i++){
                    if(i < nonNineIndex){
                        ans.push_back(digits[i]);
                    } else if(i == nonNineIndex){
                        ans.push_back(digits[i] + 1);
                    } else{
                        ans.push_back(0);
                    }
                }

                return ans;
            }

            return ans;
        }      
    }
};