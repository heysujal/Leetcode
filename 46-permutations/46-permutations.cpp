class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output; // to hold result
        generatePermutations(nums, output, 0);
        return output; // return answer
    }
private:
    void generatePermutations(vector<int> nums, vector<vector<int>>&output, int idx) {
        if (idx == size(nums)) // base case
		{ 
            output.emplace_back(nums);
        }
        for (int i = idx; i < size(nums); ++i) 
		{
            swap(nums[i], nums[idx]); // swap the current element with the next to get another permutation
            generatePermutations(nums, output, idx + 1); // generate permutations for the next element
        }
    }
};