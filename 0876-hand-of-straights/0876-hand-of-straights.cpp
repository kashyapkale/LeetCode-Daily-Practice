class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int N = hand.size();
        if(N % groupSize != 0){
            return false;
        }

        map<int, int> freq_map;
        for(int i : hand){
            freq_map[i]++;
        }

        while(!freq_map.empty()){
            int start = freq_map.begin()->first;

            for(int i = 0; i < groupSize; i++){
                if(freq_map[start+i] == 0){
                    return false;
                } else{
                    freq_map[start+i]--;
                    if(freq_map[start+i] == 0){
                        freq_map.erase(start+i);
                    }
                }
            }
        }
        return true;
    }
};