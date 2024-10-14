#include<iostream>
using namespace std;
#include "String.h"

String::String()
{
	size = 0;
	data = nullptr;
}
String::String(const char c)
{
	size = 2;
	data = new char[size] {c, '\0'};
}
String::String(const char* str)
{
	int len = getLength(str);
	data = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
	{
		data[i] = str[i];
	}
	size = len + 1;
}
String :: ~String()
{
	delete[] data;
	data = nullptr;
	size = 0;
}
int String::getLength(const char* str) const
{

	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}
bool String::isEmpty() const
{
	if (data == nullptr || data[0] == '\0')
	{
		return true;
	}
	return false;
}
bool String::isValidIndex(int index)
{
	if (index >= 0 && index < size)
	{
		return true;
	}
	else
	{
		return false;
	}
}
char& String::at(const int index)
{
	if (isValidIndex(index))
	{
		return data[index];
	}
}
void String::makeUpper()
{
	int i = 0;
	while (data != nullptr && data[i] != '\0')
	{
		if (data[i] >= 'a' && data[i] <= 'z')
		{
			data[i] = data[i] - 32;
		}

		i++;
	}
}
void String::makeLower()
{
	int i = 0;
	while (data != nullptr && data[i] != '\0')
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			data[i] = data[i] + 32;
		}

		i++;
	}
}
void String::myswap(char& i, char& j)
{
	char temp;
	temp = i;
	i = j;
	j = temp;
}
void String::reverse()
{
	if (data != nullptr)
	{
		int len = getLength(data);
		int i = 0;
		int j = len - 1;
		while (i < j)
		{
			myswap(data[i], data[j]);
			j--;
			i++;
		}
	}


}
void String::copystring(char* destination, char* source)
{
	int i = 0;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
}
void String::reSize(int newSize)
{
	if (newSize < size)
	{
		data[newSize] = '\0';
		size = newSize;
	}
	if (newSize > size)
	{
		char* newData = new char[newSize + 1];
		if (data)
		{
			copystring(newData, data);
		}
		delete[] data;
		data = newData;
		size = newSize;
		data[size] = '\0';
	}
}
void String::input()
{
	data = new char[size];
	while (!cin.getline(data, '\n'))
	{
		cin >> data;
	}
	size = getLength(data);
}
void String::display()
{
	cout << data;
}
int String::getLength() const
{
	return getLength(data);
}
int String::getSize() const
{
	return size;
}
void String::shrink()
{
	int len = getLength();
	if (len != size)
	{
		size = len;
	}
}
String String::left(const int count)
{
	int len = getLength();
	if (count > 0 && count <= len)
	{
		String obj;
		obj.data = new char[count + 1];
		int i = 0;
		while (i < count && data[i] != '\0')
		{

			obj.data[i] = data[i];
			i++;

		}
		obj.data[i] = '\0';
		obj.size = i;
		return obj;
	}

}
String String::right(const int count)
{
	int len = getLength();
	if (count > 0 && count <= len)
	{
		String obj;
		obj.size = count + 1;
		obj.data = new char[obj.size];
		obj.data[count] = '\0';
		int i = count - 1;

		int j = len - 1;
		while (i >= 0)
		{
			obj.data[i] = data[j];
			i--;
			j--;
		}
		return obj;
	}

}
long long int String::convertToInteger() const
{
	long long int ans = 0;
	long long int i = 0;
	long long int num = 0;
	while (data != nullptr && data[i] != '\0')
	{
		int y = data[i] - 48;
		num = ans * 10 + y;
		ans = num;
		i++;
	}
	return ans;

}
String String::concatenate(const String& s2) const
{
	String s3;
	int len1 = getLength();
	int len2 = s2.getLength();
	s3.size = len1 + len2;
	s3.data = new char[s3.size + 1];
	int i = 0;
	while (data[i] != '\0')
	{
		s3.data[i] = data[i];
		i++;
	}
	int j = 0;
	while (s2.data[j] != '\0')
	{
		s3.data[i] = s2.data[j];
		i++;
		j++;
	}
	s3.data[i] = '\0';
	return s3;
}
void String::trimLeft()
{
	int i = 0;
	while (data[i] == ' ')
	{
		i++;
	}
	int j = i;
	while (data[j] != '\0')
	{
		data[j - i] = data[j];
		j++;
	}
	data[j - i] = '\0';
	size = j - i + 1;

}
void String::trimRight()
{
	int i = size - 2;
	while (data[i] == ' ')
	{
		i--;
	}
	data[i + 1] = '\0';

}
void String::trim()
{
	trimLeft();
	trimRight();
}
void String::remove(const int index, int count = 1)
{
	if (index<0 || index>size)
	{
		return;
	}
	int i = index;
	while (data[i + count] != '\0')
	{
		data[i] = data[i + count];
		i = i + 1;
	}
	data[i] = '\0';
}
int String::find(const String& subStr, const int start)
{
	int len = subStr.getLength();
	int i = 0;
	while (data[i] != '\0')
	{
		if (data[i] == subStr.data[0])
		{
			int count = 0;
			int j = 0;
			while (j < len)
			{
				if (data[i] == subStr.data[j] && subStr.data[j] != '\0')
				{
					count++;
					i++;
				}
				j++;
			}
			if (count == len)
			{
				return i - len;
			}
		}
		else
		{
			i++;
		}
	}
	return -1;
}

void String::insert(const int index, const String& subStr)
{
	if (subStr.data[0] == '\0')
	{
		data[index] = '\0';
	}
	int len2 = subStr.getLength();
	int len1 = getLength();
	int newSize = len1 + len2;
	if (getSize() < newSize)
	{
		reSize(newSize + 1);
	}
	for (int i = len1 - 1; i >= index; i--)
	{
		data[i + len2] = data[i];
	}
	for (int j = 0; j < len2; j++)
	{
		data[index + j] = subStr.data[j];
	}
	data[newSize] = '\0';
}
bool String::isDigit(const char c)const
{
	if (c >= '0' && c <= '9')
	{
		return true;
	}
	return false;
}
bool String::isNegativeNum() const
{
	if (size > 0 && data[0] == '-')
	{
		return true;
	}
	return false;
}

String::operator int() const
{
	int num = 0;
	bool isNegative = false;
	for (int i = 0; i < size; i++)
	{
		if (data[i] == '-')
		{
			isNegative = true;
		}
		else if (isDigit(data[i]))
		{
			num = num * 10 + (data[i] - '0');
		}
	}
	if (isNegative)
	{
		num = -num;
	}
	return num;
}
void String::operator +=(const String& r) {
	if (r.isEmpty()) {
		return;
	}

	char* temp = new char[size + r.size + 1];
	copystring(temp, data);

	int i = size;
	for (int j = 0; j < r.size; j++) {
		temp[i++] = r.data[j];
	}
	temp[i] = '\0';

	delete[] data;
	data = temp;
	size += r.size;
}

istream& operator >> (std::istream& is, String& r)
{
	r.input();
	return is;
}
ostream& operator<<(std::ostream& os, const String& str)
{
	os << str.data;
	return os;
}
String operator+(const char* lhs, const String& rhs)
{
	int lhsLen = strlen(lhs);
        int rhsLen = rhs.getLength();

	String result;
	result.reSize(lhsLen + rhsLen + 1);

	for (int i = 0; i < lhsLen; i++)
	{
		result.data[i] = lhs[i];
	}

	for (int i = 0; i < rhsLen; i++)
	{
		result.data[lhsLen + i] = rhs.data[i];
	}

	result.data[lhsLen + rhsLen] = '\0';
	result.size = lhsLen + rhsLen;

	return result;
}
