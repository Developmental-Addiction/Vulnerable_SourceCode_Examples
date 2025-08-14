#include "Vulnerable.h"
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>

using namespace std;

Vulnerable::Vulnerable() {

}

void Vulnerable::CopyString(string str) {
	strcpy((char*)innerStr_.data(), str.c_str());
}

void Vulnerable::func1(const char* input) {
	char buf[8];
	strcpy(buf, input); // overflow if input is too long
}

void Vulnerable::func2(char* buf, size_t bufSize) {
	scanf("%s", buf); // unsafe, bufSize not enforced
}

void Vulnerable::func3(char* buf, const char* input) {
	strcpy(buf, input); // overflow if input is too long for buf
}

void Vulnerable::func4(const char* input, size_t heapSize) {
	char* buf = new char[heapSize];
	strcpy(buf, input); // overflow if input is too long
	delete[] buf;
}

void Vulnerable::func5(const int* arr, size_t arrSize, size_t index) {
	int x = arr[index]; // out-of-bounds read if index >= arrSize
}

void Vulnerable::func6(unsigned int x) {
	x += 1; // integer overflow if x == UINT_MAX
}

void Vulnerable::func7(unsigned int x) {
	x -= 1; // integer underflow if x == 0
}

void Vulnerable::func8(char* buf, size_t bufSize) {
	for (size_t i = 0; i <= bufSize; ++i) buf[i] = 'A'; // off-by-one error
}

void Vulnerable::func9(short s, char* buf, size_t bufSize) {
	unsigned short us = s;
	memset(buf, 'A', us); // unexpected sign extension
}

void Vulnerable::func10(int len, const char* src, char* dest) {
	memcpy(dest, src, len); // signed to unsigned conversion error if len < 0
}

void Vulnerable::func11(int* p) {
	delete p;
	*p = 13; // use after free
}

void Vulnerable::func12(int x) {
	int y = x; // use of uninitialized variable if x is not initialized
}

void Vulnerable::func13(int* p) {
	*p = 42; // null pointer dereference if p == nullptr
}

void Vulnerable::func14(int* arr) {
	free(arr); // free memory not on heap if arr is stack-allocated
}

void Vulnerable::func15(const char* filename) {
	FILE* f = fopen(filename, "w");
	fclose(f);
	fprintf(f, "test"); // improper control of resource
}

void Vulnerable::func16(int* arr, size_t arrSize, size_t index, int value) {
	arr[index] = value; // out-of-bounds write if index >= arrSize
}

void Vulnerable::func17(const std::vector<int>& v, size_t index) {
	int x = v.at(index); // access after end of buffer if index >= v.size()
}

void Vulnerable::func18(char* buf, size_t bufSize, size_t index, char value) {
	buf[index] = value; // buffer access with incorrect index if index >= bufSize
}

void Vulnerable::func19(char* buf, size_t bufSize, const char* src, size_t copyLen) {
	strncpy(buf, src, copyLen); // buffer overflow if copyLen > bufSize
}

void Vulnerable::func20(int* p) {
	*p = 42; // untrusted pointer dereference
}

void Vulnerable::func21(size_t iterations) {
	for (size_t i = 0; i < iterations; ++i) {} // excessive iteration
}

void Vulnerable::func22(void* p) {
	float* f = (float*)p;
	*f = 3.14f; // type confusion
}

void Vulnerable::func23(FILE* f, const char* msg) {
	fprintf(f, "%s", msg); // use of uninitialized resource if f is not valid
}

void Vulnerable::func24(int* where, int what) {
	*where = what; // write-what-where condition
}

void Vulnerable::func25(char* buf, size_t bufSize, int underwriteOffset, const char* src) {
	char* p = buf - underwriteOffset;
	strcpy(p, src); // buffer underwrite
}

void Vulnerable::func26(const char* filename) {
	remove(filename); // unchecked return value
}
