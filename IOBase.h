#ifndef _IOBASE_H_
#define _IOBASE_H_
#include "In.h"
#include "out.h"
namespace Antinus{
	class IOBASEININEXT{
	public:
		IOBASEININEXT();
	};
}
#ifndef IOBASEININEXT_CXDEFINE
namespace Antinus{
	
	inputControll ALL;
	inputControll LETTER("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");
	inputControll LOWER("qwertyuiopasdfghjklzxcvbnm");
	inputControll UPPER("QWERTYUIOPASDFGHJKLZXCVBNM");
	inputControll NUMBER("1234567890");
	inputControll SYMBOL("`~!@#$%^&*()_+-=");
	inputControll BTN_TAB('\t');
	inputControll BTN_SPACE(' ');
	inputControll BTN_ENTER('\n');
	
	terminput termin(true);
	termoutput termout(true);	
	IOBASEININEXT IOBASEININEXT_ini;
}
#endif
#endif //_IOBASE_H_