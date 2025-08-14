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

// CWE-119: Improper Restriction of Operations within the Bounds of a Memory Buffer
void Vulnerable::func1() {
	char buf[8];
	strcpy(buf, "This is too long!"); // overflow
}

// CWE-120: Classic Buffer Overflow
void Vulnerable::func2() {
	char buf[4];
	scanf("%s", buf); // unsafe
}

// CWE-121: Stack-based Buffer Overflow
void Vulnerable::func3() {
	char buf[4];
	strcpy(buf, "Overflow");
}

// CWE-122: Heap-based Buffer Overflow
void Vulnerable::func4() {
	char* buf = new char[4];
	strcpy(buf, "Overflow");
	delete[] buf;
}

// CWE-125: Out-of-bounds Read
void Vulnerable::func5() {
	int arr[2] = {1,2};
	int x = arr[5];
}

// CWE-190: Integer Overflow
void Vulnerable::func6() {
	unsigned int x = UINT_MAX;
	x += 1;
}

// CWE-191: Integer Underflow
void Vulnerable::func7() {
	unsigned int x = 0;
	x -= 1;
}

// CWE-193: Off-by-one Error
void Vulnerable::func8() {
	char buf[4];
	for (int i = 0; i <= 4; ++i) buf[i] = 'A';
}

// CWE-194: Unexpected Sign Extension
void Vulnerable::func9() {
	short s = -1;
	unsigned short us = s;
	char buf[10];
	memset(buf, 'A', us); // us is 65535
}

// CWE-195: Signed to Unsigned Conversion Error
void Vulnerable::func10() {
	int len = -1;
	char buf[10];
	memcpy(buf, "AAAA", len); // len is -1, treated as large unsigned
}

// CWE-416: Use After Free
void Vulnerable::func11() {
	int* p = new int(42);
	delete p;
	*p = 13;
}

// CWE-457: Use of Uninitialized Variable
void Vulnerable::func12() {
	int x;
	int y = x;
}

// CWE-476: NULL Pointer Dereference
void Vulnerable::func13() {
	int* p = nullptr;
	*p = 42;
}

// CWE-590: Free Memory Not on Heap
void Vulnerable::func14() {
	int arr[4];
	free(arr);
}

// CWE-664: Improper Control of a Resource
void Vulnerable::func15() {
	FILE* f = fopen("file.txt", "w");
	fclose(f);
	fprintf(f, "test");
}

// CWE-787: Out-of-bounds Write
void Vulnerable::func16() {
	int arr[2];
	arr[5] = 42;
}

// CWE-788: Access of Memory Location After End of Buffer
void Vulnerable::func17() {
	std::vector<int> v(2);
	int x = v.at(5);
}

// CWE-805: Buffer Access with Incorrect Index
void Vulnerable::func18() {
	char buf[4];
	buf[10] = 'A';
}

// CWE-806: Buffer Overflow Due to Incorrect Length
void Vulnerable::func19() {
	char buf[4];
	strncpy(buf, "TooLong", 10);
}

// CWE-822: Untrusted Pointer Dereference
void Vulnerable::func20() {
	int* p = (int*)0xDEADBEEF;
	*p = 42;
}

// CWE-834: Excessive Iteration
void Vulnerable::func21() {
	for (int i = 0; i < 1000000000; ++i) {}
}

// CWE-843: Type Confusion
void Vulnerable::func22() {
	void* p = (void*)new int(42);
	float* f = (float*)p;
	*f = 3.14f;
}

// CWE-870: Use of Uninitialized Resource
void Vulnerable::func23() {
	FILE* f;
	fprintf(f, "test");
}

// CWE-123: Write-What-Where Condition
void Vulnerable::func24() {
	int* where = nullptr;
	int what = 42;
	*where = what;
}

// CWE-124: Buffer Underwrite
void Vulnerable::func25() {
	char buf[8];
	char* p = buf - 4;
	strcpy(p, "test");
}

// CWE-252: Unchecked Return Value
void Vulnerable::func26() {
	remove("nonexistent.txt"); // return value not checked
}
