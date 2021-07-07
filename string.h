#ifdef STRING
#define STRING
#endif // STRINH
#include<malloc.h>
#define bool int
#define true 1
#define false 0
typedef struct str {
	char data;
	struct str* next;
} stringline;
typedef struct str *string;
int readline(string s);
string copystring(string s);
void putline(string s);
int length(string s);
char charAt(string s, int n);
void concat(string s1, string s2);
bool contentEquals(string s1, string s2);
int indexof(string s1, string s2);
void replace(string s, char oldchar, char newchar);
void replaceall(string s, string old, string new);