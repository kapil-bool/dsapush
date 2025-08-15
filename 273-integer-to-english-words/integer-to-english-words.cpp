class Solution {
public:
vector<string> below20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                              "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                              "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
    string helper(int num){
        if(num==0){
            //basically all are zero here
            return "";
        }
        //count variable accesing the thousands
        else if(num<20){
            //index are placed so will shoud ppush the index
            return below20[num] + " ";
        }
        else if(num<100){
            return tens[num/10]+" "+helper(num%10);
        }
        else return below20[num/100]+" Hundred "+ helper(num%100);
    }
    string numberToWords(int num) {
        /*lets see this one last for today*/
        /* %1000 here and after that just obtain what u want 
        1-20
        30-40-50-60-90
        */
        if(num==0) return "Zero";
        string ans="";
        int idx=0;
        while(num>0){
            //1000 modulo it and procede
            int checker=num%1000;
            if(checker!=0){
                ans=helper(checker)+thousands[idx]+" " + ans;
            }
            num=num/1000;
            idx++;

        }
        //there may be spaces at end so remove themm
        while(!ans.empty() and ans.back()==' ') ans.pop_back();

        return ans;
    }
};