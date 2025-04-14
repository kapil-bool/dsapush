class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
       //lets start baby girl 
       //0 <= i < j < k < arr.length
       //    |arr[i] - arr[j]| <= a
       // |arr[j] - arr[k]| <= b
       // |arr[i] - arr[k]| <= c
       int count=0;
       //    is n^3 the only approch
       int n=arr.size();
       for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                  if (abs(arr[i] - arr[j]) <= a &&
                        abs(arr[j] - arr[k]) <= b &&
                        abs(arr[i] - arr[k]) <= c)
                        count++;
            }
         }
       }
       return count;
    }
};