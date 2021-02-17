#ifndef _STATEMACHINE_H_
#define _STATEMACHINE_H_

typedef bool (*F_B_PV)(void *);
typedef void (*F_V_I_PV)(int, void *);
typedef void (*F_V_PV)(void *);

enum TimerMode
{
	TM_Once, TM_Infinite
};

enum TimerUnit
{
	TU_GameLoops, TU_Milliseconds
};


class FUNCORE_API Timer
{
	bool             m_Run;
	unsigned int     m_Unit;
    unsigned int     m_CountDown;
	unsigned int     m_Duration;
	TimerMode        m_Mode;
	F_V_PV           m_f;
	
public:

	Timer(F_V_PV f = NULL, unsigned int delay = 0, TimerUnit unit = TU_GameLoops, bool run = true, TimerMode mode = TM_Infinite);
	void Init(); 
	void Reset(unsigned int delay, TimerMode mode = TM_Infinite);
	void SetMode(TimerMode mode);
	TimerMode GetMode();
	void Tick(void * Owner);
	void Start();
	void Stop();
	bool IsRunning();
	unsigned int TimeRemaining();
	void Save(File &);
	void Load(File &); 
};

class FUNCORE_API Edge
{
	int           m_To;
	int           m_Flag;
	int           m_ToStation;//reserved for condition from station to intermediate
	F_B_PV        m_CondAct;
	bool          m_DefaultCond;
	friend class  StateMachineTraverser;
	bool          m_WayBack;
	unsigned char m_Key;
	unsigned int  m_Radius;
	friend class PathStateMachineTraverser;
public:
	Edge(int to, F_B_PV condact, bool defaultcond);
	Edge(int to, F_B_PV condact, bool defaultcond,bool WayBack, unsigned char Key,unsigned int Radius, int ToStation, int flag);
	//Edge(int flag = 0);
	int To();
};

class StateMachine;
class FUNCORE_API State
{
	std::vector<Edge>   m_Edges;
	F_V_I_PV       m_StateFunction; 
	StateMachine * m_StateMachine;
	friend class   StateMachineTraverser;
	friend class   PathStateMachineTraverser;
	unsigned int   m_Smo;
	unsigned char  m_Key;
	bool           m_Plat;
	int            m_Flag;
	int            m_ToStation;//reserved for intermediate action fct
public:
	State(F_V_I_PV statefunction = NULL, StateMachine * sm = NULL);
	State(F_V_I_PV statefunction, unsigned int smo, unsigned char key, int tostation, bool plat, int flag);
	void AddEdge(const Edge &);
	std::vector<Edge> & Edges();
};

class FUNCORE_API StateMachine
{
protected:
	std::vector<State> m_States;
	int           m_StartingState;
	friend class  StateMachineTraverser;
	friend class  PathStateMachineTraverser;
public:
	StateMachine();
	void AddState(const State & s);
	bool SetStartingState(int s);
	int GetStartingState()const;
	int GetNumberOfStates();
	std::vector<State> & States();
};

class FUNCORE_API StateMachineTraverser : public node
{
protected:

	StateMachine          *  m_StateMachine;
	int                      m_CurrentState;
	int                      m_FirstVisit;
	StateMachineTraverser *  m_SMT;
	bool                     m_CurrentStateChanged; 
    
public:

	void * operator new (size_t);
	void operator delete(void *);
	
	StateMachineTraverser(StateMachine * sm = 0);
    StateMachineTraverser(const StateMachineTraverser & smt);
	virtual ~StateMachineTraverser();
	StateMachineTraverser & operator = (const StateMachineTraverser & smt);
	
	virtual void SetCurrentState(int i);
	int  GetCurrentState();
	virtual void Go(void *);
	
	void Save(File &);
	void Load(File &);
	DYNCREATED
};


struct FUNCORE_API Position
{
	float worldPositionX;
	float worldPositionY;
	Position(float x = -1.0f, float y = -1.0f)
	{
		worldPositionX = x;
		worldPositionY = y;
	}
};

template <class T>
class SquareMatrix
{
	typedef std::vector<T> onedim;
	typedef std::vector<onedim> towdim;
    towdim matrix; 
public:
	SquareMatrix(int size = 0)
	{
        for(int i = 0; i < size; i++)
		{
			onedim v;
			v.resize(size, T());
			matrix.push_back(v); 
		}
	}
	void Init(int size)
	{
		matrix.clear();
		for(int i = 0; i < size; i++)
		{
			onedim v;
			v.resize(size, T());
			matrix.push_back(v); 
		}
	}
    int Dimension()
	{
        return matrix.size(); 		
	}
	std::vector<T> & operator[] (int index)
	{
		return matrix[index];
	}
};

class Sprite;
class PathStateMachineTraverser;
class FUNCORE_API PathStateMachine: public StateMachine
{
	SquareMatrix <int>   ShortestDistanceArray;
	SquareMatrix <int>   ShortestPathNodesArray;
	friend PathStateMachineTraverser;
	
public:
	SquareMatrix <float>            WeightList;
	std::vector<Position>           PositionList;
	std::vector<CollisionSegment *> collisionList;
	int numberOfStations;
	PathStateMachine(int ns = 0);
	PathStateMachine(const PathStateMachine &);
	PathStateMachine & operator = (const PathStateMachine &);
	~PathStateMachine();
	float Distance(int s1, int s2);
	void AddStation(const Position & pos);
	Position GetStation(int index);
	void ComputeShortestPath();
	void AddCollisionData(CollisionSegment &);
	void DisplayPath(COLORREF,Sprite *);
};

class FUNCORE_API PathStateMachineTraverser: public StateMachineTraverser
{
	bool shortestPath;
	int  currentNode;
	std::vector<int>  SPath;
		
	void SetShortestPathNodes(unsigned int n1, unsigned int n2);
	void ArrangeNodes(unsigned int n1, unsigned int n2);

public:
	PathStateMachine * psm;
	bool enablePath;
	std::vector<bool> PathVertexes;

	void * operator new (size_t);
	void operator delete(void *);
	PathStateMachineTraverser(PathStateMachine * psm = 0);

	bool ShortPath();
	void StationAction();
	bool IntermediateCondition();
	void StopShortestPath();
	bool EndOfShortestPath();
	void ShortestPath(unsigned int st);
	int NearestStationNumber(void *);
	void Go(void *);

	void Save(File &);
	void Load(File &);
	DYNCREATED
};


#endif