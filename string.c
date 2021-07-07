#include<stdio.h>
#include"string.h"
int readline(string s)
{
	int length;
	stringline* p;
	p = s;
	for (length = 1; p->data != '\n'; length++)
	{
		scanf("%c", &(p->data));
		p->next = (stringline*)malloc(sizeof(stringline));
		if (p->data == '\n')
			break;
		p = p->next;
	}
	p->data = '\0';
	p->next = NULL;
	return p;
}
string copystring(string s)
{
	stringline* p;
	stringline* np;
	string snew;
	snew = (stringline*)malloc(sizeof(stringline));
	np = snew;
	p = s;
	while (p->data != '\0')
	{
		np->data = p->data;
		np->next = (stringline*)malloc(sizeof(stringline));
		np = np->next;
		p = p->next;
	}
	np->data = '\0';
	return snew;
}
void putline(string s)
{
	stringline* p;
	p = s;
	while (p->data != '\0')
	{
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}
int length(string s)
{
	stringline* p;
	int i;
	p = s;
	for (i = 0; p->data != '\0'; i++)
	{
		p = p->next;
	}
	return i;
}
char charAt(string s, int n)
{
	int i;
	stringline* p;
	p = &s;
	if (n > length(s)||n<0)
	{
		return 0;
	}
	for (i = 1; i <= n; i++)
	{
		p = p->next;
	}
	return p->data;
}
void concat(string s1, string s2)
{
	stringline* p1;
	stringline* p2;
	p1 = s1;
	p2 = s2;
	while (p1->data != '\0')
	{
		p1 = p1->next;
	}
	p1->next = (stringline*)malloc(sizeof(stringline));
	while (p2->data != '\0')
	{
		p1 = p1->next;
		p1->data = p2->data;
		p2 = p2->next;
		p1->next = (stringline*)malloc(sizeof(stringline));
	}
	p1->next = NULL;
}
bool contentEquals(string s1, string s2)
{
	stringline* p1;
	stringline* p2;
	p1 = s1;
	p2 = s2;
	while (p1->data != '\0' && p2->data != '\0')
	{
		if (p1->data != p2->data)
		{
			return false;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	return true;
}
int indexof(string s1, string s2)
{
	int i=0;
	int num=-1;
	stringline* sign;
	stringline* p1 = s1;
	stringline* p2 = s2;
	while (p1->data != '\0')
	{
		if (p1->data = p2->data)
		{
			num = i;
			sign = p1;
			while (p2->data != '\0')
			{
				if (p2->data != p1->data)
				{
					num = -1;
					p2 = s2;
					p1 = sign;
					break;
				}
			}
		}
		if (num != -1)
		{
			break;
		}
		p1 = p1->next;
		i++;
	}
	return num;
}
void replace(string s, char oldchar, char newchar)
{
	stringline* p;
	p = s;
	while (p->data != '\0')
	{
		if (p->data == oldchar)
		{
			p->data = newchar;
		}
		p = p->next;
	}
}
void replaceall(string s, string old, string new)
{
	stringline* p, * pold, * pnew_head, * pnew_last;
	stringline* first=NULL, * last;
	int flag=0;
	p = s;
	pold = old;
	pnew_head = copystring(new);
	pnew_last = pnew_head;
	while (pnew_last->next->data != '\0')
	{
		if (pnew_last->next->data == '\0')
			break;
		pnew_last = pnew_last->next;
	}
	while(p->data!='\0')
	{
		if (p->data == pold->data) 
		{
			first = p;
			while (pold->data != '\0')
			{
				p = p->next;
				pold = pold->next;
				if (p->data != pold->data)
				{
					break;
				}
			}
			if (pold->data == '\0')
			{
				flag = 1;
				last = p;
				pold = old;
				first->data = pnew_head->data;
				first->next = pnew_head->next;

				pnew_last->next = last;
				pnew_head = copystring(new);
				pnew_last = pnew_head;
				while (pnew_last->next->data != '\0')
				{
					if (pnew_last->next->data == '\0')
						break;
					pnew_last = pnew_last->next;
				}
			}
			else
			{
				pold = old;
				p = first->next;
			}
		}
		if (p->data == '\0')
			break;
		if (flag)
			flag = 0;
		else
		p = p->next;
	}
}