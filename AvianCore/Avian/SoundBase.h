#ifndef _SOUNDBASE_H_
#define _SOUNDBASE_H_
#include "Node.h"
#include <cassert>
#include <cmath>
#include <map>
#include <iostream>
#include <fstream>
#include <ogg\ogg.h>
//#include <vorbis/codec.h>
using namespace std;

class OggStream;

class VorbisDecode {
/*public:
	vorbis_info info;
	vorbis_comment comment;
	vorbis_dsp_state dsp;
	vorbis_block block;
*/
public:
	VorbisDecode()
	{
		/*vorbis_info_init(&info);
		vorbis_comment_init(&comment);*/
	}

	void initForData(OggStream* stream);
};

class OggStream
{
public:
	int serial;
	ogg_stream_state state;
	VorbisDecode vorbis;
	bool active;

public:
	OggStream(int serial = -1) :
		serial(serial),
		active(true)
	{
	}

	~OggStream() {
		int ret = ogg_stream_clear(&state);
		assert(ret == 0);
	}
};

typedef map<int, OggStream*> StreamMap;


class OggDecoder
{
public:
	StreamMap mStreams;

	//sa_stream_t* audio;
	ogg_int64_t  granulepos;

private:
	bool handle_vorbis_header(OggStream* stream, ogg_packet* packet);
	void read_headers(istream& stream, ogg_sync_state* state);

	bool read_page(istream& stream, ogg_sync_state* state, ogg_page* page);
	bool read_packet(istream& is, ogg_sync_state* state, OggStream* stream, ogg_packet* packet);

public:
	OggDecoder() :
		//audio(0),
		granulepos(0)
	{
	}

	~OggDecoder() {
		/*if (audio) {
			sa_stream_drain(audio);
			sa_stream_destroy(audio);
		}*/
	}
	void play(istream& stream);
};

#endif 
