/**
 * @file chartIO.h
 * @brief chartIO, dealing with input
 * 				and output, also the swap of
 * 				informations between dll/so
 * @author xz ^v^
 * @version 0.0.1 dev
 * @date 2022-10-26
 */
#ifndef OMGCOUTPUT_H
#define OMGCOUTPUT_H
#include <fstream>
#include "./omgcOutputTypes.h" 

namespace omega{
	
	struct memstream{
			metadata* mdptr;
			line* lineList;
			note* noteList;
			command* cmdList;
	};

	//strange output for .dat in c-like version
	struct fileInputStream{
		// a 4 bytes char to store the output for every
		// line in .omgc
		// 4 字节
		// 存参数够了吧...
		// 给 .omgc 文件
		char _[4];
	};
	void* translate(void* _);

#ifdef READ_OMGC_ENABLED
	bool _verify(metadata* data);

	memstream* readOmgc(char* omgcTitle);
#endif
}

#endif /* OMGCOUTPUT_H */
