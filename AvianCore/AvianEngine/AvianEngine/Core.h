#ifndef _FUNCORE_H_
#define _FUNCORE_H_

#ifdef FUNCORE
	#ifdef FUNCORE_EXPORTS
		#define   __declspec(dllexport)
	#else
		#define   __declspec(dllimport)
	#endif
#else 
	#define  
#endif

#endif
