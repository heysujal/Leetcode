class Solution {
public:
    int removeDuplicates(vector<int>& vec) {
        // sort( vec.begin(), vec.end() );
    vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
        
        return vec.size();
    }
};