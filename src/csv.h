/**
 * @author Dagan Poulin
 * @brief Class for a single CSV Line
 * @assignment Lab 10.2
 * @date 11/13 12:42 AM
 **/
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/**
*@brief Struct containing information of the currently relevant CSV file, used to wrap values into one easy-to-duplicate form factor.
*@date 11/13/2020
*/
struct csv
{
    static vector<csv*> csvList;
    
    string CountryName;
    string CapitalName;
    string CapitalLatitude;
    string CapitalLongitude;
    string CountryCode;
    string ContinentName;

    csv();
    csv(string ToParse);

    string getCountryName() { return CountryName; }
    string getCapitalName() { return CapitalName; }
    string getCapitalLongitude() { return CapitalLongitude; }
    string getCapitalLatitude() { return CapitalLatitude; }
    string getCountryCode() { return CountryCode; }
    string getContinentName() { return ContinentName; }

};

int processCSV(ifstream &inFile); // An external yet related function
int saveKML(ostream& output);