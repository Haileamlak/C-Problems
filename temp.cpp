
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

template <typename T>
wchar_t *as_bytes(T &i)
{
	return static_cast<wchar_t *>(&i); // treat that memory as bytes
}
void test()
{
	wifstream ifs("sources", ios_base::binary); // stream mode is binary
	wofstream ofs("target", ios::out | ios_base::binary); // stream mode is binary
	wchar_t v[] = {L'፩', L'፪', L'፫', L'፬', L'፭', L'፮', L'፯', L'፰', L'፱', L'፲', L'፳', L'፴', L'፵', L'፶', L'፷', L'፸', L'፹', L'፺', L'፻', L'፼'};
	// for (wchar_t i; ifs.read(v, i);) // read bytes from binary file
	// 	v.push_back(i);
	// // ... do something with v ...
	for (auto i : v) // write bytes to binary file:
		ofs.write(v, i);
}
int main()
{
	test();
	return 0;
}
