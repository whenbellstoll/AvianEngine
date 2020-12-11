#ifndef _STREAMEDSOUND_H_
#define _STREAMEDSOUND_H_

class FUNCORE_API StreamedSound : public SoundBase  
{
    DWORD m_LastPlayPosition;
    DWORD m_MidBuffer;
	DWORD m_StopOfs;
    bool m_Stop;
	BYTE * LostBuffer;

    void UpdateBuffer();
	void FillFromLostBuffer(); 

	friend class SoundCard;
public:
	
	StreamedSound(const char* SoundName, const char * FileName,bool LoopFlag = false);
	StreamedSound();
	~StreamedSound();
	void SetPlayPercentage(int Percentage);
	void Play();
	void Stop();
	static StreamedSound* Search(const char *name);
	void Save(File &);
	void Load(File &);
	DYNCREATED
};

class FUNCORE_API StreamedSoundPTR
{
	StreamedSound *streamedSoundPtr;
	static StreamedSound * dummyStreamedSoundPtr;
public:
	StreamedSoundPTR(); 
	StreamedSoundPTR(StreamedSound*);
	StreamedSoundPTR(const char *);
	StreamedSound* operator->();
	StreamedSound& operator*();
	StreamedSoundPTR & operator=(StreamedSound*);
	operator StreamedSound *();
};


#endif 
