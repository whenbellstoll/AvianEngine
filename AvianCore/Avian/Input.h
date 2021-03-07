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

#ifdef _DEBUG
//#define DirectInputError(ErrCode) DirectInput::DIError(__FILE__,__LINE__,ErrCode)
#else
#define DirectInputError(ErrCode)
#endif


#endif
