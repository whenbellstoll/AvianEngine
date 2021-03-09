#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_


#define AK_ESCAPE          256
#define AK_1               49
#define AK_2               50
#define AK_3               51
#define AK_4               52
#define AK_5               53
#define AK_6               54
#define AK_7               55
#define AK_8               56
#define AK_9               57
#define AK_0               48
#define AK_MINUS           45  
#define AK_EQUALS          61
#define AK_BACK            259   
#define AK_TAB             258
#define AK_Q               'Q'
#define AK_W               'W'
#define AK_E               'E'
#define AK_R               'R'
#define AK_T               'T'
#define AK_Y               'Y'
#define AK_U               'U'
#define AK_I               'I'
#define AK_O               'O'
#define AK_P               'P'
#define AK_LBRACKET        91
#define AK_RBRACKET        93
#define AK_RETURN          257    
#define AK_LCONTROL        341
#define AK_A               'A'
#define AK_S               'S'
#define AK_D               'D'
#define AK_F               'F'
#define AK_G               'G'
#define AK_H               'H'
#define AK_J               'J'
#define AK_K               'K'
#define AK_L               'L'
#define AK_SEMICOLON       59
#define AK_APOSTROPHE      39
#define AK_GRAVE           96
#define AK_LSHIFT          340
#define AK_BACKSLASH       92
#define AK_Z               'Z'
#define AK_X               'X'
#define AK_C               'C'
#define AK_V               'V'
#define AK_B               'B'
#define AK_N               'N'
#define AK_M               'M'
#define AK_COMMA           44
#define AK_PERIOD          46
#define AK_SLASH           47
#define AK_RSHIFT          344
#define AK_MULTIPLY        0x37
#define AK_LMENU           0x38
#define AK_SPACE           0x39
#define AK_CAPITAL         0x3A
#define AK_F1              0x3B
#define AK_F2              0x3C
#define AK_F3              0x3D
#define AK_F4              0x3E
#define AK_F5              0x3F
#define AK_F6              0x40
#define AK_F7              0x41
#define AK_F8              0x42
#define AK_F9              0x43
#define AK_F10             0x44
#define AK_NUMLOCK         0x45
#define AK_SCROLL          0x46
#define AK_NUMPAD7         0x47
#define AK_NUMPAD8         0x48
#define AK_NUMPAD9         0x49
#define AK_SUBTRACT        0x4A
#define AK_NUMPAD4         0x4B
#define AK_NUMPAD5         0x4C
#define AK_NUMPAD6         0x4D
#define AK_ADD             0x4E
#define AK_NUMPAD1         0x4F
#define AK_NUMPAD2         0x50
#define AK_NUMPAD3         0x51
#define AK_NUMPAD0         0x52
#define AK_DECIMAL         0x53
#define AK_OEM_102         0x56
#define AK_F11             0x57
#define AK_F12             0x58
#define AK_F13             0x64
#define AK_F14             0x65
#define AK_F15             0x66
#define AK_KANA            0x70
#define AK_ABNT_C1         0x73
#define AK_CONVERT         0x79
#define AK_NOCONVERT       0x7B
#define AK_YEN             0x7D
#define AK_ABNT_C2         0x7E
#define AK_NUMPADEQUALS    0x8D
#define AK_PREVTRACK       0x90
#define AK_AT              0x91
#define AK_COLON           0x92
#define AK_UNDERLINE       0x93
#define AK_KANJI           0x94
#define AK_STOP            0x95
#define AK_AX              0x96
#define AK_UNLABELED       0x97
#define AK_NEXTTRACK       0x99
#define AK_NUMPADENTER     0x9C
#define AK_RCONTROL        0x9D
#define AK_MUTE            0xA0
#define AK_CALCULATOR      0xA1
#define AK_PLAYPAUSE       0xA2
#define AK_MEDIASTOP       0xA4
#define AK_VOLUMEDOWN      0xAE
#define AK_VOLUMEUP        0xB0
#define AK_WEBHOME         0xB2
#define AK_NUMPADCOMMA     0xB3
#define AK_DIVIDE          0xB5
#define AK_SYSRQ           0xB7
#define AK_RMENU           0xB8    
#define AK_PAUSE           0xC5    
#define AK_HOME            0xC7    
#define AK_UP              265    
#define AK_PRIOR           0xC9    
#define AK_LEFT            263    
#define AK_RIGHT           262    
#define AK_END             0xCF    
#define AK_DOWN            264    
#define AK_NEXT            0xD1    
#define AK_INSERT          0xD2    
#define AK_DELETE          0xD3    
#define AK_LWIN            0xDB    
#define AK_RWIN            0xDC    
#define AK_APPS            0xDD    
#define AK_POWER           0xDE    
#define AK_SLEEP           0xDF    
#define AK_WAKE            0xE3    
#define AK_WEBSEARCH       0xE5    
#define AK_WEBFAVORITES    0xE6    
#define AK_WEBREFRESH      0xE7    
#define AK_WEBSTOP         0xE8   
#define AK_WEBFORWARD      0xE9   
#define AK_WEBBACK         0xEA   
#define AK_MYCOMPUTER      0xEB   
#define AK_MAIL            0xEC   
#define AK_MEDIASELECT     0xED   


#define AK_BACKSPACE       AK_BACK           
#define AK_NUMPADSTAR      AK_MULTIPLY       
#define AK_LALT            AK_LMENU          
#define AK_CAPSLOCK        AK_CAPITAL        
#define AK_NUMPADMINUS     AK_SUBTRACT       
#define AK_NUMPADPLUS      AK_ADD            
#define AK_NUMPADPERIOD    AK_DECIMAL        
#define AK_NUMPADSLASH     AK_DIVIDE         
#define AK_RALT            AK_RMENU          
#define AK_UPARROW         AK_UP            
#define AK_PGUP            AK_PRIOR         
#define AK_LEFTARROW       AK_LEFT          
#define AK_RIGHTARROW      AK_RIGHT         
#define AK_DOWNARROW       AK_DOWN          
#define AK_PGDN            AK_NEXT           


#define AK_CIRCUMFLEX      AK_PREVTRACK      






#define kSpriteMaximum			513
#define kMapMaximum				512
#define kParticleSystemMaximum  512
#define kVariableMaximum		1024
#define kSoundMaximum			1024
#define kStreamedSoundMaximum	128
#define kMidiFileMaximum        128
#define kAlarmMaximum			512
#define MAXHOTSPOTS				5
#define MAXACTORS				2 //1001
#define kMaxSpriteType			16
#define kMaxSpriteCollisions	10
#define kMaxCollisionData		15
#define MAXCOLLISIONSEGMENTS    4096
#define MAXCOLLISIONCIRCLES     4096
#define kMaxTextsMap			1024
#define Normal					1
#define OppositeX				2
#define OppositeY				3
#define OppositeXY				4	
#define PI						3.1415926535897932
#define BUFFER_SIZE				256       
#define CHARACTER				0
#define NUMBER					1
#define PRECISECOLLISION		0
#define LOOSECOLLISION			1
#define RIGHT					0
#define LEFT					1
#define DOWN					2
#define UP						3
#define SPRITE					0
#define MAP						1
#define SPRITEANDMAP			2
#define DIM_LEFT				0
#define DIM_RIGHT				1
#define DIM_MIDDLE				2
#define BOTH                    0
#define SEGMENT                 1
#define CIRCLE                  2
#define DEFAULT_CURSOR          2000
#define ApplyingShortestPath()		pathStateMachine.ShortPath()

struct Rect{
	long left;
	long top;
	long right;
	long bottom;
};

struct Point{
	long x;
	long y;
};

struct COLORREF {
	char r;
	char g;
	char b;
};

COLORREF RGB(char r, char g, char b);


#endif
