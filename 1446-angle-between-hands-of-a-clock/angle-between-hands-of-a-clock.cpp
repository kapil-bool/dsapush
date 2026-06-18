typedef double dd;
class Solution {
public:
    double angleClock(int hour, int minutes) {
        //totola= 360/(5*12)=
        //1/12*minutes postion of hour hand will be obatinde 
        // directly add nahi kar
        //2 differnces will be here outer and inner 
        //take refence also
        //12 -12
        dd anglemin=minutes*6;
        if(hour==12) hour=0;
        dd hourc=hour*30;
        dd xpos=(1.0/12)*minutes * 6;
        dd finalpos=hourc+xpos;
        dd a1=abs(anglemin-finalpos);
        dd a2=360-a1;
        return min(a1,a2);

    }
};