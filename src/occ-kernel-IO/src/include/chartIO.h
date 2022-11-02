/**
 * @file chartIO.h
 * @brief chartIO, dealing with input
 * 				and output, also the swap of
 * 				informations between dll/so
 * @author xz ^v^
 * @version 0.0.1 dev
 * @date 2022-10-26
 */
#ifndef CHARTIO_H
#define CHARTIO_H
#include <fstream>
#include "chartTypes.h"

#define DEBUG
namespace werdxz{
	
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

	bool _verify(metadata* data);

	void* translate(void* _);

	memstream* readOmgc(char* omgcTitle);

	int test(void);
}

#endif /* CHARTIO_H */
