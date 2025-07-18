class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //so all possiblites from a to z and ans also seach it in the current one and one u find it pop it 
        //as soon as u find its +1
        /*Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
  see this even after finding u have to applly all a to z */
       unordered_set<string> store(wordList.begin(), wordList.end());
       queue<pair<string,int>>q;
      if (store.find(endWord) == store.end()) return 0;
       q.push({beginWord,1});


       //now start as discussed
       while(!q.empty()){
         auto [word, len] = q.front();
         q.pop();
        if (word == endWord) return len;
         
         for(int i=0;i<word.size();i++){
            string temp=word;
            for(char ch='a';ch<='z';ch++){
               temp[i]=ch;// change;
               //now see if u find it in the set
               if(store.find(temp)!=store.end()){
                 q.push({temp,len+1});
                 //and also remove from the set;
                 store.erase(temp);
               }
            }
         }
       }
       //return the word if u find the temp u find is in the set then return the len
         return 0;
    }
};