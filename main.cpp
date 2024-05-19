#include <iostream>
#include <string>
#include <cmath>
#include <vector>

// 0=0, 1=1, 2=2, 3=3, 4=-1, 5=-2, 6=-3

const std::vector<std::string> alph = { "0", "1", "2", "3", "^1", "^2", "^3" };
const std::string alphabet = "0123456789abcdefghijklmnopqrstuvwxyz";

int conv(std::string x, const int base) {
	int n = 0, minPassed = 0;
	x = "0" + x;
	for (int i = x.size() - 1; i > 0; i--) {
		if (x[i - 1] == '^') {
			n -= alphabet.find(x[i]) * pow(base, x.size() - i - minPassed - 1);
		}
		else if (x[i] == '^') {
			minPassed++;
		}
		else {
			n += alphabet.find(x[i]) * pow(base, x.size() - i - minPassed - 1);
		}
	}
	return n;
}

std::string codeToString(std::vector<int>& s) {
	std::string output = "";
	for (auto c : s) {
		output += alph[c];
	}
	return output;
}

std::string deleteZeros(std::string& s) {
	bool zeroEnd = 0;
	std::string newS = "";
	for (auto c : s) {
		if (zeroEnd or c != '0') {
			zeroEnd = 1;
			newS.push_back(c);
		}
	}
	return newS;
}

int main() {
	std::vector<int>numberCode(10);
	int numInDecimal;
	std::cin >> numInDecimal;
	for (int x1 = 0; x1 < 7; x1++) {
		numberCode[0] = x1;
		for (int x2 = 0; x2 < 7; x2++) {
			numberCode[1] = x2;
			for (int x3 = 0; x3 < 7; x3++) {
				numberCode[2] = x3;
				for (int x4 = 0; x4 < 7; x4++) {
					numberCode[3] = x4;
					for (int x5 = 0; x5 < 7; x5++) {
						numberCode[4] = x5;
						for (int x6 = 0; x6 < 7; x6++) {
							numberCode[5] = x6;
							for (int x7 = 0; x7 < 7; x7++) {
								numberCode[6] = x7;
								for (int x8 = 0; x8 < 7; x8++) {
									numberCode[7] = x8;
									for (int x9 = 0; x9 < 7; x9++) {
										numberCode[8] = x9;
										for (int x10 = 0; x10 < 7; x10++) {
											numberCode[9] = x10;
											std::string stringNumWZeros = codeToString(numberCode);
											std::string stringNum = deleteZeros(stringNumWZeros);
											if (conv(stringNum, 7) == numInDecimal) {
												std::cout << stringNum << std::endl;
												return 0;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
