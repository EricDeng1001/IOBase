#define IOBASEININEXT_CXDEFINE
#include "IOBase.h"
#include <stdlib.h>
using namespace Antinus;

IOBASEININEXT::IOBASEININEXT()
{
	atexit(close_getch);
	atexit(terminput::free_Table);
	getch_ini();
}
