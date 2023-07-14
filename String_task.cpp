#include <iostream>
#include <vector>
#include <algorithm>

class MyString
{
public:
	MyString()
	{
		str = nullptr;
		length = 0;
	}
	MyString(const char *str)
	{
		length = strlen(str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0';
	}
	~MyString()
	{
		delete[] this->str;
	}

	MyString& operator = (const MyString& s)
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}
		length = strlen(str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = s.str[i];
		}
		this->str[length] = '\0';
		return *this;
	}

	MyString operator+(const MyString& s)
	{
		MyString newStr;
		int thisLen = strlen(this->str);
		int sLength = strlen(s.str);
		newStr.length = thisLen + sLength;
		newStr.str = new char[thisLen + sLength + 1];
		int i = 0;
		for (; i < thisLen; i++)
		{
			newStr.str[i] = this->str[i];
		}
		for (int j = 0; j < sLength; j++, i++)
		{
			newStr.str[i] = s.str[j];
		}
		newStr.str[thisLen + sLength] = '\0';
		return newStr;
	}

	MyString(const MyString& myString)
	{
		length = strlen(myString.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			str[i] = myString.str[i];
		}
		str[length] = '\0';
	}

	MyString operator += (const MyString& s)
	{
		int newSize = strlen(str);
		int sSize = strlen(s.str);
		char* newStr = new char[newSize + sSize + 1];

		for (int i = 0; i < newSize; i++) 
		{
			newStr[i] = str[i];
		}

		for (int i = 0; i < sSize; i++) 
		{
			newStr[newSize + i] = s.str[i];
		}

		newStr[newSize + sSize] = '\0';

		delete[] str;
		str = newStr;

		return *this;
	}

	void Print()
	{
		std::cout << str << std::endl;
	}

	int Length() const
	{
		return length;
	}

	bool operator ==(const MyString& s)
	{
		if (this->length != s.length)
		{
			return false;
		}
		for (int i = 0; i < length; i++)
		{
			if (this->str[i] != s.str[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator != (const MyString& s)
	{
		return !(this->operator==(s));
	}

	friend std::ostream& operator<<(std::ostream& os, const MyString& s)
	{
		os << s.str;
		return os;
	}

	friend std::istream& operator>>(std::istream& is, MyString& s)
	{
		char buffer[1000];
		is.getline(buffer, 1000);
		int length = 0;
		while (buffer[length] != '\0')
		{
			length++;
		}
		delete[] s.str;
		s.str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			s.str[i] = buffer[i];
		}
		s.str[length] = '\0';
		s.length = length;
		return is;
	}

	bool operator <(const MyString& s)
	{
		int i = 0;
		while (i < Length() && i < s.Length())
		{
			if (str[i] < s.str[i])
			{
				return true;
			}
			else if (str[i] > s.str[i])
			{
				return false;
			}
			i++;
		}
		return Length() < s.Length();
	}

private:
	char* str;
	int length;
};

int main()
{
	int stringsNumber;
	std::cout << "Enter the number of strings: ";
	std::cin >> stringsNumber;

	std::vector<MyString> strings;
	std::cout << "Enter the strings: " << std::endl;

	for (int i = 0; i < stringsNumber; i++)
	{
		MyString s;
		std::cin >> s;
		strings.push_back(s);
	}

	std::cout << "Sorted strings: " << std::endl;
	std::sort(strings.begin(), strings.end());

	for (const MyString& s : strings)
	{
		std::cout << s << std::endl;
	}

	return 0;
}

