#ifndef _FUNCORE_H_
#define _FUNCORE_H_

#ifdef FUNCORE
	#ifdef FUNCORE_EXPORTS
		#define FUNCORE_API __declspec(dllexport)
	#else
		#define FUNCORE_API __declspec(dllimport)
	#endif
#else 
	#define FUNCORE_API
#endif

#endif
