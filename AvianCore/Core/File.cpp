#include "File.h"

File::File(const char* name, Mode m)
{
}

File::~File()
{
}

long File::Size()
{
	return 0;
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

void File::Write(RECT)
{
}

void File::Write(FunRect)
{
}

void File::Write(FRECT)
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

void File::Read(RECT&)
{
}

void File::Read(FunRect&)
{
}

void File::Read(FRECT&)
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

String::String(const char*)
{
}

String::String(const String&)
{
}

String::~String()
{
}

String::operator const char* () const
{
	return static_cast<const char*>(*pc)
}

int String::length() const
{
	return strlen(pc);
}

bool String::empty() const
{
	return false;
}

void String::erase()
{

}

void String::assign(const char*, int)
{

}

String& String::operator=(const String&)
{
	// TODO: insert return statement here
}

String& String::operator+=(const String&)
{
	// TODO: insert return statement here
}

void String::Load(File&)
{

}

void String::Save(File&)
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

UString::UString(const UString&);
{
}



UString::UString(const char*)
{
}

UString::~UString()
{
}

UString::operator WCHAR* ()
{
}

UString& UString::operator=(const UString&)
{
	// TODO: insert return statement here
}

CREATE::CREATE(char*, node* (*)())
{
}
