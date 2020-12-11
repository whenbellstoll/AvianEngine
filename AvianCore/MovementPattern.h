#ifndef _MOVEMENTPATTERN_H_
#define _MOVEMENTPATTERN_H_

class FUNCORE_API MovementPattern:public node
{
	struct PatternVector{
		float PunitX;
		float PunitY;
		float Pmagnitude;		
	};
	PatternVector *PVectorPath;

	int id;
	int numberOfVectors;
	String name;
	node * Clone();

	void Id(int);
	void UpdateMovementPattern(Sprite *);
public:
	Behavior behavior;
	MovementPattern();
	~MovementPattern();
	MovementPattern(MovementPattern *);
	MovementPattern(const MovementPattern &);
	MovementPattern & operator=(const MovementPattern &);
	void Name(const char *);
	const char * Name();

	void NumberOfVectors(unsigned int);
	unsigned int NumberOfVectors();
	void CalculateVectorPattern(int,int,int);

	friend class GameNode;
	friend class Sprite;
};


#endif