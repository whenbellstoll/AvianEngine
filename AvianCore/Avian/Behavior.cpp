#include "Behavior.h"

Bnode::Bnode()
{
	Index = 0;
	Active = true;
	type = -1;
	f = 0;
}

Bnode::Bnode(const Bnode& bn)
{
	Index = bn.Index;
	Active = bn.Active;
	type = bn.type;
	f = bn.f;
}

Bnode& Bnode::operator=(const Bnode& bn)
{
	Index = bn.Index;
	Active = bn.Active;
	type = bn.type;
	f = bn.f;
	return *this;
}

void Bnode::Save(File& f)
{
}

void Bnode::Load(File& f)
{
}

Behavior::Behavior()
{
	IsRunning = true;
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
	// Timer function, to do
	return false;
}

void Behavior::ChangeState(unsigned int, unsigned int)
{
	// State Machine function, to do
}

int Behavior::GetCurrentState(unsigned int)
{
	// State Machine Function, to do
	return 0;
}

void Behavior::Clear()
{
	Bnodes.clear();
	FunctionsIndexes.clear();
	StateMachinesIndexes.clear();
	TimersIndexes.clear();
}

unsigned int Behavior::Count()
{
	return 0;
}

// Not implementing the timer yet
//void Behavior::ResetTimer(unsigned int i, unsigned int delay, TimerMode mode)
//{
//}

//unsigned int Behavior::TimeRemaining(unsigned int)
//{
	//return 0;
//}

void Behavior::Update(void* f)
{
}

void Behavior::Save(File&)
{
}

void Behavior::Load(File&)
{
}

const char* Behavior::ClassName()
{
	return "Behavior";
}

const char* Bnode::ClassName()
{
	return "Bnode";
}
