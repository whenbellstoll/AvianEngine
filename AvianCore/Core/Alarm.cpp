#include "Alarm.h"
#include "Node.h"
#include "CollisionData.h"

void Alarm::ShowAlarmCollision(Map*)
{

}

Alarm::Alarm()
{
}

Alarm::Alarm(Alarm* alarmPrime)
{
}

Alarm::Alarm(const Alarm& alarmAddress)
{
}

Alarm& Alarm::operator=(const Alarm& alarmAddress)
{
	// TODO: insert return statement here
}

Alarm::~Alarm()
{
}

node* Alarm::Clone()
{
	return nullptr;
}

Alarm* Alarm::Search(const char* alarmName)
{
	return nullptr;
}

Alarm* Alarm::Search(const char*, const char*)
{
	return nullptr;
}

int Alarm::Id()
{
	return id;
}

void Alarm::Id(int i)
{
	id = i;
}

const char* Alarm::Name()
{
	return Name;
}

void Alarm::Name(const char* n)
{
	Name = n;
}

bool Alarm::Active()
{
	return active;
}

void Alarm::Active(bool b)
{
	active = b;
}

void Alarm::AddCollisionData(CollisionSegment)
{
}

void Alarm::AddCollisionData(CollisionCircle)
{
}

void Alarm::ExecuteOnce(bool b)
{
	executeOnce = b;
}

bool Alarm::ExecuteOnce()
{
	return (bool)executeOnce;
}

void Alarm::ShowCollision(bool b)
{
	showCollision = b;
}

bool Alarm::ShowCollision()
{
	return showCollision;
}

void Alarm::AddLocalVariable(unsigned int ui)
{
}

void Alarm::Save(File& file)
{
}

void Alarm::Load(File& file)
{
}

AlarmPTR::AlarmPTR()
{
}

AlarmPTR::AlarmPTR(Alarm*)
{
}

AlarmPTR::AlarmPTR(const char*)
{
}

Alarm* AlarmPTR::operator->()
{
	return nullptr;
}

Alarm& AlarmPTR::operator*()
{
	// TODO: insert return statement here
}

AlarmPTR& AlarmPTR::operator=(Alarm*)
{
	// TODO: insert return statement here
}

AlarmPTR::operator Alarm* ()
{
}
