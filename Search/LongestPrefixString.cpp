string longestCommonPrefix(vector<string>& strs) {
	int size = numeric_limits<int>::max();

	if (strs.size() == 0) return "";

	if (strs.size() == 1) return strs[0];

	// shortest string O(n)
	for (auto& a : strs) {
		size = size > a.size() ? a.size() : size;
	}
	
	int count = 0;
	// From 0 to size, compare vertically
	while(count < size) {
		for (size_t x = 1; x < strs.size(); ++x) {
			if (strs[x][count] != strs[0][count]) {
				return strs[0].substr(0,count);
			}
		}
		count++;
	}
	
	return strs[0].substr(0,size);
}
