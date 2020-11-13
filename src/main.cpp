/**
 * @author Dagan Poulin
 * @brief main Lab10.2
 * @assignment Lab 10.2
 * @credit Devin Paden
 * @date 11/13 12:42 AM
 **/
#include "logger.h"
#include "csv.h"
using namespace std;

/**
*@brief Main function, controls other functions
*@date 11/13/2020
*@return returns a boolean indicating the message was written ok
*@param argc Int number of arguments
*@param argv char* list of other arguments
*@param env char* list of environment variables
*/
int main(int argc, char* argv[], char* env[])
{
	int opt{};
	bool kmlFlag{false};
	bool logFlag{false};
	string kmlValue;
	string logValue;
	bool optErr=true;
	
	while ((opt = getopt(argc, argv, "k:l:")) != EOF) //Check args
	{
		switch(opt)
		{
			case 'k':
				kmlFlag = true;
				kmlValue = optarg;
				break;
			case 'l':
				logFlag = true;
				logValue = optarg;
				break;
			default:
				optErr=true;
				break;
		}
	}
	cout<< "flags - kmlFlag:" << kmlFlag << " logFlag:" << logFlag << endl; //State args validity
	
	if(kmlFlag&&logFlag)
	{
		cout<<"flags set!"<<endl;
		if(logValue.empty()||kmlValue.empty()) 
		{
			optErr=true;
			cout << "Option arguments are not set" <<endl;
		}
		else
		{
			optErr = false;
		}
		
	}
	else
	{
		cout << "error - flags are not set! "<<endl;
		optErr = true;

	}
	
	if(optErr) //Exit with failure if it fails
	{
		return EXIT_FAILURE;
	}
	
	ofstream file; //Open log file
	file.open(logValue, ios::app);

	if(!file)
	{
		return EXIT_FAILURE;
	}

	string name = basename(argv[0]); //Get some basic info to log
	string msg = "The kmlfile is: " + kmlValue + " and logfile is: " + logValue;

	log(msg,file,name); //Log the info

	
	ifstream csvFile; //Open the CSV file
	csvFile.open(kmlValue);
	processCSV(csvFile); //Process it's contents into the static csv vector

	ofstream kmlFile; //Open a KML file for output
	kmlFile.open((kmlValue+".kml"));
	saveKML(kmlFile); //Process the contents of the static csv vector into the kml file

	cout<<"\n\n\n"; //Throw in some newlines for legibility.
	file.close(); //Close all 3 files
	csvFile.close();
	kmlFile.close();

	int i = 0;
	while(i<csv::csvList.size()) //Deleting allocated memory
	{
		delete csv::csvList[i];
		csv::csvList[i]=nullptr;
		i++;
	}
	csv::csvList.clear(); //Clearing the array.

	return EXIT_SUCCESS;

}
