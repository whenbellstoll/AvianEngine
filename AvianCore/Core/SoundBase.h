#ifndef _SOUNDBASE_H_
#define _SOUNDBASE_H_


struct SBImp;

class   SoundBase:public node    
{

	WAVEFORMATEX* m_pwfx;      
	HMMIO         m_hmmioIn;   
	MMCKINFO      m_ckIn;        
    MMCKINFO      m_ckInRiff;    

	bool m_IsMeStreamedSound;
	bool m_PausedBySoundCard;
	int id;
	String name;
	String fileName;

	friend class SoundCard;

protected:    

	HRESULT Open(const char* FileName );
    HRESULT Reset();
	HRESULT Read( UINT nSizeToRead, BYTE* pbData, UINT* pnSizeRead );
	HRESULT Advance(UINT nBytes);
	HRESULT Close();
	SBImp * pSBImp;

	DWORD m_PausePosition;
	bool m_LoopFlag;
	bool RestoreBuffer();
	void FillBuffer();
	bool IsBufferLost();
	int volume;
	int pan;
	int bytesReaded; 

public:


	SoundBase(const char* SoundName,const char * FileName,bool LoopFlag,bool IsMeStreamedSound);
	SoundBase();
	~SoundBase();
	bool IsPlaying();
	virtual void Play() {};
	virtual void Stop() {};
	void Pause();
	void SetVolume(int Volume); //0 -> -10000
	void SetPan(int Pan); //-10,000 -> 0 -> 10,000 
	void SetLoopFlag(bool LoopFlag);
	void Id(int);
    int  Id();
	void Name(const char*);
	const char* Name();

	void Save(File & file);
	void Load(File & file);

	DYNCREATED			
};


#endif 
