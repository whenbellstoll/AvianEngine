#include "../globals.h"

Bnode::Bnode()
{
	Index = 0;
	Active = false;
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
	Clear();
}

Behavior& Behavior::operator=(const Behavior& b)
{
	IsRunning = b.IsRunning;
	Bnodes = b.Bnodes;
	FunctionsIndexes = b.FunctionsIndexes;
	StateMachinesIndexes = b.StateMachinesIndexes;
	TimersIndexes = b.TimersIndexes;

	return *this;
}

void Behavior::AddStateMachine(unsigned int, bool)
{
}

void Behavior::AddFunction(unsigned int i, bool b)
{
	if (i > maxFIndex)
	{
		return;
	}
	Bnode n;
	n.Index = i;
	n.Active = b;
	n.type = 0;
	// this casts our function to "void FunctionSignature(void* arg)"
	n.f = (void(*)(void*))FArray[i];
	Bnodes.push_back(n);
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

void Behavior::Update(void* obj)
{
	if (Bnodes.empty()) return;

	for (std::vector<Bnode>::iterator it = Bnodes.begin(); it != Bnodes.end(); ++it )
	{
		// we are passing in our parent object to the function
		if(it->Active && IsRunning) (*it->f)(obj);
	}
}

void Behavior::Save(File&)
{
}

void Behavior::Load(File&)
{
}

DYNCREATEIMP(Behavior);
DYNCREATEIMP(Bnode);
