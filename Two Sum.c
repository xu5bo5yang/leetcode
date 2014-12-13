class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map <int, int> hashTable;
        vector<int> answer;
        int temp;
        for(int i=0;i<numbers.size();i++){
            temp = target-numbers[i];
            if(hashTable.find(temp) != hashTable.end()){
                answer.push_back(hashTable[temp]+1);
                answer.push_back(i+1);
                return answer;
            }
            hashTable[numbers[i]]=i;
        }
        return answer;
    }
};