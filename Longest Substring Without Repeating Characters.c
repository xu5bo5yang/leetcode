class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer=0;
        int maxLength=0;
        map<char, int> hashTable;
        hashTable.clear();
        if(s.size()==0) return 0;
        for(int i=0;i<s.size();i++){
            if(hashTable.find(s[i])==hashTable.end()){
                answer++;
                hashTable.insert(pair<char, int>(s[i], i));
            }
            else{
                if(maxLength<answer) maxLength=answer;
                while(hashTable[s[i+1]]==hashTable[s[i]]+1){
                    i++;
                }
                i=hashTable[s[i]];
                hashTable.clear();
                answer=0;
            };
        }
        if(maxLength<answer) maxLength=answer;
        return maxLength;
    }
};