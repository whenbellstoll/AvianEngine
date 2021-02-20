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
// Notes:
// This DirectInput will need completely revised it's based off a DirectX 8 feature of the same name
// This engine is not using DirectX so you will have to find another way to get the input
class   DirectInput
{
	static unsigned int References;
	static HWND hWnd; //Windows Environment Variable

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
