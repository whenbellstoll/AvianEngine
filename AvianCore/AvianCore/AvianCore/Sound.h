#ifndef _SOUND_H_
#define _SOUND_H_

class FUNCORE_API Sound : public SoundBase  
{
	int m_PlayPercentage;

public:

	Sound(const char* SoundName,const char *FileName,bool LoopFlag = false,int PlayPercentage = 100);
	Sound();
	~Sound();
	void SetPlayPercentage(int Percentage);
	void Play();
	void Stop();
	static Sound* Search(const char *);

	void Save(File &);
	void Load(File &);
	DYNCREATED
};

class FUNCORE_API SoundPTR
{
	Sound *soundPtr;
	static Sound * dummySoundPtr;
public:
	SoundPTR(); 
	SoundPTR(Sound*);
	SoundPTR(const char *);
	Sound* operator->();
	Sound& operator*();
	SoundPTR & operator=(Sound*);
	operator Sound *();
};


#endif 
