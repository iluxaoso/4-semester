//!======includes
#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>


//!======functions
std::string prepare(const std::string& );
std::string toLower(const std::string& );
std::string punct  (const std::string& );

std::map<std::string, int> getWordFreq(const std::string );

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


std::string prepare(const std::string& str)
{
	std::string res(str);
	res = toLower(res);
	res = punct(res);
	
	return res;
}

std::string toLower(const std::string& str)
{
	std::string nstr(str);
	std::transform(nstr.begin(), nstr.end(), nstr.begin(), ::tolower);

	return nstr;
}

std::string punct(const std::string& str)
{
	std::string nstr(str);
	// nstr.back() <=> nstd[nstd.size() - 1]
	while (!isalpha(nstr[nstr.size() - 1]))
	{
		nstr.pop_back();
	}

	return nstr;
}

/*
лучше передать fName по ссылке. видимо забыли & поставить
*/
std::map<std::string, int> getWordFreq(const std::string fName)
{
	std::ifstream file(fName);
	if (!file.is_open())
	{
		std::cout << "Cannot open the file" << fName << "\n";

		exit(-1);
	}
	if (file.is_open())
	{
		std::string word;
		std::map <std::string, int> wordFreq;

		while (!file.eof())
		{
			file >> word;
			word = prepare(word);

			wordFreq[word]++;
		}
		return wordFreq;
	}
}

struct freq
{
	int count;
	std::string word;

	bool operator <(const freq& freq)
	{
		return count < freq.count;
	}
};

int outPut(const std::map<std::string, int>& m)
{
	int mapSize = m.size();
	std::vector<freq> freq;
	freq.resize(mapSize);

	int i = 0;
	for (auto it : m)
	{
		freq[i].word = it.first;
		freq[i].count = it.second;
	}

	std::sort(freq.begin(), freq.end());

	std::cout << freq[mapSize - 1].word << " " << freq[mapSize - 1].count << "\n";

	return 0;
}
