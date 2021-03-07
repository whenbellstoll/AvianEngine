#ifndef _RANDOMNUMBERS_H_
#define _RANDOMNUMBERS_H_

#define NTAB               32

class Random:public node
{
	int iy;
	int idum;
	int iv[NTAB];
	float Get();
public:
	Random();
	float GetFloat(float n);              
	unsigned int Get(unsigned int n);
	void Reset(unsigned int n);   
	
	void Save(File &);
	void Load(File &);

	DYNCREATED
};

extern Random fRandom;
extern Random iRandom;

  float RandFlt(float);
  unsigned int RandInt(unsigned int);
  void RandReset(unsigned int);



#endif





