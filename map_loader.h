/** 
* @file map_loader.h 
* @brief 
*
* @author RISK
*
* @date 2012-07-27
*/

#include <iostream>
#include <string>
using namespace std;

// Replacement function for the map_file_load function
void LoadMapFromFile(std::string file)
{
	if( file.empty() )
	{
		std::cout << "Failed due to not specifying a map file to load" << std::endl;
	}
	else
	{
		for(int k=0; k<9; k++)
		{
			ifstream map_file; // Filebuffer object
			map_file.open(file.c_str());
			
			int value;
			map_file >> value; 
			std::cout << value << std::endl;
		}
		cin.get(); // pause and wait for user keypress
	}
};

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
