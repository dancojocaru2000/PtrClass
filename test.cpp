#include <iostream>
#include "ptr.hpp"
using std::cin;
using std::cout;
using dcdevelop::ptr;

char s[500];

int main() {
	cin >> s;
	ptr<char> p = s;
	cout << p.is_empty() << std::endl;
	cout << p.next().prev() << std::endl;

	int x = 5;
	ptr<int> a = &x;

	#ifdef DCDEVELOP_PTR_CLASS_CSTRING

	cout << p.length() << std::endl;

	#endif

	return 0;
}