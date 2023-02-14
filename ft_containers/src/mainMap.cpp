/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainMap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:33:43 by ftekdrmi          #+#    #+#             */
/*   Updated: 2023/02/14 14:33:44 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/containers/map.hpp"
#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <stdlib.h>
#include <stdio.h>

using std::cout;
using std::endl;
using std::string;

int main()
{
    {
        cout << " -*-*-*-*-*-*-*-*-*-*-*-*-*-/ UNDERSTANDING TO MAP [0] \\-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "--------------------/ Phonebook and Circuit Example \\--------------------" << endl << endl;
        std::map<string, int> phoneBook;
        std::map<string, bool> circuit;

        phoneBook["Furkan"] = 5235;
        phoneBook["Ali"] = 5422;
        phoneBook["Faruk"] = 5671;
        phoneBook["Faruk"] = 5671; // Ayni degeri eklemiyor cunku anahtar deger ikilileri benzersizdir
        phoneBook["Faruk"] = 42;  // Fakat deger guncellenebilir

        std::map<string, int>::iterator it;
        cout << "Phonebook Example:         { ";
        for (it = phoneBook.begin(); it != phoneBook.end() ; ++it)
            cout << it->first << "-" << it->second << ", ";
        cout << "}" << endl;

        circuit["Open"] = true;
        circuit["Off"] = false;
        circuit["Off"] = false; // ❌

        std::map<string, bool>::iterator cit;
        cout << "Circuit Example:           { ";
        for (it = phoneBook.begin(); it != phoneBook.end() ; ++it)
            cout << it->first << "-" << it->second << ", ";
        cout << "}" << endl;
    }

    {
        cout << endl << " -*-*-*-*-*-*-*-*-*-*-*-*-*-/ CONSTRUCTOR AND ASSIGMENT OPERATOR TEST CASES [1] \\-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "--------------------/ Original Map Constructor Defines \\--------------------" << endl << endl;

        std::map<int, string> orgM;
        std::map<int, string> oprorgM;
        orgM[0] = "Zero";
        orgM[1] = "One";
        orgM[2] = "Second";
        std::map<int, string> rngorgM(orgM.begin(), orgM.end());
        std::map<int, string>::iterator orgit;
        cout << "Range Constructor Define:      { ";
        for (orgit = rngorgM.begin(); orgit != rngorgM.end() ; ++orgit)
            cout << orgit->first << "-" << orgit->second << ", ";
        cout << "}" << endl;
        std::map<int, string> copyorgM(rngorgM);
        cout << "Copy Constructor Define:       { ";
        for (orgit = copyorgM.begin(); orgit != copyorgM.end() ; ++orgit)
            cout << orgit->first << "-" << orgit->second << ", ";
        cout << "}" << endl;
        cout << "Operator Assignment Define:    { ";
        oprorgM = copyorgM;
        for (orgit = oprorgM.begin(); orgit != oprorgM.end() ; ++orgit)
            cout << orgit->first << "-" << orgit->second << ", ";
        cout << "}" << endl;

        cout << endl << "--------------------/ Fake Map Constructor Defines \\--------------------" << endl << endl;
        ft::map<int, string> ftM;
        ft::map<int, string> oprftM;
        ftM[0] = "Zero";
        ftM[1] = "One";
        ftM[2] = "Second";
        ft::map<int, string> rngftM(ftM.begin(), ftM.end());
        ft::map<int, string>::iterator ftit;
        cout << "Range Constructor Define:      { ";
        for (ftit = rngftM.begin(); ftit != rngftM.end() ; ++ftit)
            cout << ftit->first << "-" << ftit->second << ", ";
        cout << "}" << endl;
        ft::map<int, string> copyftM(rngftM);
        cout << "Copy Constructor Define:       { ";
        for (ftit = copyftM.begin(); ftit != copyftM.end() ; ++ftit)
            cout << ftit->first << "-" << ftit->second << ", ";
        cout << "}" << endl;
        cout << "Operator Assignment Define:    { ";
        oprftM = copyftM;
        for (ftit = oprftM.begin(); ftit != oprftM.end() ; ++ftit)
            cout << ftit->first << "-" << ftit->second << ", ";
        cout << "}" << endl;

        cout << endl << " -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
    }

    {
        cout << " -*-*-*-*-*-*-*-*-*-*-*-*-*-/ MODIFIERS FUNCTIONS TEST CASES [2] \\-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "--------------------/ Original Map Modifiers Defines \\--------------------" << endl << endl;
        std::map<int, string> orgM;
        std::map<int, string> orgM2;
        std::map<int, string>::iterator orgit;
        orgM.insert(std::make_pair(24, "Fevzi"));
        orgM.insert(std::make_pair(42, "Efe"));
        orgM.insert(std::make_pair(12, "Ali"));
        cout << "Form 1 single element insert:      { ";
        for (orgit = orgM.begin(); orgit != orgM.end() ; ++orgit)
            cout << orgit->first << "-" << orgit->second << ", ";
        cout << "}" << endl;
        orgM2.insert(orgM.begin(), orgM.end());
        cout << "Form 2 range insert:               { ";
        for (orgit = orgM.begin(); orgit != orgM.end() ; ++orgit)
            cout << orgit->first << "-" << orgit->second << ", ";
        cout << "}" << endl;
        orgit = orgM.find(2);
        orgM.insert(orgit, std::make_pair(98, "Kâzim")); // verdigimiz iterator konumunun 1 fazlasina degeri ekler
        cout << "Form 3 with hint insert:           { ";
        for (orgit = orgM.begin(); orgit != orgM.end() ; ++orgit)
            cout << orgit->first << "-" << orgit->second << ", ";
        cout << "}" << endl;
        orgit = orgM2.find(2);
        orgM2.insert(orgit, std::make_pair(123, "Bekir"));
        orgM.swap(orgM2);
        cout << "Swap define:                       { ";
        for (orgit = orgM.begin(); orgit != orgM.end() ; ++orgit)
            cout << orgit->first << "-" << orgit->second << ", ";
        cout << "}" << endl;
        orgM.erase(42);
        cout << "Form 1 erase define:               { ";
        for (orgit = orgM.begin(); orgit != orgM.end() ; ++orgit)
            cout << orgit->first << "-" << orgit->second << ", ";
        cout << "}" << endl;
        orgM.erase(orgM.begin());
        cout << "Form 2 erase define:               { ";
        for (orgit = orgM.begin(); orgit != orgM.end() ; ++orgit)
            cout << orgit->first << "-" << orgit->second << ", ";
        cout << "}" << endl;
        orgM.erase(orgM.begin(), orgM.end());
        cout << "Form 3 erase define:               { ";
        for (orgit = orgM.begin(); orgit != orgM.end() ; ++orgit)
            cout << orgit->first << "-" << orgit->second << ", ";
        cout << "}" << endl;
        orgM2.clear();
        cout << "Clear function define:             { ";
        for (orgit = orgM.begin(); orgit != orgM.end() ; ++orgit)
            cout << orgit->first << "-" << orgit->second << ", ";
        cout << "}" << endl;

        cout << endl << "--------------------/ Fake Map Modifiers Defines \\--------------------" << endl << endl;
        ft::map<int, string> ftM;
        ft::map<int, string> ftM2;
        ft::map<int, string>::iterator ftit;
        ftM.insert(ft::make_pair(24, "Fevzi"));
        ftM.insert(ft::make_pair(42, "Efe"));
        ftM.insert(ft::make_pair(12, "Ali"));
        cout << "Form 1 single element insert:      { ";
        for (ftit = ftM.begin(); ftit != ftM.end() ; ++ftit)
            cout << ftit->first << "-" << ftit->second << ", ";
        cout << "}" << endl;
        ftM2.insert(ftM.begin(), ftM.end());
        cout << "Form 2 range insert:               { ";
        for (ftit = ftM.begin(); ftit != ftM.end() ; ++ftit)
            cout << ftit->first << "-" << ftit->second << ", ";
        cout << "}" << endl;
        ftit = ftM.find(2);
        ftM.insert(ftit, ft::make_pair(98, "Kâzim")); // verdigimiz iterator konumunun 1 fazlasina degeri ekler
        cout << "Form 3 with hint insert:           { ";
        for (ftit = ftM.begin(); ftit != ftM.end() ; ++ftit)
            cout << ftit->first << "-" << ftit->second << ", ";
        cout << "}" << endl;
        ftit = ftM2.find(2);
        ftM2.insert(ftit, ft::make_pair(123, "Bekir"));
        ftM.swap(ftM2);
        cout << "Swap define:                       { ";
        for (ftit = ftM.begin(); ftit != ftM.end() ; ++ftit)
            cout << ftit->first << "-" << ftit->second << ", ";
        cout << "}" << endl;
        ftM.erase(42);
       cout << "Form 1 erase define:               { ";
        for (ftit = ftM.begin(); ftit != ftM.end() ; ++ftit)
            cout << ftit->first << "-" << ftit->second << ", ";
        cout << "}" << endl;
        ftM.erase(ftM.begin());
        cout << "Form 2 erase define:               { ";
        for (ftit = ftM.begin(); ftit != ftM.end() ; ++ftit)
            cout << ftit->first << "-" << ftit->second << ", ";
        cout << "}" << endl;
        ftM.erase(ftM.begin(), ftM.end());
        cout << "Form 3 erase define:               { ";
        for (ftit = ftM.begin(); ftit != ftM.end() ; ++ftit)
            cout << ftit->first << "-" << ftit->second << ", ";
        cout << "}" << endl;
        ftM2.clear();
        cout << "Clear function define:             { ";
        for (ftit = ftM.begin(); ftit != ftM.end() ; ++ftit)
            cout << ftit->first << "-" << ftit->second << ", ";
        cout << "}" << endl;

        cout << endl << " -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
    }

    {
        cout << " -*-*-*-*-*-*-*-*-*-*-*-*-*-/ CAPACITY FUNCTIONS TEST CASES [3] \\-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "--------------------/ Original Map Capacity Defines \\--------------------" << endl << endl;
        std::map<string, int> orgM;
        orgM["first"] = 1;
        orgM["second"] = 2;
        orgM["third"] = 3;

        cout << "empty function define:                 ";
        if(!orgM.empty())
            cout << "Map array is not empty!" << endl;
        cout << "max_size function define:              ";
        cout << orgM.max_size() << endl;
        cout << "size function define:                  ";
        cout << orgM.size() << endl;

        cout << endl << "--------------------/ Fake Map Capacity Defines \\--------------------" << endl << endl;
        ft::map<string, int> ftM;
        ftM["first"] = 1;
        ftM["second"] = 2;
        ftM["third"] = 3;

        cout << "empty function define:                 ";
        if(!ftM.empty())
            cout << "Map array is not empty!" << endl;
        cout << "max_size function define:              ";
        cout << ftM.max_size() << endl;
        cout << "size function define:                  ";
        cout << ftM.size() << endl;

        cout << endl << " -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
    }

    {
        cout << " -*-*-*-*-*-*-*-*-*-*-*-*-*-/ ELEMENT ACCESS TEST CASES [4] \\-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "--------------------/ Original Map Element Access Defines \\--------------------" << endl << endl;

        std::map<string, float> orgM;
        orgM["first"] = 45.1f;
        orgM["second"] = 34.12f;
        orgM["third"] = 42.42f;

        cout << "operator[] define:                 ";
        cout << orgM["third"] << endl;
        cout << "at define:                         ";
        cout << orgM.at("second") << endl;

        cout << endl << "--------------------/ Fake Map Element Access Defines \\--------------------" << endl << endl;

        ft::map<string, float> ftM;
        ftM["first"] = 45.1f;
        ftM["second"] = 34.12f;
        ftM["third"] = 42.42f;

        cout << "operator[] define:                 ";
        cout << ftM["third"] << endl;
        cout << "at define:                         ";
        cout << ftM.at("second") << endl;

        cout << endl << " -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;

    }

    {
        cout << " -*-*-*-*-*-*-*-*-*-*-*-*-*-/ OPERATIONS FUNCTIONS TEST CASES [5] \\-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "--------------------/ Original Operations Functions Defines \\--------------------" << endl << endl;

        std::map<char, string> orgM;
        std::map<char, string>::iterator itlow, itup;
        std::pair<std::map<char, string>::iterator, std::map<char, string>::iterator> eqalR;

        orgM['b'] = "Batman";
        orgM['a'] = "Arkham";
        orgM['q'] = "Aard"; // birden fazla 'a' anahtari olsa da ikinci tanimlama da degeri ustune overwrite edilecek. Yani 'Batman' artik 'Aard' olacak.
        orgM['j'] = "Joker";
        orgM['n'] = "Night";

        cout << "Find function define:          ";
        cout << orgM.find('b')->first << " => " << orgM.find('b')->second << endl;
        cout << "Count function define:         ";
        cout << orgM.count('a') << endl; // belirtilen anahtarın map içinde kaç kez bulunduğunu döndürür.
        cout << "Count function define again:   ";
        cout << orgM.count('x') << endl; // 'x' olmadigi icin '0' donecek.
        cout << "Equal range define             " << endl; // equal range verilen key degerinin ilk iterator'unu (lower) ve bir sonra ki (upper) iterator'unu dondurur. Bunlari da 'pair' nesnesine dondurur.
        eqalR = orgM.equal_range('b');
        cout << "Lower bound points to:         " << eqalR.first->first  << " => " << eqalR.first->second << endl;
        cout << "Upper bound points to:         " << eqalR.second->first << " => " << eqalR.second->second << endl;
        for (itlow = orgM.begin(); itlow != orgM.end() ; ++itlow)
            cout << itlow->first << " => " << itlow->second << endl;

        cout << "--------------------/ Fake Operations Functions Defines \\--------------------" << endl << endl;

        ft::map<char, string> ftM;
        ft::map<char, string>::iterator ftitlow, ftitup;
        ft::pair<ft::map<char, string>::iterator, ft::map<char, string>::iterator> fteqalR;

        ftM['b'] = "Batman";
        ftM['a'] = "Arkham";
        ftM['q'] = "Aard";
        ftM['j'] = "Joker";
        ftM['n'] = "Night";

        cout << "Find function define:          ";
        cout << ftM.find('b')->first << " => " << ftM.find('b')->second << endl;
        cout << "Count function define:         ";
        cout << ftM.count('a') << endl;
        cout << "Count function define again:   ";
        cout << ftM.count('x') << endl;
        cout << "Equal range define             " << endl;
        eqalR = orgM.equal_range('b');
        cout << "Lower bound points to:         " << eqalR.first->first  << " => " << eqalR.first->second << endl;
        cout << "Upper bound points to:         " << eqalR.second->first << " => " << eqalR.second->second << endl;
        for (ftitlow = ftM.begin(); ftitlow != ftM.end() ; ++ftitlow)
            cout << ftitlow->first << " => " << ftitlow->second << endl;
        cout << endl << " -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;

    }

}