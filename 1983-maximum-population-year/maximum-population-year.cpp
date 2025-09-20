class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
    //  lets solve this one
    //maxe one so all i have to figure out when to add and subtract
vector<pair<int,int>> str;
    for(auto &i:logs){
      str.push_back({ i[0],+1});
      str.push_back( {i[1],-1});
    }
    sort(str.begin(),str.end());
    //so now seep it 
    int current=0;
    int alive=0;
    int year=0;
    for(auto &i:str){
        current+=i.second; //added here 
        if(alive<current){
            //then 
            year=i.first;
            alive=current;
        }
    }
     return year;
    }
};