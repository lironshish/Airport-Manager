#pragma once

#define CHECK_RETURN_0(p) if(!p) return 0;
		
#define CHECK_RETURN_NULL(p)if(!p) return NULL;
				
#define CHECK_MSG_RETURN_0(p,s) if(!p) {\
								printf(#s"\n");\
								return 0;\
								}\
						
#define CHECK_0_MSG_CLOSE_FILE(x,f,s) if(x==0) return MSG_CLOSE_RETURN_0(f,s);
															    
#define CHECK_NULL_MSG_COLSE_FILE(x,f,s) if(x==NULL) return MSG_CLOSE_RETURN_0(f,s);
					
#define MSG_CLOSE_RETURN_0(f,s) printf(#s"\n");\
								fclose(f);\
								return 0;\
						
