#include <iostream>
#include <string>
#include <deque>
//#include <map.hpp>
//#include <stack.hpp>
#include "../inc/containers/vector.hpp"
#include <stdlib.h>
#include <stdio.h>

#include <vector>

int main()
{
	std::vector<int> vc;
	vc.push_back(1);
	vc.push_back(2);
	vc.push_back(3);

	std::vector<int>::iterator it;

	for (it = vc.begin(); it < vc.end(); ++it)
		std::cout << "Original: " << *it << std::endl;

	std::cout << "Fake State Below" << std::endl;

	ft::vector<int> ftvc;

	ftvc.push_back(1);
	ftvc.push_back(2);
	ftvc.push_back(3);

	ft::vector<int>::iterator fit;
	for (fit = ftvc.begin(); fit < ftvc.end() ; ++fit)
		std::cout << "Fake: " << *fit << std::endl;
}