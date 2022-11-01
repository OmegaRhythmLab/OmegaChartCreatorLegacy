#include "chartIO.h"
#include <cstdio>
#include <fstream>

#ifdef DEBUG_MAIN
#include <iostream>
#endif

werdxz::memstream* VARIFICATION_FAILED;

int werdxz::test(){
	return 1;
}

bool werdxz::_verify(werdxz::metadata* data){
	char var[8];
	memcpy(&var,data,8);
	char varCode[8]=VERIFICATION_CODE;
	return memcmp(var,varCode,8)==0;
	return true;
}


/**
 * @brief convert pointer type elangently
 *
 * @param _ input pointer
 *
 * @return whatever it is defined for return type 
 */
void* werdxz::translate(void* _){return _;}

/**
 * @brief 读区omgc文件,其他的你不用管
 *
 * @param omgcTitle 文件名称(或者相对目录
 *
 * @return	0 如果 读取失败, 
 * 					1 如果 验证失败
 * 					否则 memstream*
 */
werdxz::memstream* werdxz::readOmgc(char* omgcTitle){
	std::FILE* file = std::fopen(omgcTitle,"rb");
	if(!file)return 0;

	memstream* output = new memstream;
	output->mdptr = new metadata;

	std::fread(output->mdptr, sizeof(metadata), 1, file);

	if(!werdxz::_verify(output->mdptr))return VARIFICATION_FAILED;

	output->lineList = new line[output->mdptr->lineCount];
	output->noteList = new note[output->mdptr->noteCount];
	output->cmdList = new command[output->mdptr->cmdCount];

	std::fread(output->lineList, sizeof(line), output->mdptr->lineCount, file);
	std::fread(output->noteList, sizeof(note), output->mdptr->noteCount,file);

	for(int i=0; i<output->mdptr->cmdCount; i++){
		std::fread(&(output->cmdList[i]), 12, 1, file);

		arg* temp = new arg[output->cmdList[i].argLength];
		std::fread(temp,sizeof(arg),output->cmdList[i].argLength,file);
		output->cmdList[i].args=temp;
	};
	return output;
};

#ifdef DEBUG_MAIN
using namespace std;
using namespace werdxz;
int main(){
	memstream* res = readOmgc("test.omgc");	

	if(res == VARIFICATION_FAILED){
		cout<<"varification failed"<<endl<<
			"aborting"<<endl;
		return 1;
	}

	ofstream output;
	output.open("debug.log",ofstream::out);

	output<<"omgc version "<<res->mdptr->omgcVersion<<endl;
	output<<"line count   "<<res->mdptr->lineCount<<endl;
	output<<"note count   "<<res->mdptr->noteCount<<endl;
	output<<"cmd count    "<<res->mdptr->cmdCount<<endl;

	output.close();

	ofstream lineOutput;
	lineOutput.open("line.log",ofstream::out);
	for(int i=0; i<res->mdptr->lineCount;i++){
		lineOutput<<"line number:\t"<<i<<"\t"<<"line pos:\t"<<res->lineList[i].position
			<<"\t"<<"transparency:\t"<<res->lineList[i].alpha<<endl;
	}
	lineOutput.close();


	ofstream noteOutput;
	noteOutput.open("note.log",ofstream::out);
	for(int i=0; i<res->mdptr->noteCount;i++){
		noteOutput<<"note line ID:"<<res->noteList[i].lineID<<"\t";
		noteOutput<<"note prop:   "<<res->noteList[i].prop<<"\t";
		noteOutput<<"note length: "<<res->noteList[i].length<<"\t";
		noteOutput<<endl;
	}
	noteOutput.close();

	ofstream cmdOutput;
	cmdOutput.open("cmd.log",ofstream::out);
	for(int i=0;i<res->mdptr->cmdCount;i++){
		cmdOutput<<"line: "<<i+1;
		switch(res->cmdList[i].type){
		case COMMAND_PLAY_MUSIC:
			cmdOutput<<"cmd play music"<<endl;
			break;
		case COMMAND_DISPLAY_NOTE:
			cmdOutput<<"cmd display note"<<endl;
			break;
		case COMMAND_HIDE_NOTE:
			cmdOutput<<"cmd hide note"<<endl;
			break;
		default:
			cmdOutput<<"cmd other"<<endl;
			break;
		}
	}
	cmdOutput.close();
	return 0;
}


#endif
