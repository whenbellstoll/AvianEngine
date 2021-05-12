#ifndef _SOUNDBASE_H_
#define _SOUNDBASE_H_
#include "Node.h"
#include <iostream>
struct SBImp;

class   SoundBase:public node    
{
	const std::size_t NUM_BUFFERS = 4;
	/*const ALsizei BUFFER_SIZE = 65536;

	struct StreamingAudioData
	{
		ALuint buffers[NUM_BUFFERS];
		std::string filename;
		std::ifstream file;
		std::uint8_t channels;
		std::int32_t sampleRate;
		std::uint8_t bitsPerSample;
		ALsizei size;
		ALuint source;
		ALsizei sizeConsumed = 0;
		ALenum format;
		OggVorbis_File oggVorbisFile;
		std::int_fast32_t oggCurrentSection = 0;
		std::size_t duration;
	};

	DYNCREATED	*/		
};


#endif 
