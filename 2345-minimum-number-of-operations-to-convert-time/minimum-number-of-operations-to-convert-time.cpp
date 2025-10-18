class Solution {
public:
  int converter(string &s){
      int number=0;
      for(int i=3;i<5;i++){
        //  int x=stoi(s[i]);
         int x = s[i] - '0';
         number=number*10+x;

      }
      return number;
  }
  int hourminute(string &s){
    int number=0;
    for(int i=0;i<2;i++){
          int x = s[i] - '0';
         number=number*10+x;
    }
    return number*60;
  }
    int convertTime(string current, string correct) {
        //should i convert it in minutes ?
        //LAST to are minutes and firt one will be x*60
        int cu_m=hourminute(current)+converter(current);
        int c_m=hourminute(correct)+converter(correct);

        int differ=c_m -cu_m;  //done now see the minutes;
        
        // current <= correct
        //take modulo wiyh all 4
        int zns=0;
        //60 one
        zns+=(differ/60);
        differ%=60;
        zns+=(differ/15);
        differ%=15;
        zns+=(differ/5);
        differ%=5;
        zns+=(differ/1);
        differ%=1;

        return zns;
     

        

    }
};