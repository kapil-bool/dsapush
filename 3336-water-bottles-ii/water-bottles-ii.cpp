class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
       //drink all and start exchanging i guess this will work and icrease the count
       int answer=numBottles; //+ it in increasing one 
       int empty=numBottles;
       int instanceofnumExchange=numExchange;
       while(empty>=instanceofnumExchange){
          //+1 only for the exchange
          answer++;
          empty-=instanceofnumExchange;
          instanceofnumExchange++;
        //   now u will also consume the bottle here
          empty++;
       }
       return answer;
    }
};