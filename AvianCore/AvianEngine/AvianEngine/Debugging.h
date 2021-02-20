#ifndef _DEBUGGING_H_
#define _DEBUGGING_H_

#ifdef  ERROR_MESSAGES 
#define Trace(str)       pConsole->Print(str)
#define Trace1(str,a1)     pConsole->Print(str,(a1))
#define Trace2(str,a1,a2)     pConsole->Print(str,(a1),(a2)) 
#define Trace3(str,a1,a2,a3)     pConsole->Print(str,(a1),(a2),(a3))  
#define Trace4(str,a1,a2,a3,a4)     pConsole->Print(str,(a1),(a2),(a3),(a4))  
#define Trace5(str,a1,a2,a3,a4,a5)     pConsole->Print(str,(a1),(a2),(a3),(a4),(a5))  
#define Trace6(str,a1,a2,a3,a4,a5,a6)     pConsole->Print(str,(a1),(a2),(a3),(a4),(a5),(a6)) 
#define Trace7(str,a1,a2,a3,a4,a5,a6,a7)     pConsole->Print(str,(a1),(a2),(a3),(a4),(a5),(a6),(a7))  
#define Trace8(str,a1,a2,a3,a4,a5,a6,a7,a8)     pConsole->Print(str,(a1),(a2),(a3),(a4),(a5),(a6),(a7),(a8))  
#define Trace9(str,a1,a2,a3,a4,a5,a6,a7,a8,a9)     pConsole->Print(str,(a1),(a2),(a3),(a4),(a5),(a6),(a7),(a8),(a9))
#else
#define Trace(str)       
#define Trace1(str,a1)   
#define Trace2(str,a1,a2)
#define Trace3(str,a1,a2,a3)
#define Trace4(str,a1,a2,a3,a4)     
#define Trace5(str,a1,a2,a3,a4,a5)   
#define Trace6(str,a1,a2,a3,a4,a5,a6)
#define Trace7(str,a1,a2,a3,a4,a5,a6,a7)
#define Trace8(str,a1,a2,a3,a4,a5,a6,a7,a8) 
#define Trace9(str,a1,a2,a3,a4,a5,a6,a7,a8,a9) 
#endif

#ifdef ERROR_MESSAGES
class   Console  
{
	Variable buffer;
	void Display();
public:
	Console();
	~Console();
	void Show(bool);
	bool Show();
	void Color(COLORREF); 
	void Print(const char *,...);
	friend void GameLoopBody();
	friend void RestoreAllSurfaces();
	friend void ToggleMode();
	friend void ExitMessage(const char *,...);
};


struct   UserError
{
	char objectName[256];
	char objectType[256];
	char stateMachineName[256];
	char stateName[256];
	char edgeName[256];
	char functionName[256];
	char targetFunction[256];
	char message[512];
	UserError();
	void Print();
	void ExitMessage();
	bool operator==(const UserError &);
	static Array<UserError> SpritesErrors;
	static Array<UserError> MapsErrors;
	static Array<UserError> VariablesErrors;
	static Array<UserError> AlarmsErrors;
	static Array<UserError> GameErrors;
	static Array<UserError> Errors;
};
#endif

void ExitMessage(const char *,...);

#endif 
