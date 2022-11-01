#include "chartIO.h"
#include "chartTypes.h"

#include <iostream>
#include <cstdio>

using namespace werdxz;
using namespace std;

int main(int argv, char* argc[]){

	
	const char INPUT_FILE_FLAG[] = "-r";
	const char OUTPUT_FILE_FLAG[] = "-o";
	const char ENABLE_OUTPUT_ALL_FLAG[] = "-a";
	const char OUTPUT_FILE_SEPERATLY[] = "-s";

	char readFrom[32]={0};
	char writeTo[32]={0};
	bool enableOutputAll=false;
	bool outputSeperatly=false; 

	bool readInputFlag=false;
	bool readOutputFlag=false;

	for(int i=1;i<argv;i++){
		if(!strcmp(argc[i],INPUT_FILE_FLAG)){
			cout<<"get ipf flg"<<endl;
			if(i+1<argv){
				strcpy(readFrom,argc[i+1]);
				readInputFlag=true;
			}
		}
		if(!strcmp(argc[i],OUTPUT_FILE_FLAG)){
			cout<<"get opf flg"<<endl;
			if(i+1<argv){
				strcpy(writeTo,argc[i+1]);
				readOutputFlag=true;
			}
		}
		if(!strcmp(argc[i],ENABLE_OUTPUT_ALL_FLAG)){
			cout<<"get dbg flag"<<endl;
			enableOutputAll=true;
		}
		if(!strcmp(argc[i],OUTPUT_FILE_SEPERATLY)){
			outputSeperatly=true;
		}
	}


	if(((!readInputFlag)&&(!readOutputFlag))||(strcmp(readFrom,"\0")==0)||(strcmp(writeTo,"\0")==0)){
		cout<<"error, no file specified\n"
				<<"-r <file to read>\n"
				<<"-o <file to dump>\n"
				<<"\n";
		return 1;
		
	}
	return 0;
}
