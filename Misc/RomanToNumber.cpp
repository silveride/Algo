
// Input should be "MXIV" etc

int RomanToNumbers(string str) {
	int sum = 0;

	unordered_map<char, int> num_map = {
		{'M',1000},
		{ 'D',500 },
		{ 'C',100 },
		{ 'L',50 },
		{ 'X',10 },
		{ 'V',5 },
		{ 'I',1},
	};

	auto prev = 0;

	for (auto& x : str) {
		
		sum += (num_map[x] <= num_map[prev] ? num_map[x] : num_map[x] -2* num_map[
prev]);
		prev = x;
	}

	return sum;
}