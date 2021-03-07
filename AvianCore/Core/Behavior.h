#ifndef _BEHAVIOR_H_
#define _BEHAVIOR_H_
#include "Node.h"
class Bnode : public node
{
public:
	int          Index       ;
	bool         Active      ;
	int          type        ; //-1 = nothing, 0 = function, 1 = statemachine, 2 = timer;
	void         (*f)(void *);
	StateMachineTraverser * smt;
	Timer tm; 

	Bnode();
	Bnode(const Bnode &);
	Bnode & operator = (const Bnode &);
	
	void Save(File &);
	void Load(File &);
	
	DYNCREATED
};

class Behavior:public node
{
	std::vector<Bnode> Bnodes;
	std::vector<int> FunctionsIndexes;
	std::vector<int> StateMachinesIndexes;
	std::vector<int> TimersIndexes;
	bool IsRunning;

public:
	
    Behavior();
	Behavior & operator=(const Behavior &);
	void AddStateMachine(unsigned int,bool = true);
	void AddFunction(unsigned int,bool = true);
	void AddTimer(unsigned int,bool = true);
	
	bool IsStateMachineAdded(unsigned int);
	bool IsFunctionAdded(unsigned int);
	bool IsTimerAdded(unsigned int);
	
	void StateMachineActiveStatus(unsigned int,bool);
	void FunctionActiveStatus(unsigned int,bool);
	void TimerActiveStatus(unsigned int,bool);

	bool StateMachineActiveStatus(unsigned int);
	bool FunctionActiveStatus(unsigned int);
	bool TimerActiveStatus(unsigned int);

	void ChangeState(unsigned int,unsigned int);
	int  GetCurrentState(unsigned int);
	void Clear();
	unsigned int Count();

	void ResetTimer(unsigned int i, unsigned int delay, TimerMode mode = TM_Infinite);
	unsigned int TimeRemaining(unsigned int);
	
	void Update(void *);

	void Save(File &);
	void Load(File &);

	DYNCREATED
};

#endif