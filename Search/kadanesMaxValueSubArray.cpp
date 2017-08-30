	/* https://www.youtube.com/watch?v=86CQq3pKSUw */
	int maxSubArrayKadane(vector<int>& nums) {

		if (nums.size() < 0) return 0;

		int max_current, maxglobal;
		max_current = maxglobal = nums[0];

		// iterate through elements
		for (int i = 1; i < nums.size(); ++i) {
			max_current = max(nums[i], max_current + nums[i]);

			if (max_current > maxglobal) maxglobal = max_current;
		}

		return maxglobal;
	}