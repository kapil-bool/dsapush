class Solution {
public:
    int minOperations(string s1, string s2) {
        if(s1.size()==1 && s2.size()==1){
            if(s1[0]==s2[0])return 0;
            if(s1[0]=='0' && s2[0]=='1')return 1;
            return -1;
        }
        int ans=0;
        //if last then +2 else see the I+1 condtion 
        
        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[i])continue;
            else{
                if(s1[i]=='0' && s2[i]=='1'){
                    ans++;
                    s1[i]='1';
                }
                else if(s1[i]=='1' && s2[i]=='0'){
                    if(i+1<s1.size() && s1[i+1]=='1'){
                        ans++;
                        s1[i]='0';
                        s1[i+1]='0';
                    }
                    else if(i+1<s1.size() && s1[i+1]=='0'){
                        ans+=2;
                        s1[i]='0';
                    }
                    //compressedd both here 
                    else if(i-1>=0){
                        ans+=2;
                        s1[i]='0';
                    }
                }
            }
        }
        return ans;
    }
};