#pragma once
#include <iostream>
#include <string>


class Vulnerable {
private:
	std::string innerStr_{};

protected:
public:
	explicit Vulnerable();
	virtual ~Vulnerable() = default;

	void CopyString(std::string str);
};

