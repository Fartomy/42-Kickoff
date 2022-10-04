#ifndef SEDLOSERS_HPP
#define SEDLOSERS_HPP

#include <iostream>
#include <fstream>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;

class SedLosers
{
public:

	ofstream fot;
	ifstream fin;

	void	setFilename(string fn)
	{
		fileName = fn;
	}
	void	setS1(string s)
	{
		s1 = s;
	}
	void	setS2(string s)
	{
		s2 = s;
	}

	string	getFilename(void)
	{
		return (fileName);
	}
	string getS1(void)
	{
		return (s1);
	}
	string getS2(void)
	{
		return (s2);
	}

private:
	string fileName;
	string s1;
	string s2;
};


#endif
