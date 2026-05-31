class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long currMass = mass;

        for (int x : asteroids) {
            if (currMass < x)
                return false;

            currMass += x;
        }

        return true;
    }
};