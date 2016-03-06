class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		const int MAX = 100000;
		int idx[MAX << 1];
		memset(idx, 0, sizeof(idx));
		vector<int> result = vector<int>(2);
		int temp;
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (temp = idx[target - nums[i] + MAX])
			{
				result[0] = temp;
				result[1] = i + 1;
				return result;
			}
			idx[nums[i] + MAX] = i + 1;
		}
	}
};