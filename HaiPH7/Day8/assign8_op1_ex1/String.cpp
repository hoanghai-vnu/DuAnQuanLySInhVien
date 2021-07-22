#include "String.h"
using namespace std;

String::String(): m_str(0), m_size(0)
{}

String::String(const char *cStr): m_str(0), m_size(0)
{
	// Find length
	int length=0;
	while(cStr[length] != '\0')
		length++;
	m_size = length;	// Update size
	m_str = new char[m_size+1];	// Add 1 for '\0' character
	// Copy
	for(int i=0; i<m_size+1; i++)
		m_str[i] = cStr[i];
}

String::String(const String &other): m_str(0), m_size(0)
{
	m_size = other.m_size;	// Update size
	m_str = new char[m_size+1];
	// Copy
	for(int i=0; i<m_size+1; i++)
		m_str[i] = other.m_str[i];
}

String& String::operator=(const String &other)
{
	if(this == &other)
		return *this;
	delete[] m_str;	m_str = NULL;	// delete old value (memory - avoid leak mem)
	m_size = other.m_size;	// Update size
	m_str = new char[m_size+1];
	// Copy
	for(int i=0; i<m_size+1; i++)
		m_str[i] = other.m_str[i];
		
	return *this;
}

String::~String()
{
	delete[] m_str;	// free
}

// =============================================================================

std::ostream& operator<<(std::ostream &output, const String &s)
{
	if(s.m_str == NULL)
		return output;
	output << s.m_str;
	return output;
}

std::istream& operator>>(std::istream &input, String &s)
{
	int maxSize = 100;
	int length = 0;
	char c;
	s.m_str = new char[maxSize+1];
	
	while((c = getchar()) != '\n'){		// Type string until you press Enter
		// If input's size > current maxSize, reallocate
		if(length >= maxSize){
			maxSize += 100;
			char *temp = new char[maxSize+1];
			for(int i=0; i<length; i++)
				temp[i] = s.m_str[i];
			delete[] s.m_str;	// free 
			s.m_str = temp;
		}
		// Add next char input to m_str
		s.m_str[length] = c;
		length++;
	}
	s.m_str[length] = '\0'; // Add '\0' to the end
	s.m_size = length;	// Update size
	
	return input;
}

// =============================================================================

void String::erase()
{
	*this = "";
}

int String::size() const
{
	return m_size;
}

void String::reverse()
{
	String temp(*this);
	for(int i=0; i<m_size; i++)
		m_str[i] = temp[m_size-i-1];
}

// Chỉ để cho đối tượng bên ngoài lớp dùng
char& String::operator[](int i)
{
	return m_str[i];	
}
// Chỉ để cho đối số là đối tượng bên ngoài lớp dùng
char& String::operator[](int i) const
{
	return m_str[i];	
}

// =============================================================================

String& String::operator+=(String const& s)
{
	int size = m_size + s.m_size;
	char *result = new char[size + 1];
	// Copy
	for(int i=0; i<m_size; i++)
		result[i] = m_str[i];
	for(int i=0; i<s.m_size + 1; i++)
		result[m_size + i] = s.m_str[i];
		
	delete[] m_str;	// free
	m_str = result;
	m_size = size;	// Update size
	
	return *this;	
}

String operator+(String const& s1, String const& s2)
{
	String result;
	result += s1;
	result += s2;
	return result;
}

// =============================================================================

bool operator==(String const& s1, String const& s2)
{
	if (s1.size() != s2.size())
		return false;
	int n = s1.size();
	for(int i=0; i<n; i++)
		if(s1[i] != s2[i]) 
			return false;
	return true;		
}

bool operator!=(String const& s1, String const& s2)
{
	return !(s1 == s2);
}

bool operator<(String const& s1, String const& s2)
{
	int i=0;
	int min = (s1.size() < s2.size() ? s1.size() : s2.size());
	for(i=0; i<min; i++)
		if(s1[i] != s2[i]) 
			break;
	return (s1[i] < s2[i]);
}

bool operator>(String const& s1, String const& s2)
{
	return !(s1<s2 || s1==s2);
}

bool operator<=(String const& s1, String const& s2)
{
	return (s1<s2 || s1==s2);
}

bool operator>=(String const& s1, String const& s2)
{
	return (s1 < s2);
}
