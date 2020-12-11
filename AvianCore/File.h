#ifndef _FUNFILE_H_
#define _FUNFILE_H_

class node;

struct ID
{
	int id;
	node * address;
};

#pragma warning(disable : 4251)

struct FRECT;

class FUNCORE_API File
{
	FILE * f;
	bool read;
	std::vector<ID> vID;
	int SavedClasses,LoadedClasses;
	bool rcReadOnly;
	HGLOBAL hrm; 
	char *  pr;
	char *  cur;
	DWORD   size;

public:
	enum Mode{READ,WRITE};
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
	void Write(RECT);
	void Write(FunRect);
	void Write(FRECT);

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
	void Read(RECT &);
	void Read(FunRect &);
	void Read(FRECT &);
	
	void Write(node * pn);
	void Read(node * &pn);

	node * CreateObject(char * name);
};


class FUNCORE_API String
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
	friend FUNCORE_API String operator+(const String &,const String &);
	friend FUNCORE_API int    operator==(const String &,const String &);
	friend FUNCORE_API int    operator!=(const String &,const String &);
	friend FUNCORE_API int    operator==(const String &,const char *);
	friend FUNCORE_API int    operator==(const char *,const String &);
	friend FUNCORE_API int    operator!=(const String &,const char *);
	friend FUNCORE_API int    operator!=(const char *,const String &);

	void Load(File &);
	void Save(File &);
};

class UString
{
	WCHAR *pwc;
	UString(const UString &);
	UString& operator  =(const UString&);
public:
	UString(const char *);
	~UString();
	operator WCHAR *();
};


#define DYNCREATED										\
		public:											\
	    static node * CreateObject();					\
		static CREATE cr;                               \
		const char * ClassName();



#define DYNCREATEI(cname)								\
		node * cname::CreateObject(){return new cname;}	\
		CREATE cname::cr(#cname,cname::CreateObject);   \
		const char * cname::ClassName(){ return cr.name;}


struct FUNCORE_API CREATE
{
	String name;
	node * (*pCreateObject)();
	CREATE(char *,node * (*)());
};

bool CurrentDirectory(String &);

#endif
