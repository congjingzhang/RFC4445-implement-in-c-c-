#include <iostream>
#include <fstream>
#include <vector>
#include "MdiParser.h"
Result* getMdi(const char*  filename) {
	std::ifstream file(filename, std::ios::in | std::ios::binary);
	if (!file.is_open()) {
		std::cout << "file open failed !!!" << std::endl;
		return NULL;
	} 

}
int main() {
	Result* result = new Result();
	const char* filename = "C:\\Users\\Administrator\\Desktop\\pcap\\df.pcap";

	result = getMdi(filename);
}