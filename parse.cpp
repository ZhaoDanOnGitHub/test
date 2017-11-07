#include <fstream>
#include <stdint.h>
#include <iostream>
#include <string>

using namespace std;
uint32_t swap_endian(uint32_t val);

int main() {

	ifstream image_file("train-labels-idx1-ubyte", std::ios::in | std::ios::binary);

	if(!image_file.is_open()) {
		cout<<"open file failed !!!"<<endl;	
		return 0;
	} else {
		uint32_t magic;
		uint32_t num_items;
		uint32_t num_labels;
		uint32_t rows;
		uint32_t cols;
		image_file.read(reinterpret_cast<char*>(&magic), 4);
		cout<<magic<<endl;
		magic = swap_endian(magic);
		cout<<magic<<endl;
		return 0;
	}
}

uint32_t swap_endian(uint32_t val){
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | (val >> 16);
}
