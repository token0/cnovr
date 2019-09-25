#ifndef _CNOVRTCC_H
#define _CNOVRTCC_H

#ifdef TCCINSTANCE


//You should implement these
void init( const char * id );	//called only once
void start( const char * id );	//called on start and after reload
void stop( const char * id );	//called on reload and stop

//These are provided.
int printf( const char * format, ... );

//from os_generic
typedef void* og_thread_t;
typedef void* og_mutex_t;
typedef void* og_sema_t;
typedef void* og_tls_t;


void OGSleep( int is );
void OGUSleep( int ius );
double OGGetAbsoluteTime();
double OGGetFileTime( const char * file );
og_thread_t OGCreateThread( void * (routine)( void * ), void * parameter );
void * OGJoinThread( og_thread_t ot );
void OGCancelThread( og_thread_t ot );
og_mutex_t OGCreateMutex();
void OGLockMutex( og_mutex_t om );
void OGUnlockMutex( og_mutex_t om );
void OGDeleteMutex( og_mutex_t om );
og_sema_t OGCreateSema();
int OGGetSema( og_sema_t os );
void OGLockSema( og_sema_t os );
void OGUnlockSema( og_sema_t os );
void OGDeleteSema( og_sema_t os );
og_tls_t OGCreateTLS();
void OGDeleteTLS( og_tls_t key );
void * OGGetTLS( og_tls_t key );
void OGSetTLS( og_tls_t key, void * data );



#else

#include <stdint.h>

struct TCCState;
typedef struct TCCState TCCState;
typedef void (*tcccbfn)( const char * id );

typedef struct TCCInstance_t
{
	tcccbfn init;
	tcccbfn start;
	tcccbfn stop;
	TCCState * state;
	char * tccfilename;
	void * image;
	char * identifier;
	char ** additionalfiles; //sb_buffer.
	uint8_t bActive;
	uint8_t bDynamicGen;
	uint8_t bFirst;
	uint8_t bDontCompile;
} TCCInstance;



void CNOVRTCCLog( void * data, const char * tolog );
void CNOVRStartTCCSystem( const char * systemname );

#endif

#endif
