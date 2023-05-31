#ifndef __BRAINPP_HPP__
#define __BRAINPP_HPP__

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <fstream>

namespace BrainPP {
	class BrainPP {
	private:
		int memory[30000] = {0};
		int pointer = 0;
		std::vector<std::array<int, 2>> loops;
		std::string input = "";

		void trim_input(std::string input);
		void loop_preprocess();
		int find_pair(int value, bool is_first);
	public:
		BrainPP() {}
		void run(std::string input, bool file);
	};
	void brainpp(std::string input, bool file = false);
}

#endif // __BRAINPP_HPP__
