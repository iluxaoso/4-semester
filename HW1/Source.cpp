#include "includes.h"

//!======functions
std::map<std::string, int> getWordFreq(const std::string&);
int outPut(const std::map<std::string, int>&);



int main()
{
	std::string filename;
	std::cout << "Input filename" << "\n";
	std::cin >> filename;

	std::map<std::string, int> WordFreq = getWordFreq(filename);
	outPut(WordFreq);

	system("pause");
}
