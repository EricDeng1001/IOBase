#include "inputControll.h"

namespace Antinus{
	inputControll::inputControll()
	{
		charset = new int[128];
		int i = 0;
		while(i < 128)
		{
			charset[i++] = 1;
		}
	}

	inputControll::inputControll(const char init)
	{
		charset = new int[128];
		int i = 0;
		while(i < 128)
		{
			charset[i++] = 0;
		}
		charset[init] = 1;
	}

	inputControll::inputControll(const char* init)
	{
		charset = new int[128];
		int i = 0;
		while(i < 128)
		{
			charset[i++] = 0;
		}
		i = 0;
		while(init[i])
		{
			charset[init[i++]]++;
		}
	}

	inputControll::inputControll(inputControll& that)
	{
		charset = new int[128];
		int i = 0;
		while(i < 128)
		{
			charset[i] = that.charset[i++];
		}
	}
	inputControll::inputControll(inputControll&& that):charset(that.charset)
	{
		that.charset = nullptr;
	}
	inputControll::~inputControll()
	{
		delete [] charset;
		charset = nullptr;
	}

	void inputControll::Add(const char* src)
	{ 
		charset = new int[128];
		int i = 0;
		while(src[i])
		{
			charset[src[i++]]++;
		}
	}

	int* inputControll::dump()
	{
		return charset;
	}

	inputControll inputControll::operator + (inputControll& another)
	{
		inputControll tmp(*this);
		int i = 0;
		while(i < 128)
		{
			tmp.charset[i] += another.charset[i++];
		}
		return tmp;
	}

	inputControll inputControll::operator - (inputControll& another)
	{
		inputControll tmp(*this);
		int i = 0;
		while(i < 128)
		{
			tmp.charset[i] -= another.charset[i];
			if(tmp.charset[i] < 0)
				tmp.charset[i] = 0;
		}
		return tmp;
	}

	inputControll inputControll::operator + (const char* Added)
	{
		inputControll tmp(*this);
		int i = 0;
		while(Added[i])
		{
			tmp.charset[Added[i++]]++;
		}
		return tmp;
	}

	inputControll inputControll::operator * (int t)
	{
		inputControll tmp(*this);
		int i = 0;
		while(i < 128)
		{
			tmp.charset[i++] *= t;
		}
		return tmp;
	}

	inputControll operator + (const char* Added,inputControll _this)
	{
		inputControll tmp(_this);
		int i = 0;
		while(Added[i])
		{
			tmp.charset[Added[i++]]++;
		}
		return tmp;
	}

	inputControll operator * (int t,inputControll _this)
	{
		inputControll tmp(_this);
		int i = 0;
		while(i < 128)
		{
			tmp.charset[i++] *= t;
		}
		return tmp;
	}
}
