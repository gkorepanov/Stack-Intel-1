#ifndef S_ALERTS
#define S_ALERTS

#define USERERR(...)\
{\
    fprintf(stderr, __VA_ARGS__);\
    fflush(stderr);\
    exit(0);\
}
 

#define FATALERR(...)\
{\
    fprintf(stderr, "FATAL ERROR: " __VA_ARGS__);\
    fprintf(stderr, "\nFile: %s\nLine: %d\nFunction: %s\n", __FILE__, __LINE__, __PRETTY_FUNCTION__);\
    fflush(stderr);\
    exit(1);\
}

#define DBGPRINT(...)\
{\
    if(DEBUGMODE) {\
        printf(__VA_ARGS__);\
    }\
}


/*printf("Function: %s |     ", __PRETTY_FUNCTION__);*/
#endif
