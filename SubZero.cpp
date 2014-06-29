// SubZero.cpp : Defines the entry point for the console application.
//
#include <string>
#include <fstream>
#include <iostream>
#include <direct.h>
#include <ctime>
#include <io.h>  
#include <sys/types.h> 
#include <sys/stat.h>
using namespace std;


bool isDir(const char * path)
{
	// reference to stat.h :http://linux.die.net/man/3/stat
	// returns 0 if the file has the given mode. The function returns –1 if the named file does not exist or does not have the given mode
	 if( _access( path, 0 ) == 0 )
	 {
        struct stat status;
        stat( path, &status );
        return (status.st_mode & S_IFDIR) != 0;
    }
	return false;
}

bool createDir()
{
	static const char* const path[] = {"C:\\Subzero", "C:\\Subzero\\Init"};
	for(int i=0; i<2; i++)
	{
		if(!isDir(path[i]))
		{
			if(!_mkdir(path[i])==0)
			{
				cout<<"Problem creating dir at level "<<path[i]<<endl;
				return false;
			}
		}
		else
		{
			cout<<"Directory exist "<<path[i]<<endl;
			return false;
		}
	}
	return true;
}
bool createFile()
{
	//writting to a file reference: http://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm
	const char *path="C:\\Subzero\\Init\\file.txt";
	ifstream  exist(path, ios::in);
	if(!exist)
	{
		ofstream file(path);
		if(!file) return false;
		file.close();
	}
	else
	{
		cout<<"File at location "<<path<< " already exist"<<endl;
	}
	return true;
}

void start()
{
	//more info on c++ time function at: http://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
	time_t currtime;
	time(&currtime);
	string now= ctime (&currtime);

	cout<<"Subzero Password Manager"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

	if(createDir()) cout<<"Directory structure created successfully. "<<now<<endl;
	if(createFile()) cout<<"Initial file created successfully. "<<now<<endl;

}

int main(void)
{
	start();
	return 0;
}

