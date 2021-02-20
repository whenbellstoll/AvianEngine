#ifndef _ALARM_H_
#define _ALARM_H_

class Alarm: public node
{
protected:
	int		id;			
	String name;
	bool	active;
	int executeOnce;
	bool showCollision;
	void ShowAlarmCollision(Map *);

	friend class Sprite;
	friend void GameLoopBody();
	int li;
public:
	Alarm();
	Alarm(Alarm *);
	Alarm(const Alarm &);
	Alarm & operator=(const Alarm &);
	~Alarm();

	List	collisionList; 
	node* Clone();
	static Alarm* Search(const char *);

	//Definition:	Search for the Alarm by its name in the owner sprites alarm lists.
	static Alarm* Search(const char *,const char *);
	int Id();
	void Id(int);
	const char *Name();
	void Name(const char *);
	bool Active();
	void Active(bool b);
	void AddCollisionData(CollisionSegment);
	void AddCollisionData(CollisionCircle);

	void ExecuteOnce(bool);
	bool ExecuteOnce();
	void ShowCollision(bool);
	bool ShowCollision();	
	void AddLocalVariable(unsigned int);

	Sprite *SpriteAddress;

	void Save(File &);
	void Load(File &);

	Behavior behavior;

	DYNCREATED
};


class   AlarmPTR
{
	Alarm *alarmPtr;
	static Alarm * dummyAlarmPtr;
public:
	AlarmPTR(); 
	AlarmPTR(Alarm *);
	AlarmPTR(const char *);
	Alarm * operator->();
	Alarm & operator*();
	AlarmPTR & operator=(Alarm *);
	operator Alarm *();
	
};


#endif

