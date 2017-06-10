#ifndef _TERMOUTPUT_H_
#define _TERMOUTPUT_H_
#include "outputControll.h"
#define itself termoutput&
namespace Antinus{
	class termoutput
	{
	private:
		bool AutoClean;
	private:
		long long Allowed_Length;
		int Accuracy;
	public:
		termoutput(bool);
	public:
		termoutput();
		termoutput(termoutput& that);
	public:
		itself operator << (char* source);
		itself operator << (const char* source);
		itself operator << (int source);
		itself operator << (double source);
	public:
		itself operator [] (long long Allowed_Output_length);
	};
}


#undef itself
#endif