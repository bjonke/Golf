/** 
* @file map_loader.h 
* @brief this header file will contain all required 
* definitions and basic utilities functions.
*
* @author RISK
*
* @date 2012-07-27
*/

#include <string>
using namespace std;

	/**
	* This method will be used for sound.
	* @author RISK
	* @date 2012-07-27
	*/
bool map_file_load(std::string map_file_name)
{
	if( map_file_name.empty() )
	{
		fprintf(stderr, "Calling map_file_load without any file parameter\n");
		//exit();
		return false;
	}
	else
	{
		for(int k=0; k<9; k++)
		{
			ifstream map_file;
			map_file.open(map_file_name.c_str());
			int value;
			map_file >> value; 
			printf("%d\n",value);
		}
		cin.get();
		exit(0);
	}
	return true;
}