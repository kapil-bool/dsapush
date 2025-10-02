class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        //batch lenge abki bar baby girl
        //same hai here just the instance is not chaniing so copy it 
         long long  answer=numBottles; //+ it in increasing one 
       long long  empty=numBottles;
    
       while(empty>=numExchange){
          //+1 only for the exchange
         //so here follow a greedy approch 
         int possible=empty/numExchange; 
         answer+=possible;
        //  empty decrease hongi and u will consume new one
        empty=possible+ (empty%numExchange);
       }
       return answer;
    }
};