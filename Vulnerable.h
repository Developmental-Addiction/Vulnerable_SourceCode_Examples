#pragma once
#include <iostream>
#include <string>
#include <vector>

class Vulnerable {
private:
	std::string innerStr_{};

protected:
public:
	explicit Vulnerable();
	virtual ~Vulnerable() = default;

	void CopyString(std::string str);

	// Generic function names
	void func1();
	void func2();
	void func3();
	void func4();
	void func5();
	void func6();
	void func7();
	void func8();
	void func9();
	void func10();
	void func11();
	void func12();
	void func13();
	void func14();
	void func15();
	void func16();
	void func17();
	void func18();
	void func19();
	void func20();
	void func21();
	void func22();
	void func23();
	void func24();
	void func25();
	void func26();
};

