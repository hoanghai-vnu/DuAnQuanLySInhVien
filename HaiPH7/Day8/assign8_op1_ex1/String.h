#ifndef DEF_STRING
#define DEF_STRING
#include <iostream>

class String
{
	char *m_str;
	int m_size; // store size for a very long string, avoid many calculations
public:	
	// Block 1
	String();
	String(const char *other);
	String(const String &other);
	String& operator=(const String &other);
	~String();
	
	// Block 2
	friend std::ostream& operator<<(std::ostream &output, const String &s);
	friend std::istream& operator>>(std::istream &input, String &s);
	
	// Block 3
	void erase();
	int size() const;
	void reverse();
	char& operator[](int i);
	char& operator[](int i) const;
	
	// Block 4
	String& operator+=(String const& s);
	friend String operator+(String const& s1, String const& s2);

	// Block 5
	friend bool operator==(String const& s1, String const& s2);
	friend bool operator!=(String const& s1, String const& s2);
	friend bool operator<(String const& s1, String const& s2);
	friend bool operator>(String const& s1, String const& s2);
	friend bool operator<=(String const& s1, String const& s2);
	friend bool operator>=(String const& s1, String const& s2);
};

#endif // STRING
