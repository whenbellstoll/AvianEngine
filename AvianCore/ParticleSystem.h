#ifndef _PARTICLESYSTEM_H_
#define _PARTICLESYSTEM_H_

class FUNCORE_API Particle
{
	ParticleSystem * m_ps;
	float         m_x0;
	float         m_y0; 
	float         m_x;
	float		  m_y;
	float         m_px;
	float         m_py;
	float         m_tx;
	float         m_ty;
	float         m_ux;
	float         m_uy;
	float         m_vx;
	float		  m_vy;
	float         m_angle;
	float         m_cosa;
	float         m_sina;
	float         m_velocity;
	float         m_v2;
	float         m_t;
	float         m_friction;
	unsigned int  m_size;
	unsigned int  m_maxage;
	unsigned int  m_age;
	unsigned int  m_delaytoborn;
	COLORREF      m_color;
	COLORREF      m_dc; 
	float         m_cr;
	float         m_cg;
	float         m_cb; 
	float         m_ar;
	float         m_ag;
	float         m_ab;
	bool          m_visible;
	FRECT         m_bb;
	void          CollisionWithMap(Map *,float);
	float         VelocityT(float);
	float         Txy(float,float);  
	bool          m_collwithmap;
	bool          m_reflection;
	bool          m_checkcoll;

	
public:
	friend class ParticleSystem;
	float var1,var2,var3,var4,var5;
	Particle();
	void         Angle(float);
	float        Angle();
	void         Velocity(float);
	float        Velocity();
	void         Visible(bool);
	bool         Visible();
	void         Friction(float);
	float        Friction();
	void         CheckCollisionWithMap(bool);
	bool         CheckCollisionWithMap();
	bool         CollisionWithMap();
	void         Reflection(bool);
	bool         Reflection();
	void         PositionX(float);
	float        PositionX();
	void         PositionY(float);
	float        PositionY();
	void         Position(float,float);
	void         MaximumAge(unsigned int);
	unsigned int MaximumAge();
	unsigned int Age();
	void         BirthDelay(unsigned int);
	unsigned int BirthDelay();
	bool         Dead();
	void         Color(COLORREF,COLORREF);
	COLORREF     Color();
	void         Size(unsigned int);
	unsigned int Size();
	ParticleSystem * Owner();
};


class FUNCORE_API ParticleSystem:public node
{
	std::vector<Particle> m_particles;
	String       name;
	Map *        mapPtr;
	float        m_x;
	float        m_y;
	float        m_gravity;
	bool         m_alive;
	bool         m_unused;
	unsigned int m_nparticles;
	int          m_init;
	int          m_update;
	void (*m_pInit)(Particle *);
	void (*m_pUpdate)(Particle *);
	void Init();
	void Display();
	friend class GameNode;
	friend class Particle;
	bool          pauseParticleSystem;
		
public:
						   ParticleSystem(unsigned int n = 0 ,int init = -1 ,int update = -1);
	node*				   Clone();
	static ParticleSystem* Search(const char *);
	const char *           Name();
	void                   Name(const char *);
	void                   Gravity(float);
	float                  Gravity();
	void                   Pause(bool);
	bool                   Pause();
	void                   WorldPositionX(float);
	void                   WorldPositionY(float);
	float                  WorldPositionX();
	float                  WorldPositionY();
	void                   WorldPosition(float,float); 
	float                  MapPositionX();
	float                  MapPositionY();
	void                   MapPositionX(float);
	void                   MapPositionY(float);
	void                   MapPosition(float,float);
	void                   WorldPositionXInc(float,float);
	void                   WorldPositionXDec(float,float);
	void                   WorldPositionYInc(float,float);
	void                   WorldPositionYDec(float,float);
	void                   MapPositionXInc(float,float);
	void                   MapPositionXDec(float,float);
	void                   MapPositionYInc(float,float);
	void                   MapPositionYDec(float,float);
	ParticleSystem *       CreateParticleSystem();
	void                   Unused(bool);
	bool                   Unused();
	void                   Use(const char *);
	bool                   Alive(); 
	void                   BelongToMap(const char *);
	const char *           BelongToMap();
	void                   Update();

	void * operator new(size_t);
	void   operator delete(void *);

	void                   Save(File &);
	void                   Load(File &);

	DYNCREATED
};

class FUNCORE_API ParticleSystemPTR
{
	ParticleSystem *particleSystemPTR;
	static ParticleSystem * dummyParticleSystemPTR;
public:
	ParticleSystemPTR(); 
	ParticleSystemPTR(ParticleSystem *);
	ParticleSystemPTR(const char *);
	ParticleSystem * operator->();
	ParticleSystem & operator*();
	ParticleSystemPTR & operator=(ParticleSystem *);
	operator ParticleSystem *();
};


#endif