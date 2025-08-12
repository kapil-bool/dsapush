class Solution {
public:
    vector<int> helper(string expression, unordered_map<string, vector<int>> &mp) {
        // If already computed, return from memo
        if (mp.count(expression)) return mp[expression];

        // Base case: check if purely numeric
        bool is_numeric = true;
        for (char c : expression) {
            if (!isdigit(c)) {
                is_numeric = false;
                break;
            }
        }
        if (is_numeric) {
            return {stoi(expression)}; //for calulation change it now
        }

        vector<int> ans;
        int n = expression.size();

        for (int i = 0; i < n; i++) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                
                vector<int> left = helper(expression.substr(0, i), mp);
                vector<int> right = helper(expression.substr(i + 1), mp);

                //divide it and store and calulate it
                for (int a : left) {
                    for (int b : right) {
                        if (c == '+') ans.push_back(a + b);
                        else if (c == '-') ans.push_back(a - b);
                        else if (c == '*') ans.push_back(a * b);
                    }
                }
            }
        }

       
        mp[expression] = ans;
        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> mp;
        return helper(expression, mp);
    }
};

       //so here check for the sign and create a tree against int with leaf nodesas the alphabatic one and arthematic one as the inner node 
       //once u reach the end compute it and return 
       //check for all the sub string both to the left and right
       //base case is if the substring is only num
       //so to store the answer for a particular +,-,*