#pragma once
class Str
{
	friend ostream operator<<(ostream &out, const Str &s);
	friend istream operator>>(istream &in, Str &s);

private:
	char *m_str;

public:
	Str();
	Str(const char *str = NULL);
	Str(const Str &str);
	Str operator+(const Str &s);
	Str operator+(const char *);

	~Str();
};

