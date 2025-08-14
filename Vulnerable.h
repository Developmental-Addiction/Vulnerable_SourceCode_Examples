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

	// Parameterized generic function names
	void func1(const char* input);
	void func2(char* buf, size_t bufSize);
	void func3(char* buf, const char* input);
	void func4(const char* input, size_t heapSize);
	void func5(const int* arr, size_t arrSize, size_t index);
	void func6(unsigned int x);
	void func7(unsigned int x);
	void func8(char* buf, size_t bufSize);
	void func9(short s, char* buf, size_t bufSize);
	void func10(int len, const char* src, char* dest);
	void func11(int* p);
	void func12(int x);
	void func13(int* p);
	void func14(int* arr);
	void func15(const char* filename);
	void func16(int* arr, size_t arrSize, size_t index, int value);
	void func17(const std::vector<int>& v, size_t index);
	void func18(char* buf, size_t bufSize, size_t index, char value);
	void func19(char* buf, size_t bufSize, const char* src, size_t copyLen);
	void func20(int* p);
	void func21(size_t iterations);
	void func22(void* p);
	void func23(FILE* f, const char* msg);
	void func24(int* where, int what);
	void func25(char* buf, size_t bufSize, int underwriteOffset, const char* src);
	void func26(const char* filename);
};

