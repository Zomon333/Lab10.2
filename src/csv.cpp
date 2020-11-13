/**
 * @author Dagan Poulin
 * @brief Class implementation for a single CSV Line
 * @assignment Lab 10.2
 * @date 11/13 12:42 AM
 **/
#include "csv.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

vector<csv*> csv::csvList;


/**
*@brief Saves the csvList to a KML file
*@date 11/13/2020
*@return returns an int indicating the message was written ok
*@param output ostream reference to which info is saved, validation is expected beforehand.
*/
int saveKML(ostream& output)
{
    output<<"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"<<endl;
    output<<"<kml xmlns=\"http://www.opengis.net/kml/2.2\">"<<endl;
    output<<"<Document>"<<endl;
    
    int i = 0;
    cout<<"i: "<<i<<"  csvList.size(): "<<csv::csvList.size()<<endl;
    while(i<csv::csvList.size())
    {
        output<<"<Placemark>"<<endl;
        output<<"<name>"<<csv::csvList[i]->getCountryName()<<"</name>"<<endl;
        output<<"<Point><coordinates>"<<csv::csvList[i]->getCapitalLongitude()<<","<<csv::csvList[i]->getCapitalLatitude()<<"</coordinates></Point>"<<endl;
        output<<"</Placemark>"<<endl;
        i++;
    }

    output<<"</Document>"<<endl;
    output<<"</kml>"<<endl;

    return EXIT_SUCCESS;
}

/**
*@brief Breaks the CSV into separate lines and pushes them all into a vector.
*@date 11/13/2020
*@return returns an int indicating success or failure
*@param inFile The CSV file which will be read by processCSV
*/
int processCSV(ifstream &inFile) // Grabs all the lines from the CSV and adds them to the csv-class vector.
{
    string line="";
    if(inFile.peek()!=EOF) //As long as the file is more than zero indexes long...
    do //Add the contents to the csv array at least once
    {
        getline(inFile, line);
        csv::csvList.push_back(new csv(line));
    } while (inFile.peek()!=EOF);

    if(csv::csvList.size()==0) return EXIT_FAILURE; //Returns false if it fails, true if it succeeds
    else return EXIT_SUCCESS;
}

/**
*@brief CDefault CSV Constructor
*@date 11/13/2020
*@return None
*/
csv::csv() //Default constructor for a CSV instance
{
    CountryName="CountryName"; //0
    CapitalName="Capitalname"; //1
    CapitalLatitude=""; //2
    CapitalLongitude=""; //3
    CountryCode="CountryCode"; //4
    ContinentName="ContinentName"; //5
}

/**
*@brief Secondary CSV Constructor; parses info from a raw line
*@date 11/13/2020
*@return None
*/
csv::csv(string ToParse) //Constructor to parse info for CSV instance from a line
{
    int parsePosition=0;
    int i=0;

    string parsedSection="";

    while(ToParse[i]!=NULL)
    {
        if(ToParse[i]!=',')
        {
            parsedSection+=ToParse[i];
            i++;
        }
        else
        {
            switch(parsePosition)
            {
                case 0:
                    CountryName=parsedSection;
                    parsedSection="";
                    parsePosition++;
                    i++;
                    break;
                case 1:
                    CapitalName=parsedSection;
                    parsedSection="";
                    parsePosition++;
                    i++;
                    break;
                case 2:
                    CapitalLatitude=parsedSection;
                    parsedSection="";
                    parsePosition++;
                    i++;
                    break;
                case 3:
                    CapitalLongitude=parsedSection;
                    parsedSection="";
                    parsePosition++;
                    i++;
                    break;
                case 4:
                    CountryCode=parsedSection;
                    parsedSection="";
                    parsePosition++;
                    i++;
                    break;
                case 5:
                    ContinentName=parsedSection;
                    parsedSection="";
                    parsePosition++;
                    i++;
                    break;
                default:
                    return;
            }
        } 
    }
}