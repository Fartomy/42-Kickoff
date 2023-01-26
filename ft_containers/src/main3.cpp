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
	{
		cout << " -*-*-*-*-*-*-*-*-*-*-*-*-*-/ CONSTRUCTOR AND ASSIGMENT OPERATOR TEST CASES [1] \\-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
		cout << "--------------------/ Original Vector Constructor Defines \\--------------------" << endl << endl;
		std::vector<int> defaultV;
		std::vector<int> fillV(5, 8);
		int arr[5] = {1, 2, 3, 4, 5};
		std::vector<int> rangeV(arr, arr + 3);
		std::vector<int> copyV(fillV);
		defaultV = rangeV; // ==========> Operator Assigment

		std::vector<int>::iterator orgit;
		cout << "fillV: 			{ ";
		for (orgit = fillV.begin(); orgit < fillV.end() ; ++orgit)
			cout << *orgit << ", ";
		cout << "}" << endl;
		cout << "rangeV: 		{ ";
		for (orgit = rangeV.begin(); orgit < rangeV.end() ; ++orgit)
			cout << *orgit << ", ";
		cout << "}" << endl;
		cout << "copyV: 			{ ";
		for (orgit = copyV.begin(); orgit < copyV.end() ; ++orgit)
			cout << *orgit << ", ";
		cout << "}" << endl;
		cout << "defaultV: 		{ ";
		for (orgit = defaultV.begin(); orgit < defaultV.end() ; ++orgit)
			cout << *orgit << ", ";
		cout << "}" << endl << endl;

		cout << "--------------------/ Fake Vector Constructor Defines \\--------------------" << endl << endl;
		ft::vector<int> ft_defaultV;
		ft::vector<int> ft_fillV(5, 8);
		ft::vector<int> ft_rangeV(arr, arr + 3);
		ft::vector<int> ft_copyV(ft_fillV);
		ft_defaultV = ft_rangeV; // ==========> Operator Assigment

		ft::vector<int>::iterator ftit;
		cout << "ft_fillV: 		{ ";
		for (ftit = ft_fillV.begin(); ftit < ft_fillV.end() ; ++ftit)
			cout << *ftit << ", ";
		cout << "}" << endl;
		cout << "ft_rangeV: 		{ ";
		for (ftit = ft_rangeV.begin(); ftit < ft_rangeV.end() ; ++ftit)
			cout << *ftit << ", ";
		cout << "}" << endl;
		cout << "ft_copyV: 		{ ";
		for (ftit = ft_copyV.begin(); ftit < ft_copyV.end() ; ++ftit)
			cout << *ftit << ", ";
		cout << "}" << endl;
		cout << "defaultV: 		{ ";
		for (ftit = ft_defaultV.begin(); ftit < ft_defaultV.end() ; ++ftit)
			cout << *ftit << ", ";
		cout << "}" << endl << endl;

		cout << " -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*" << endl;
	}

	{

	}

}