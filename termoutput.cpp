#include "termoutput.h"
#define itself termoutput&
#define me *this
using namespace Antinus;

template <class T>
void PrintDigit(T digit){
	if(digit < 10){
		putchar(digit + '0');
	}
	else{
		T mid = digit/10;
		PrintDigit(mid);
		putchar(digit - mid*10 + '0');
	}
}

void PrintDigit(double digit,int Accuracy){
	long long interger = (long long)digit;
	PrintDigit<long long>(digit);
	putchar('.');
	PrintDigit((long long)((digit - interger)*Accuracy));
}

termoutput::termoutput(bool a)
{
	Allowed_Length = 0;
	AutoClean = false;
	Accuracy = 5;
}

termoutput::termoutput()
{
	Allowed_Length = 0;
	AutoClean = true;
	Accuracy = 5;
}

termoutput::termoutput(termoutput& that)
{
	Allowed_Length = that.Allowed_Length;
	AutoClean = that.AutoClean;
	Accuracy = that.Accuracy;
}

itself termoutput::operator [] (long long h)
{
	Allowed_Length = h;
}

itself termoutput::operator << (char* source)
{
	long long i = 0;
	if(!Allowed_Length){
		while(source[i]){
			putchar(source[i++]);
		}
	}
	else{
		while(i < Allowed_Length&&source[i]){
			putchar(source[i++]);
		}
	}
	return me;
}

itself termoutput::operator << (int source)
{
	PrintDigit(source);
	return me;
}


itself termoutput::operator << (double source)
{
	PrintDigit(source,Accuracy);
	return me;
}

itself termoutput::operator << (const char* source)
{
	long long i = 0;
	while(source[i])
		putchar(source[i++]);
	return me;
}
	