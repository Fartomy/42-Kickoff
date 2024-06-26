/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:33:49 by ftekdrmi          #+#    #+#             */
/*   Updated: 2023/02/14 14:33:50 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include "../inc/containers/vector.hpp"
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using std::cout;
using std::endl;


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

		cout << " -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
	}

	{
		cout << " -*-*-*-*-*-*-*-*-*-*-*-*-*-/ CAPACITY FUNCTIONS TEST CASES [2] \\-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
		cout << "--------------------/ Original Vector Capacity Defines \\--------------------" << endl << endl;
		std::vector<int> orgV;
		if( orgV.empty() == 1 )
			cout << "orgV vector is empty." << endl;
		cout << "orgV maximum number of elements that can be stored in memory: [ " << orgV.max_size() << " ]" << endl;
		orgV.reserve(888);
		cout << "orgV size of allocated storage capacity is: [ " << orgV.capacity() << " ]" << endl;
		orgV.resize(555, 3);
		cout << "orgV size is: [ " << orgV.size() << " ]" << endl;
		std::vector<int>::iterator orgit;
		cout << "In orgV: { ";
		for (orgit = orgV.begin(); orgit < orgV.end() ; ++orgit)
			cout << *orgit << ", ";
		cout << "}" << endl << endl;

		cout << "--------------------/ Fake Vector Capacity Defines \\--------------------" << endl << endl;
		ft::vector<int> ftV;
		if( ftV.empty() == 1 )
			cout << "ftV vector is empty." << endl;
		cout << "ftV maximum number of elements that can be stored in memory: [ " << ftV.max_size() << " ]" << endl;
		ftV.reserve(888);
		cout << "ftV size of allocated storage capacity is: [ " << ftV.capacity() << " ]" << endl;
		ftV.resize(555, 3);
		cout << "ftV size is: [ " << ftV.size() << " ]" << endl;
		ft::vector<int>::iterator ftit;
		cout << "In ftV: { ";
		for (ftit = ftV.begin(); ftit < ftV.end() ; ++ftit)
			cout << *ftit << ", ";
		cout << "}" << endl << endl;

		cout << " -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
	}

	{
		cout << " -*-*-*-*-*-*-*-*-*-*-*-*-*-/ MODIFIER FUNCTIONS TEST CASES [3] \\-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
		cout << "--------------------/ Original Vector Modifier Defines \\--------------------" << endl << endl;
		std::vector<int> orgV;
		std::vector<int> _orgV(3, 11);
		std::vector<int>::iterator orgit;
		int arr[5] = {1, 2, 3, 4, 5};
		orgV.assign(10, 4);
		cout << "Form 1 fill assigned orgV: 		{ ";
		for (orgit = orgV.begin(); orgit < orgV.end() ; ++orgit)
			cout << *orgit << ", ";
		cout << "}" << endl;
		orgV.assign(arr, arr + 5);
		cout << "Form 2 range assigned orgV: 		{ ";
		for (orgit = orgV.begin(); orgit < orgV.end() ; ++orgit)
			cout << *orgit << ", ";
		cout << "}" << endl;
		orgV.push_back(6);
		cout << "Push backed orgV: 			{ ";
		for (orgit = orgV.begin(); orgit < orgV.end() ; ++orgit)
			cout << *orgit << ", ";
		cout << "}" << endl;
		orgV.insert(orgV.begin() + 3, 8);
		cout << "Form 1 single element inserted orgV: 	{ ";
		for (orgit = orgV.begin(); orgit < orgV.end() ; ++orgit)
			cout << *orgit << ", ";
		cout << "}" << endl;
		orgV.insert(orgV.begin(), 3, 42);
		cout << "Form 2 fill inserted orgV: 		{ ";
		for (orgit = orgV.begin(); orgit < orgV.end() ; ++orgit)
			cout << *orgit << ", ";
		cout << "}" << endl;
		orgV.insert(orgV.end(), _orgV.begin(), _orgV.end());
		cout << "Form 3 range inserted orgV: 		{ ";
		for (orgit = orgV.begin(); orgit < orgV.end() ; ++orgit)
			cout << *orgit << ", ";
		cout << "}" << endl;
		orgV.swap(_orgV);
		cout << "Swaped orgV: 				{ ";
		for (orgit = orgV.begin(); orgit < orgV.end() ; ++orgit)
			cout << *orgit << ", ";
		cout << "}" << endl;
		orgV.swap(_orgV);
		cout << "Swaped orgV again: 			{ ";
		for (orgit = orgV.begin(); orgit < orgV.end() ; ++orgit)
			cout << *orgit << ", ";
		cout << "}" << endl;
		orgV.pop_back();
		cout << "Pop_backed orgV: 			{ ";
		for (orgit = orgV.begin(); orgit < orgV.end() ; ++orgit)
			cout << *orgit << ", ";
		cout << "}" << endl;
		orgV.erase(orgV.begin() + 6);
		cout << "Form 1 single element erased orgV: 	{ ";
		for (orgit = orgV.begin(); orgit < orgV.end() ; ++orgit)
			cout << *orgit << ", ";
		cout << "}" << endl;
		orgV.erase(orgV.begin(), orgV.begin() + 3);
		cout << "Form 2 range erased orgV: 		{ ";
		for (orgit = orgV.begin(); orgit < orgV.end() ; ++orgit)
			cout << *orgit << ", ";
		cout << "}" << endl;
		orgV.clear();
		cout << "Cleared orgV: 				{ ";
		for (orgit = orgV.begin(); orgit < orgV.end() ; ++orgit)
			cout << *orgit << ", ";
		cout << "}" << endl << endl;

		cout << "--------------------/ Fake Vector Modifier Defines \\--------------------" << endl << endl;

		ft::vector<int> ftV;
		ft::vector<int> _ftV(3, 11);
		ft::vector<int>::iterator ftit;
		ftV.assign(10, 4);
		cout << "Form 1 fill assigned ftV: 		{ ";
		for (ftit = ftV.begin(); ftit < ftV.end() ; ++ftit)
			cout << *ftit << ", ";
		cout << "}" << endl;
		ftV.assign(arr, arr + 5);
		cout << "Form 2 range assigned ftV: 		{ ";
		for (ftit = ftV.begin(); ftit < ftV.end() ; ++ftit)
			cout << *ftit << ", ";
		cout << "}" << endl;
		ftV.push_back(6);
		cout << "Push backed ftV: 			{ ";
		for (ftit = ftV.begin(); ftit < ftV.end() ; ++ftit)
			cout << *ftit << ", ";
		cout << "}" << endl;
		ftV.insert(ftV.begin() + 3, 8);
		cout << "Form 1 single element inserted ftV: 	{ ";
		for (ftit = ftV.begin(); ftit < ftV.end() ; ++ftit)
			cout << *ftit << ", ";
		cout << "}" << endl;
		ftV.insert(ftV.begin(), 3, 42);
		cout << "Form 2 fill inserted ftV: 		{ ";
		for (ftit = ftV.begin(); ftit < ftV.end() ; ++ftit)
			cout << *ftit << ", ";
		cout << "}" << endl;
		ftV.insert(ftV.end(), _ftV.begin(), _ftV.end());
		cout << "Form 3 range inserted ftV: 		{ "; // ======================================> Have a problem!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		for (ftit = ftV.begin(); ftit < ftV.end() ; ++ftit)
			cout << *ftit << ", ";
		cout << "}" << endl;
		ftV.swap(_ftV);
		cout << "Swaped ftV: 				{ ";
		for (ftit = ftV.begin(); ftit < ftV.end() ; ++ftit)
			cout << *ftit << ", ";
		cout << "}" << endl;
		ftV.swap(_ftV);
		cout << "Swaped ftV again: 			{ ";
		for (ftit = ftV.begin(); ftit < ftV.end() ; ++ftit)
			cout << *ftit << ", ";
		cout << "}" << endl;
		ftV.pop_back();
		cout << "Pop_backed ftV: 			{ ";
		for (ftit = ftV.begin(); ftit < ftV.end() ; ++ftit)
			cout << *ftit << ", ";
		cout << "}" << endl;
		ftV.erase(ftV.begin() + 6);
		cout << "Form 1 single element erased ftV: 	{ ";
		for (ftit = ftV.begin(); ftit < ftV.end() ; ++ftit)
			cout << *ftit << ", ";
		cout << "}" << endl;
		ftV.erase(ftV.begin(), ftV.begin() + 3);
		cout << "Form 2 range erased ftV: 		{ ";
		for (ftit = ftV.begin(); ftit < ftV.end() ; ++ftit)
			cout << *ftit << ", ";
		cout << "}" << endl;
		ftV.clear();
		cout << "Cleared ftV: 				{ ";
		for (ftit = ftV.begin(); ftit < ftV.end() ; ++ftit)
			cout << *ftit << ", ";
		cout << "}" << endl << endl;


		cout << " -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
	}

    {
        cout << " -*-*-*-*-*-*-*-*-*-*-*-*-*-/ ELEMENT ACCESS FUNCTIONS TEST CASES [3] \\-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;

        cout << "--------------------/ Original Vector Element Access Defines \\--------------------" << endl << endl;

        std::vector<int> orgV;
        orgV.push_back(21);
        orgV.push_back(1);
        orgV.push_back(2);
        orgV.push_back(3);
        orgV.push_back(42);
        cout << "Operator[] usage: " << orgV[2] << endl;
        cout << "function at usage: " << orgV.at(2) << endl;
        cout << "function front usage: " << orgV.front() << endl;
        cout << "function back usage: " << orgV.back() << endl << endl;

        cout << "--------------------/ Fake Vector Element Access Defines \\--------------------" << endl << endl;
        ft::vector<int> ftV;
        ftV.push_back(21);
        ftV.push_back(1);
        ftV.push_back(2);
        ftV.push_back(3);
        ftV.push_back(42);
        cout << "Operator[] usage: " << ftV[2] << endl;
        cout << "function at usage: " << ftV.at(2) << endl;
        cout << "function front usage: " << ftV.front() << endl;
        cout << "function back usage: " << ftV.back() << endl << endl;

        cout << " -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
    }
}