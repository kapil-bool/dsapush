class Solution {
public:
    long long flowerGame(int n, int m) {
        //lets see what can i do here
        //there are no flower left at all this mean both lanes are empty 
        //there for w 1->3->5->7->9 so odd is the key here now number of ways 
        long long oddN = (n + 1) / 2; // number of odd x in [1..n]
        long long evenN = n / 2; // number of even x in [1..n]
         long long oddM = (m + 1) / 2; // number of odd y in [1..m]
        long long evenM = m / 2; // number of even y in [1..m]

return oddN * evenM + evenN * oddM;
    }
};