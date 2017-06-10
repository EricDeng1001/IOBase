#ifndef _IN_H_
#define _IN_H_
#include "terminput.h"
#include "fileinput.h"

namespace Antinus{
	class In
	{
	private:
		terminput* Tin;
		fileinput* Fin;
	private:
		bool AutoClean;
	public:
		In();
		In(In& that);
		In(In&& that);
		In(bool);
		~In();
	};
}

#endif