#include "brainpp.hpp"

void BrainPP::BrainPP::trim_input(std::string input) {
	std::string charset = "><+-.,[]";
	for(char c : input) {
		if(charset.find(c) != std::string::npos) {
			this->input += c;
		}
	}
}

void BrainPP::BrainPP::loop_preprocess() {
	std::vector<int> op;
	for(int i = 0; i < this->input.size(); i++) {
		if(this->input[i] == '[') { op.push_back(i); }
		else if(this->input[i] == ']') { this->loops.push_back({op[op.size() - 1], i}); op.pop_back(); }
	}
}

int BrainPP::BrainPP::find_pair(int value, bool is_first = true) {
	for(std::array<int, 2> el : this->loops) {
		if(is_first && el[0] == value) { return el[1]; }
		if(!is_first && el[1] == value) { return el[0]; }
	}
	throw std::runtime_error("Invalid array value");
}

void BrainPP::BrainPP::run(std::string input, bool file) {
	if(file) {
		std::ifstream ifs(input);
  		this->input.assign((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
	}
	this->trim_input(input);
	this->loop_preprocess();
	for(int i = 0; i < this->input.size(); i++) {
		switch (this->input[i]) {
			case '+':
				this->memory[this->pointer]++;
				break;
			case '-':
				this->memory[this->pointer]--;
				break;
			case '>':
				this->pointer++;
				break;
			case '<':
				this->pointer--;
				break;
			case '.':
				std::cout << char(this->memory[this->pointer]);
				break;
			case ',':
				this->memory[this->pointer] = std::getchar();
				break;
			case '[':
				if(this->memory[this->pointer] == 0) { i = this->find_pair(i); }
				break;
			case ']':
				if(this->memory[this->pointer] != 0) { i = this->find_pair(i, false); }
				break;
			default:
				break;
		}
	}
	std::cout << std::endl;
}

void BrainPP::brainpp(std::string input, bool file) {
	BrainPP bp = BrainPP();
	bp.run(input, file);
}