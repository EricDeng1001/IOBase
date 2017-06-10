#ifndef _FILEINPUT_H_
#define _FILEINPUT_H_
#include "inputControll.h"

namespace Antinus{
	class fileinput
	{
	private:
		int Allowed[128];
		int Banned[128];
		bool AutoClean;
	public:
		fileinput();
		fileinput(fileinput& that);
		fileinput(fileinput&& that);
		fileinput(bool a);
	};
}

#endif //_FILEINPUT_H_