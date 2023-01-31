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
        cout << " -*-*-*-*-*-*-*-*-*-*-*-*-*-/ UNDERSTANDING TO MAP \\-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "--------------------/ Phonebook and Circuit Example \\--------------------" << endl << endl;
        std::map<string, int> phoneBook;
        std::map<string, bool> circuit;

        phoneBook["Furkan"] = 5235;
        phoneBook["Ali"] = 5422;
        phoneBook["Faruk"] = 5671;
        phoneBook["Faruk"] = 5671; // Ayni degeri eklemiyor cunku anahtar deger ikilileri benzersizdir
        phoneBook["Faruk"] = 42; // Fakat deger guncellenebilir

        std::map<string, int>::iterator it;
        for (it = phoneBook.begin(); it != phoneBook.end() ; ++it)
            cout << it->first << " " << it->second << endl;

        cout << endl;

        circuit["Open"] = true;
        circuit["Off"] = false;
        circuit["Off"] = false; // ❌

        std::map<string, bool>::iterator cit;
        for (cit = circuit.begin(); cit != circuit.end(); ++cit)
            cout << cit->first << " " << cit->second << endl;
    }

    {
        cout << endl << " -*-*-*-*-*-*-*-*-*-*-*-*-*-/ CONSTRUCTOR AND ASSIGMENT OPERATOR TEST CASES [1] \\-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
        cout << "--------------------/ Original Map Constructor Defines \\--------------------" << endl << endl;

        std::map<int, string> orgM;
        std::map<int, string> oprOrgM;
        orgM[0] = "Zero";
        orgM[1] = "One";
        orgM[2] = "Second";
        std::map<int, string> rngOrgM(orgM.begin(), orgM.end());
        std::map<int, string>::iterator orgit;
        cout << endl << "[ Range Constructor Define ]\n" << endl;
        for (orgit = rngOrgM.begin(); orgit != rngOrgM.end() ; ++orgit)
            cout << orgit->first << " " << orgit->second << endl;
        std::map<int, string> copyOrgM(rngOrgM);
        cout << endl << "[ Copy Constructor Define ]\n" << endl;
        for (orgit = copyOrgM.begin(); orgit != copyOrgM.end(); ++orgit)
            cout << orgit->first << " " << orgit->second << endl;
        cout << endl << "[ Operator Assignment Define ]\n" << endl;
        oprOrgM = copyOrgM;
        for (orgit = oprOrgM.begin(); orgit != oprOrgM.end() ; ++orgit)
            cout << orgit->first << " " << orgit->second << endl;

        cout << endl << "--------------------/ Fake Map Constructor Defines \\--------------------" << endl << endl;
        ft::map<int, string> ftM;
        ft::map<int, string> oprftM;
        ftM[0] = "Zero";
        ftM[1] = "One";
        ftM[2] = "Second";
        ft::map<int, string> rngftM(ftM.begin(), ftM.end());
        ft::map<int, string>::iterator ftit;
        cout << endl << "[ Range Constructor Define ]\n" << endl;
        for (ftit = rngftM.begin(); ftit != rngftM.end() ; ++ftit)
            cout << ftit->first << " " << ftit->second << endl;
        ft::map<int, string> copyftM(rngftM);
        cout << endl << "[ Copy Constructor Define ]\n" << endl;
        for (ftit = copyftM.begin(); ftit != copyftM.end(); ++ftit)
            cout << ftit->first << " " << ftit->second << endl;
        cout << endl << "[ Operator Assignment Define ]\n" << endl;
        oprftM = copyftM;
        for (ftit = oprftM.begin(); ftit != oprftM.end() ; ++ftit)
            cout << ftit->first << " " << ftit->second << endl;


        cout << endl << " -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;

    }
}