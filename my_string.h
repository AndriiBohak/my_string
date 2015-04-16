#ifndef MY_STRING
#define MY_STRING

char* my_modify(char * str);
void* my_cout(char *str);


size_t my_strlen  ( const char * str );
char * my_strcat  ( char * destination, const char * source );
char * my_strncat ( char * destination, const char * source, size_t num );
char * my_strcpy  ( char * destination, const char * source );
int    my_strcmp  ( const char * str1,  const char * str2 ); 
char * my_strchr  ( char * str, int character );
void * my_memcpy  ( void * destination, const void* source, size_t size);
void * my_memmove (void* destination, const void* source, size_t size);
char * my_strncpy (char* destination, const char* source, size_t size);
int    my_memcmp  (const void* ptr1, const void* ptr2, size_t size);
int    my_strncmp (const char* pointer1, const char* pointer2, size_t size);
void * my_memchr  (void* pointer, int value, size_t num);
size_t my_strcspn (const char* source, const char* keys);
char * my_strpbrk(char* source, const char* keys);
char * my_strrchr(char* source, int value);
size_t my_strspn (const char* source, const char* keys);
char * my_strstr (char* source, const char* searching);
char * my_strtok (char* buffer, const char* delims);
void * my_memset (void* pointer1, int value, size_t size);




#endif // !MY_STRING