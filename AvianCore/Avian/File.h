#ifndef _FUNFILE_H_
#define _FUNFILE_H_

#include <vector>
#include "Constants.h"
class node;

struct ID
{
	int id;
	node * address;
};

#pragma warning(disable : 4251)

struct FRECT;
enum Mode { READ, WRITE };
class   File
{
	FILE * f;
	bool read = false;
	std::vector<ID> vID;
	int SavedClasses,LoadedClasses = 0;
	bool rcReadOnly = false;
	void * hrm = nullptr; 
	char* pr = 0;
	char *  cur = 0;
	long   size = 0;

public:
	
	File(const char * name,Mode m);
	~File();
	long Size();
	void SeekBegin(long l);
	void SeekCur(long l);
	void SeekEnd(long l);
	long Position();
	bool EndOfFile();
	void Write(const void * p,int s);
	void Read(void * p,int s);
	
	void Write(bool);
	void Write(unsigned char);
	void Write(unsigned short);
	void Write(unsigned int);
	void Write(unsigned long);
	void Write(char);
	void Write(short);
	void Write(int);
	void Write(long);
	void Write(float);
	void Write(double);
	void Write(Rect);

	void Read(bool &);
	void Read(unsigned char &);
	void Read(unsigned short &);
	void Read(unsigned int &);
	void Read(unsigned long &);
	void Read(char &);
	void Read(short &);
	void Read(int &);
	void Read(long &);
	void Read(float &);
	void Read(double &);
	void Read(Rect&);
	
	void Write(node * pn);
	void Read(node * &pn);

	node * CreateObject(char * name);
};


class   String
{
	char * pc;
public:
	
	String(const char * = 0);
	String(const String &);
	~String();
	
	operator const char *() const;
	int  length() const;
	bool empty()  const;
	void erase();
	void assign(const char *,int);
	
	String & operator  =(const String &);
	String & operator +=(const String &);
	friend   String operator+(const String &,const String &);
	friend   int    operator==(const String &,const String &);
	friend   int    operator!=(const String &,const String &);
	friend   int    operator==(const String &,const char *);
	friend   int    operator==(const char *,const String &);
	friend   int    operator!=(const String &,const char *);
	friend   int    operator!=(const char *,const String &);

	void Load(File &);
	void Save(File &);
};

class UString
{
	wchar_t *pwc;
	UString(const UString &);
	UString& operator  =(const UString&);
public:
	UString(const char *);
	~UString();
	operator wchar_t *();
};


#define DYNCREATED										\
		public:											\
	    static node * CreateObject();					\
		static CREATE cr;                               \
		const char * ClassName();



#define DYNCREATEIMP(cname)								\
	const char * cname::ClassName(){ return #cname;}	\
	node * cname::CreateObject(){return new cname;}		
	//CREATE cname::cr(#cname,&cname::CreateObject);   \ //causes memory leaks.
		


struct CREATE
{
	const char * name;
	node * (*pCreateObject)();
	CREATE(const char *,node * (*)());
};

bool CurrentDirectory(String & u);

#endif
