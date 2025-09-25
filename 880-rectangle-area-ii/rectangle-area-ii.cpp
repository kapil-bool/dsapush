class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        // here actullay line sweep will work so lets go 
        // its a 2d seep so let me visulaise it how to change in 1d 
        // lets leran the 2d sweep and then we can calulate it 
        const int MOD=1e9+7;
        // damm man this is actuallt tough
        vector<tuple<int,int,int,int>>events;
        // index type y cordinates that how it is 
        set<int>ally; // here all unique will be there 
        for(auto &i:rectangles){
            int x1=i[0],x2=i[2],y1=i[1],y2=i[3];
            events.push_back({x1,y1,y2,1});
            events.push_back({x2,y1,y2,-1});
            ally.insert(y1);
            ally.insert(y2);
        }
        // now creaton and all is done 
        // now compression is there  of the y axis 
        // sorting is there 
        unordered_map<int,int>ymap;
        sort(events.begin(), events.end());
        vector<int> yCoords(ally.begin(), ally.end()); // it will also conatin alll uniqye y
        for(int i=0;i<ally.size();i++){
            ymap[yCoords[i]]=i; // so sorted order me ho gaya iska kaam to
        }
        // now sweep i need delta x here 
        long long ans=0;
        vector<int> count(yCoords.size(), 0);
        int prevx=get<0>(events[0]); // damm this is good way to acces one 
        for(auto& [x,y1,y2,type] : events){
            long long curY = 0;
            // calculate the length of active y-intervals 
            for (int i = 0; i < yCoords.size()-1; ++i) {
                if (count[i] > 0)
                    curY += yCoords[i+1] - yCoords[i];
            }
            // area contribution = covered y * delta x
            ans = (ans + curY * (x - prevx)) % MOD;
            // update the active segments based on event type
            for(int i=ymap[y1]; i<ymap[y2]; i++){
                count[i]+=type;
            }
            prevx=x;
        }
        return (int)ans;
    }
};
