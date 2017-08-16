#pragma once

#include<string>

class End {

public:
	End(int iEnd = -1) :end(iEnd) {}
	int end;
	std::string toString() {
		return std::to_string(end);
	}
};


