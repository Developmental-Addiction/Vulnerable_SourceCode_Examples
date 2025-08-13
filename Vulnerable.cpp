#include "Vulnerable.h"

using namespace std;

Vulnerable::Vulnerable() {

}

void Vulnerable::CopyString(string str) {
	strcpy((char*)innerStr_.data(), str.c_str());
}
