#ifndef _INPUT_H_
#define _INPUT_H_


struct Key
{
	bool PreviousState;         
	bool Press;					
	bool Trigger;				
	unsigned int TapCounter;
	unsigned int TapCounterP;
	unsigned int HoldCounter;	
};

struct DImp;

class FUNCORE_API DirectInput
{
	static unsigned int References;
	static HWND hWnd;

public:

	DImp * pDImp;
	DirectInput(HWND,HINSTANCE);
	~DirectInput();
	static void DIError(LPCSTR FileName,int Line,HRESULT ErrCode);
};

#ifdef _DEBUG
#define DirectInputError(ErrCode) DirectInput::DIError(__FILE__,__LINE__,ErrCode)
#else
#define DirectInputError(ErrCode)
#endif


#endif
