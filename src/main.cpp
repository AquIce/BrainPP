#include "brainpp.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if(argc != 2) {
		std::cout << "Usage: brainpp <file>" << std::endl;
		return 1;
	}
	BrainPP::brainpp(argv[1], true);
	return 0;
}