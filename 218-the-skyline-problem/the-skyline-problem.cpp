class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        //ok what it is demanging is the outer most points with no 2 points in the same line that is the y axis is same for them 
        vector<pair<int,int>>events;
        for(auto &i: buildings){
             int ent=i[0],exit=i[1],height=i[2];
             events.push_back({ent,-height});
             events.push_back({exit,height});
        }
        //sort them
        //on the basis of xCORDINATE
           sort(events.begin(), events.end(), [](auto &a, auto &b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second; // negative heights come first
        });
        vector<vector<int>>ans;
    //need a  way to calulate the height 
       multiset<int>heights;
       heights.insert(0);
       int prevMax=0;
       for(auto &[x,h]:events){
         //this is the main one here 
         //how to design the heights here 
         //its more like a heigher hight add it always and when it will be falling it will crete a new points from its below running one  if its the peak in
         //so more height 
         //now the twist is negative one will be before
         if(h<0){
            heights.insert(-h); //making it posive 
         }
         else{
            //this means it is a running one also 
            heights.erase(heights.find(h)); //else remove the starting one here 
            //thiss is how the active one are mentioned 
            //suiii

         } 
         int curMax = *heights.rbegin(); //this is the heightst one;
         //if a new max is there for sure insert it in 
         if(curMax!=prevMax){
            //current wale ko anwer me push karo an
            ans.push_back({x,curMax});
            prevMax=curMax;
         }
       }
        return ans;
    }
};