#include "Behavior.h"

Bnode::Bnode()
{
	Index = 0;
	Active = true;
	type = -1;
}

Bnode::Bnode(const Bnode&)
{
}

Bnode& Bnode::operator=(const Bnode&)
{
	// TODO: insert return statement here
}

void Bnode::Save(File&)
{
}

void Bnode::Load(File&)
{
}

Behavior::Behavior()
{
}

Behavior& Behavior::operator=(const Behavior&)
{
	// TODO: insert return statement here
}

void Behavior::AddStateMachine(unsigned int, bool)
{
}

void Behavior::AddFunction(unsigned int, bool)
{
}

void Behavior::AddTimer(unsigned int, bool)
{
}

bool Behavior::IsStateMachineAdded(unsigned int)
{
	// To do after semester
	return false;
}

bool Behavior::IsFunctionAdded(unsigned int)
{
	return false;
}

bool Behavior::IsTimerAdded(unsigned int)
{
	return false;
}

void Behavior::StateMachineActiveStatus(unsigned int, bool)
{
	 // To do after semester
}

void Behavior::FunctionActiveStatus(unsigned int, bool)
{
}

void Behavior::TimerActiveStatus(unsigned int, bool)
{
}

bool Behavior::StateMachineActiveStatus(unsigned int)
{
	return false;
}

bool Behavior::FunctionActiveStatus(unsigned int)
{
	return false;
}

bool Behavior::TimerActiveStatus(unsigned int)
{
	return false;
}

void Behavior::ChangeState(unsigned int, unsigned int)
{
}

int Behavior::GetCurrentState(unsigned int)
{
	return 0;
}

void Behavior::Clear()
{
}

unsigned int Behavior::Count()
{
	return 0;
}

void Behavior::ResetTimer(unsigned int i, unsigned int delay, TimerMode mode)
{
}

unsigned int Behavior::TimeRemaining(unsigned int)
{
	return 0;
}

void Behavior::Update(void*)
{
}

void Behavior::Save(File&)
{
}

void Behavior::Load(File&)
{
}
