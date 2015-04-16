#include"my_string.h"
#include<iostream>

#define END '^'

void* my_cout(char *str){
	while (*str != END)
	{
		std::cout<<*str;
		str++;
	}
	return 0;
}


char* my_modife(char * str)
{
	if (str == NULL)
		return 0;

	char* begin = str;

	while (*++str);
	*str = END;

	return begin;
}

/* function returns the length of the C string str.

*param  str to string ended with my terminal symbol
*return the length of string

*/

size_t my_strlen( const char * str )
{
	size_t lenght=0;

	while (*str++ != END)
		lenght++;

	return lenght;
}

/*function to add source string to the end of first string

param  destination pointer to destination char array
param  source      constant pointer to source char array
return pointer to destination array

*/

char * my_strcat ( char* destination, const char* source )
{
	if (destination == NULL)
		return NULL;

	if (source == NULL)
		return destination;

	char* begin = destination;

	destination += my_strlen(destination);

	while (*source != '\0')
		*destination++ = *source++;

	*destination = END;

	return begin;
}

/*function to add source string to the end of first string

param  destination pointer to destination char array
param  source      constant pointer to source char array
param  num         amount of bytes to copied
return pointer to destination array

*/

char * my_strncat ( char * destination, const char * source, size_t num )
{

	if (destination == NULL)
		return NULL;

	if (source == NULL || num == 0)
		return destination;

	char * begin = destination;

	while (*destination!=END)
		destination++;


	for (size_t i  = 1; i <= num; i++){
		*destination=*source;
		destination++;
		source++;
	}

	*destination=END;

	return begin;

}

/* function to copy one char array ended with terminal
symbol to another

param  destination pointer to destination char array
param  source      constant pointer to source char array
return pointer to destination array

*/

char * my_strcpy( char * destination, const char * source )
{

	char* begin =destination;

	while(*source!=END){
		*destination=*source;

		destination++;
		source++;
	}
	*destination=END;
	return begin;
}

/*function to compare two char arrays ended with terminal symbol

param  str1 pointer to first char array
param  str2 pointer to second char array
return  -1 first smaller then second
return   1 second smaller then first
return   0 equal

*/

int my_strcmp(const char* str1, const char* str2 )
{
	while( *str1 ||*str2)
	{
		int counter=*str1-*str2;

		if  (counter==0 && *str1==END && *str2==END)
			return 0;

		else if(counter < 0   ||  *str1 == END)
			return -1;


		else if (counter >  0 || *str2 == END)
			return 1;

		str1++;
		str2++;

	}
	return 0;

}

/* return a pointer to the first occurrence of
character int the string

param str string ended with terminal symbol
param character character to be located
return a pointer to first occurrence of character in str

*/

char * my_strchr( char * str, int character )
{

	if(str == NULL||character==NULL){
		return NULL;
	}
	while (*str!=END)
	{

		if(*str==(unsigned char)character){
			return str;
			str++;
		}
	}
	return 0;
}

/*function to copy some amount of bytes from source address to
destination

param destination address from where copy
param source address where copy
param size amount of bytes to copy
return pointer to destination

*/

void * my_memcpy (void* destination, const void* source, size_t size)
{
	if (destination == NULL)
		return NULL;

	if (source == NULL)
		return destination;

	unsigned char* dest = (unsigned char*)destination;
	const unsigned char* sour = (const unsigned char*)source;

	for (size_t i = 0; i < size; i++)
	{
		*(dest+i)=*(sour+i);
	
	}
	return destination;
}

/* function to move bytes from source address to destination

param destination address from where copy
param source address where copy
param size amount of bytes to copy
return pointer to destination

*/

void * my_memmove (void* destination, const void* source, size_t size)
{
	unsigned char* dest = (unsigned char*)destination;
	const unsigned char* sour = (const unsigned char*)source;

	while (size--)
	{
		*--dest = *--sour;
	}
	return dest;
}


/* function to copy size bytes from one char array ended with
terminal symbol to another

param  destination pointer to destination char array
param  source      constant pointer to source char array
param  size        amount of bytes copied
return pointer to destination array

*/

char * my_strncpy (char* destination, const char* source, size_t size)
{
	if (destination == NULL)
		return NULL;
	if (source == NULL || size == 0)
		return destination;

	char* begin = destination;

	while (size-- && *source != END)
		*++destination = *++source;
	return begin;
}

/*compare the first number of bytes

param  ponter1 pointer to block of memory
param  ponter2 pointer to block of memory
param  num     numbers of byte to compare
return  <0 first smaller then second
return  >0 second smaller then first
return   0 equal

*/

int my_memcmp (const void* ptr1, const void* ptr2, size_t size)
{
	unsigned char* pointer1 = (unsigned char*)ptr1;
	unsigned char* pointer2 = (unsigned char*)ptr2;
	while (size--)
	{
		if (*pointer1 - *pointer2 != 0)
			return (*pointer1 - *pointer2);
		else
		{
			pointer1++;
			pointer2++;
		}
	}
	return 0;
}

/* compare first num chars in char arrays ended with
terminal symbol

param  string1 pointer to first char array
param  string2 pointer to second char array
param  num amount of chars to compare
return  <0 first smaller then second
return  >0 second smaller then first
return   0 equal

*/

int my_strncmp(const char* pointer1, const char* pointer2, size_t size)
{
	while (size-- && *pointer1 != END)
	{
		if (*pointer1 != *pointer2)
			return (*pointer1 - *pointer2) < 0 ? -1 : 1;
		++pointer1;
		pointer2++;
	}
	return 0;
}

/*search first occurrence of value in memory block pointed by ptr

param ptr pointer to the block of memory where the search performed
param value Value to be located
param num  number of bytes to be analyzed
return a pointer to first occurrence of value in the block of memory

*/

void * my_memchr (void* pointer, int value, size_t num)
{
	unsigned char* position = (unsigned char*)pointer;
	while (num--)
		if (*position++ == (unsigned char)value)
			return position;
	return NULL;
}


/*brief get span until character in string

param str1 string to be scanned.
param str2 string containing the characters to match.
return the length of the initial part of str1 not containing
any of the characters that are part of str2.

*/
size_t my_strcspn (const char* source, const char* keys)
{
	size_t num = 1;
	const char* key;
	while ( source != "^")
	{
		key = keys;
		while (*key != END)
		{
			if (*source == *key)
				return num;
			key++;
		}
		num++;
		source++;
	}
	return num;
}

/* Scans str1 for the first occurrence of any of the characters
that are part of str2, returning the number of characters of
str1 read before this first occurrence.

param  source string to be scanned
param  keys const string containing the characters to match.
return the length of the initial part of source not containing any
characters that are part of keys

*/

char * my_strpbrk(char* source, const char* keys)
{
	while (*source != END)
	{
		if (strchr(source, *keys++))
			return (char*)--keys;
	}
	return NULL;
}

/*brief returns a pointer to the last occurrence of character in the
string str

param str string ended with terminal symbol
param character symbol to be located
return a pointer to the last occurrence of character in str

*/

char * my_strrchr(char* source, int value)
{
	char* ret = NULL;
	while (*source != END)
	{
		if (*source++ == char(value))
			ret = source;
	}
	return ret;
}


/*Returns the length of the initial portion of str1 which consists
only of characters that are part of str2.

param str1 string to be scanned
param str2 string containing the characters to match
return The length of the initial portion of str1 containing only
characters that appear in str2.

*/

size_t my_strspn (const char* source, const char* keys)
{
	size_t amount = 0;
	while (*source != END && strchr((char*)keys, *source++))
		amount++;
	return amount;
}

/* Returns a pointer to the first occurrence of str2 in str1,
or a null pointer if str2 is not part of str1.

param str1 string to be scanned
param str2 string containing the sequence of characters to match
return a pointer to the first occurrence in str1 of the entire
sequence of characters specified in str2

*/

char * my_strstr (char* source, const char* searching)
{
	size_t lenght = strlen(searching);
	while (*source != END)
	{
		if (!memcmp((const void*)source++, (const void*)searching, lenght))
			return source--;
	}
	return NULL;
}

/*brief A sequence of calls to this function split str into tokens

param string to truncate
param string containing the delimiter characters
return If a token is found, a pointer to the beginning of the token.
Otherwise, a null pointer.

*/

char * my_strtok (char* buffer, const char* delims)
{
	// check limits of tokens
	if (delims == 0)
	{
		return 0;
	}

	// pointer to further use function
	static char* token = 0;

	// check for previous token
	if (buffer == 0)
	{
		if (token == 0)
		{
			return 0;
		}
		else
		{
			buffer = token;
		}
	}

	char* beggin = buffer;
	const char* beginDelims = delims;

	while (*buffer   != END)
	{

		delims = beginDelims;

		while (*delims  != END)
		{

			if (*buffer == *delims)
			{

				token = buffer + 1;
				*buffer = END;
				return beggin;
			}
			delims++;
		}
		buffer++;

		//check symbol to create pointer to next token
		if (*buffer == END)
			token = 0;
	}
	return beggin;
}

/* Sets the first num bytes of the block of memory pointed by ptr
to the specified value

param  ptr pointer to the block of memory to fill
param  value value to set
param  num number of bytes to be set to the value
return ptr is returned

*/

void* my_memset (void* pointer1, int value, size_t size)
{
	if (pointer1 == NULL)
		return NULL;

	unsigned char* ptr1 = (unsigned char*)pointer1;

	while (size--)
	{
		*ptr1++ = (unsigned char)value;
	}
	return pointer1;
}