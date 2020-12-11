#ifndef _SOUNDCARD_H_
#define _SOUNDCARD_H_


struct SCImp;

class FUNCORE_API SoundCard  
{
	SCImp * pSCImp;	
	int m_nChannels;
	int m_BitsPerSample;
	int m_SamplingRate;
	static bool m_Created;
    static HWND m_GameWindow;
	
	friend class SoundBase;
	friend class Sound;
	friend class StreamedSound;
	friend class MidiFile;

	static void DSError(LPCSTR FileName,int Line,HRESULT ErrCode);

public:
	
	SoundCard(int SamplingRate ,int BitsPerSample ,int nChannels ,HWND GameWindow);
	~SoundCard();
	void UpdateBuffers();
	void ManageBuffers(bool FocusState); 

	SCImp*  DirectSound();
};


SoundCard * GetSoundCard();

#ifdef _DEBUG
#define DirectSoundError(ErrCode) SoundCard::DSError(__FILE__,__LINE__,ErrCode)
#else
#define DirectSoundError(ErrCode)
#endif


#endif 
