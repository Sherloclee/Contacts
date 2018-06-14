#include "stdafx.h"
#include "str.h"


Str::Str()
{
	m_str = new char[1];
	m_str[0] = '\0';
}

Str::Str(const char *str)
{
	m_str = new char[strlen(str) + 1];
	strcpy(m_str, str);
}

Str Str::operator+(const Str &s)
{
	char * str;
	str = new char[strlen(this->m_str) + strlen(s.m_str) + 1];
	strcpy(str, this->m_str);
	strcat(str, s.m_str);
	return str;
}

Str Str::operator+(const char * s)
{
	char * str;
	str = new char[strlen(this->m_str) + strlen(s) + 1];
	strcpy(str, this->m_str);
	strcat(str, s);
	return str;
}

Str::~Str()
{
}
