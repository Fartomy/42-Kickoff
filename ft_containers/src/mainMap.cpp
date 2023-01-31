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

        cout << endl << " -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
    }
}