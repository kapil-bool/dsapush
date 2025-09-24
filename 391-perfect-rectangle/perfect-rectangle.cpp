class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        //negative inputs are also a possiblitie here so manage accordingly
        //geomtry hai isme majorly so 
        //final area(4 points  se ayega) and the the other one is actuall area here if and only if they ARE == if 1
        //points are more than 4 then also also like imagine it like a rectange and other rectange get attach to it so points of this + th eprevios one  here it will be 5 
        //these 5 points can more like can be ta=sted like if they are comman that is already there (set) u dont include it and pop them sa they are the boundary one now a new boundary is introduced
        long long Tarea=0;
        int minX = INT_MAX, minY = INT_MAX;
        int maxX = INT_MIN, maxY = INT_MIN;
        set<pair<int,int>>boundries;
        for(auto &i:rectangles){
            //what to do here 
            //area calci
            int x1=i[0];
            int x2=i[2];
            int y1=i[1];
            int y2=i[3]; //u got them all area now
            //update them also
            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);
            Tarea+=(long long)(x2-x1)*(y2-y1); //ok lets goo
            //if these 4 are not in the boundries add them if any one is there pop is 
             vector<pair<int,int>> pts = {{x1,y1}, {x1,y2}, {x2,y1}, {x2,y2}};
             for(auto &j:pts){
                  if(boundries.find(j)==boundries.end()){
                    //insert it 
                     boundries.insert(j);
                  }
                  else{
                    boundries.erase(j);
                  }
             }

        }
        //claarea? nedd oints that to final one so need a strutrre which get me 4 points and update with every new one 
        //set?
        long long calarea=(long long)(maxX - minX) * (maxY - minY);
        if(Tarea!=calarea) return false;
        if(boundries.size()!=4) return false; //deformed hai 
        
        //gpt condtion i forget it it says i should also check that the min and max boundries here should be there else 
        // return false
        if (!boundries.count({minX, minY})) return false;
        if (!boundries.count({minX, maxY})) return false;
        if (!boundries.count({maxX, minY})) return false;
        if (!boundries.count({maxX, maxY})) return false;


       return true;
    }
};