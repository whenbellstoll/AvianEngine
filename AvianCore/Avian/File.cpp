#include "File.h"

File::File(const char* name, Mode m)
{
	f = nullptr;
	SavedClasses = 0;
	LoadedClasses = 0;
	if (m == 0)
	{
		f = fopen(name, "r");
		read = true;
		rcReadOnly = true;
	}
	else if (m == 1)
	{
		f = fopen(name, "w");
		read = false; 
		rcReadOnly = false;
	}
	else
	{
		return;
	}
	size = sizeof(f);
	pr = (char *)f;
	cur = pr;

}

File::~File()
{
	delete f;
}

long File::Size()
{
	return size;
}

void File::SeekBegin(long l)
{

}

void File::SeekCur(long l)
{
}

void File::SeekEnd(long l)
{
}

long File::Position()
{
	return 0;
}

bool File::EndOfFile()
{
	return false;
}

void File::Write(const void* p, int s)
{
}

void File::Read(void* p, int s)
{
}

void File::Write(bool)
{
}

void File::Write(unsigned char)
{
}

void File::Write(unsigned short)
{
}

void File::Write(unsigned int)
{
}

void File::Write(unsigned long)
{
}

void File::Write(char)
{
}

void File::Write(short)
{
}

void File::Write(int)
{
}

void File::Write(long)
{
}

void File::Write(float)
{
}

void File::Write(double)
{
}

void File::Write(Rect a)
{
}


void File::Read(bool&)
{
}

void File::Read(unsigned char&)
{
}

void File::Read(unsigned short&)
{
}

void File::Read(unsigned int&)
{
}

void File::Read(unsigned long&)
{
}

void File::Read(char&)
{
}

void File::Read(short&)
{
}

void File::Read(int&)
{
}

void File::Read(long&)
{
}

void File::Read(float&)
{
}

void File::Read(double&)
{
}

void File::Read(Rect& )
{
}

void File::Write(node* pn)
{
}

void File::Read(node*& pn)
{
}

node* File::CreateObject(char* name)
{
	return nullptr;
}

String::String(const char* name)
{
	pc = _strdup(name);
}

String::String(const String& str)
{
	pc = str.pc;
}

String::~String()
{
}

String::operator const char* () const
{
	const char* pcc = pc;
	return pcc;
}

int String::length() const
{
	return strlen(pc);
}

bool String::empty() const
{
	return(strlen(pc) != 0);
}

void String::erase()
{
	delete pc;
	pc = 0;
}

void String::assign(const char* pcc, int i)
{

}

String& String::operator=(const String&)
{
	// TODO: insert return statement here
	return *this;
}

String& String::operator+=(const String&)
{
	// TODO: insert return statement here
	return *this;
}

void String::Load(File& f)
{

}

void String::Save(File& f)
{

}

String operator+(const String& f, const String& l)
{
	return String(f) += l;
}

int operator==(const String& f, const String& l)
{
	return 0;
}

int operator!=(const String& f, const String& l)
{
	return 0;
}

int operator==(const String& f, const char* cc)
{
	return 0;
}

int operator==(const char* cc, const String& f)
{
	return 0;
}

int operator!=(const String& f , const char* cc)
{
	return 0;
}

int operator!=(const char* cc , const String& f)
{
	return 0;
}

UString::UString(const UString& us)
{
	pwc = us.pwc;
}



UString::UString(const char* pcc)
{
	// convert pcc from const char * to wchar_t *
	pwc = new wchar_t();
}

UString::~UString()
{
	delete pwc;
}

UString::operator wchar_t * ()
{
	return pwc;
}

UString& UString::operator=(const UString& cus)
{
	pwc = cus.pwc;
	return *this;
}

CREATE::CREATE(char* c , node* (*pCn)())
{
	name = String(c);
	pCreateObject = pCn;
}
