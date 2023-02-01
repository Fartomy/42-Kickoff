#include <iostream>
#include <string>
#include <deque>
//#include <map.hpp>
//#include <stack.hpp>
#include "../inc/containers/vector.hpp"
#include <stdlib.h>
#include <stdio.h>

#include <vector>

using std::cout;
using std::endl;

template<typename T>
void print(ft::vector<T> v, std::vector<T> v2)
{
    for(int i = 0,len = v2.size() > v.size() ? v2.size() : v.size(); i < len; i++)
	{
		if(i < v.size())
			printf("v[%d] = %d ",i,v[i]);
		if(i < v2.size())
			printf("v2[%d] = %d ",i,v2[i]);
		printf("\n");
	}
}
int main()
{

/*    ft::vector<int> vec;

    ft::vector<int>::const_iterator cit;

    cit = vec.begin();*/

	ft::vector<int> v;
	std::vector<int> v2;

	for(int i = 0; i < 10000; i++)
	{
		v.push_back(i);
		v2.push_back(i);
	}
	printf(v.size() == v2.size() && v.capacity() == v2.capacity() ? "OK" : "KO");
	printf("\n");

	v.clear();
	v2.clear();
	printf(v.size() == v2.size() && v.capacity() == v2.capacity() ? "OK" : "KO");
	printf("\n");

	for(int i = 0; i < 10; i++)
	{
		v.insert(v.begin(),i);
		v2.insert(v2.begin(),i);
	}
	printf(v.size() == v2.size() && v.capacity() == v2.capacity() ? "OK" : "KO");
	printf("\n");
	v.clear();
	v2.clear();


	std::vector<int> v3;
	for(int i = 0; i < 10; i++)
		v3.push_back(i);

	//cout << v.size() << " " << v.capacity() << endl;
	//cout << v2.size() << " " << v2.capacity() << endl;

	v.insert(v.begin(), v3.begin(),v3.end());
	v2.insert(v2.begin(), v3.begin(),v3.end());
	printf(v.size() == v2.size() && v.capacity() == v2.capacity() ? "OK" : "KO");
	printf("\n");


	v.erase(v.begin() + 5, v.begin() + 7);
	v2.erase(v2.begin() + 5, v2.begin() + 7);
	printf(v.size() == v2.size() && v.capacity() == v2.capacity() ? "OK" : "KO");
	printf("\n");

	print(v,v2);

}
