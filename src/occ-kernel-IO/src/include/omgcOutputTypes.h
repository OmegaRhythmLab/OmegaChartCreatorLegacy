/**
 * @file omgeOutputTypes.h  
 * @brief defination of all input struct
 * 				for omgc file ver 2
 * @author xz ^v^ 
 * @version 0.0.1 dev
 * @date 2022-10-26
 */

#ifndef OMGCOUTPUTTYPES_H
#define OMGCOUTPUTTYPES_H

#include <cstdint>

#define NONE 0

#define COMMAND_PLAY_MUSIC 															0x0000
#define COMMAND_DISPLAY_NOTE														0x0100
#define COMMAND_HIDE_NOTE																0x0101
#define COMMAND_CHANGE_NOTE_VERTICAL_FUNCTION 					0x0110
#define COMMAND_CHANGE_NOTE_HORIZONTAL_FUNCTION_LINEAR	0x0120
#define COMMAND_CHANGE_NOTE_HORIZONTAL_FUNCTION_SINE 		0x0121
#define COMMAND_CHANGE_LINE_TRANSPARENCY_LINEAR					0x0200
#define COMMAND_CHANGE_LINE_TRANSPARENCY_SINE						0x0201
#define COMMAND_CHANGE_LINE_HORIZONTAL_FUNCTION_LINEAR	0x0210
#define COMMAND_CHANGE_LINE_HORIZONTAL_FUNCTION_SINE	 	0x0211

#define VERIFICATION_CODE {0x6f,0x6d,0x67,0x63,0x03,0x00,0x00,0x00}


namespace omega{
typedef float omgfloat;
typedef std::uint32_t omgint;
	// 占位符(
	struct arg{
		char _[4];
	};

	struct metadata{
		char omgc[4];
		omgint omgcVersion;
		omgint lineDataLength;
		omgint lineCount;
		omgint noteDataLength;
		omgint noteCount;
		omgint cmdDataLength;
		omgint cmdCount;
	};

	struct command{
		omgfloat time;
		omgint type;
		omgint argLength;
		arg* args;
	};

	struct note{
		omgint prop;
		omgint lineID;
		omgfloat quadraticCoefficient;
		omgfloat linearCoefficient;
		omgfloat constant;
		omgint displayTrack;
		omgint judgmentTrack;
		omgfloat judgmentTime;
		omgfloat endTime;
		omgfloat length;
	};

	struct line{
		omgfloat position;
		omgfloat alpha;
	};

}
#endif /* OMGCOUTPUTTYPES_H */
