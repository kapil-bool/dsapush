class Solution {
public:
    int numberOfSubstrings(string s) {
        //2 pointer sliding window yehi hoga ig
        //lets go
        //if more than 200 zeroes consecutively are there this will mean no way a string can be considered 
        //i need to see both left and right range from a certain 1
        //THIS IS QUESTION IS JUST SO ELEGENTLY DESIGNED
        
        vector<int> zero_index;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') zero_index.emplace_back(i); //sorted 0(n);
        }
        //now make a window over the zeroindex
        int ones = n - zero_index.size(); 
        zero_index.push_back(n); 
        int index = 0;
        int answer = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = index; j < (int)zero_index.size() - 1; j++) {
                 int no_of0 = j - index + 1;
                 
                 //sqrt(n) bound ~200
                 if (no_of0 > 200) break; //no way;
                 
                 //now if that condtion is passed count ones n-no fo zeroes -1 as u have already added 1 
                 int right_zero = zero_index[j];
                 int noof_ones = right_zero - i - (no_of0 - 1);
                 
                 if (no_of0 * no_of0 <= noof_ones) {
                    answer += zero_index[j + 1] - zero_index[j];
                 }
                 else {
                    //u need more 1
                    int need = (no_of0 * no_of0) - noof_ones;
                    //ya to next 0 wale tak satisfy ho jaye else skipp this one only
                    answer += max(0, (zero_index[j + 1] - zero_index[j]) - need);
                 }
            }
            
            if (s[i] == '0') {
                index++; //increse the right pointer here
            }
            else {
                //1 hoga include it in answer
                answer += zero_index[index] - i;
                ones--;
            }
        }
        
        return answer;
    }
};