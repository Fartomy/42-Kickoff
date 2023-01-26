#include <iostream>
#include <string>
#include <deque>
//#include <map.hpp>
//#include <stack.hpp>
#include "../inc/containers/vector.hpp"
#include <stdlib.h>
#include <stdio.h>

using std::cout;
using std::endl;

#include <vector>

int main()
{
		// -*-*-*-*-*-*-*-*-*-*-*-*-*-/ Constructor Test Cases \-*-*-*-*-*-*-*-*-*-*-*-*-*-
	{
		cout << " -*-*-*-*-*-*-*-*-*-*-*-*-*-/ CONSTRUCTOR TEST CASES [1] \\-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
		cout << "--------------------/ Original Vector Constructor Defines \\--------------------" << endl;
		std::vector<int> defaultV;
		std::vector<int> fillV(5, 8);
		int arr[5] = {1, 2, 3, 4, 5};
		std::vector<int> rangeV(arr, arr + 3);
		std::vector<int> copyV(fillV);

		std::vector<int>::iterator orgit;
		for (orgit = fillV.begin(); orgit < fillV.end() ; ++orgit)
			cout << "fillV: " << *orgit << endl;
		cout << endl;
		for (orgit = rangeV.begin(); orgit < rangeV.end() ; ++orgit)
			cout << "rangeV: " << *orgit << endl;
		cout << endl;
		for (orgit = copyV.begin(); orgit < copyV.end() ; ++orgit)
			cout << "copyV: " << *orgit << endl;
		cout << endl;

		cout << "--------------------/ Fake Vector Constructor Defines \\--------------------" << endl;
		ft::vector<int> ft_defaultV;
		ft::vector<int> ft_fillV(5, 8);
		ft::vector<int> ft_rangeV(arr, arr + 3);
		ft::vector<int> ft_copyV(ft_fillV);

		ft::vector<int>::iterator ftit;
		for (ftit = ft_fillV.begin(); ftit < ft_fillV.end() ; ++ftit)
			cout << "ft_fillV: " << *ftit << endl;
		cout << endl;
		for (ftit = ft_rangeV.begin(); ftit < ft_rangeV.end() ; ++ftit)
			cout << "ft_rangeV: " << *ftit << endl;
		cout << endl;
		for (ftit = ft_copyV.begin(); ftit < ft_copyV.end() ; ++ftit)
			cout << "ft_copyV: " << *ftit << endl;
		cout << endl;

		cout << " -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*" << endl;
	}

}