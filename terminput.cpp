#include "terminput.h"

#define INF_TIME -100
#define itself terminput&
#define me (*this)
#define N(a) //	printf("\n%d\n",a);
#define S(a) //printf("\n%s\n",a);
using namespace Antinus;

int* terminput::Ini::Table_Pow()
{
	int* tmp = new int[10];
	tmp[9] = 1;
	int i = 8;
	while(i >= 0)
	{
		tmp[i] = tmp[i + 1] * 10;
		i--;
	}
	return tmp;
}

int* terminput::pow = terminput::Ini::Table_Pow();

long long* terminput::Ini::Table_LLPow()
{
	long long* tmp = new long long[19];
	tmp[18] = 1;
	int i = 17;
	while(i >= 0)
	{
		tmp[i] = tmp[i + 1] * 10;
		i--;
	}
	return tmp;
}

long long* terminput::llpow = terminput::Ini::Table_LLPow();

unsigned long* terminput::Ini::Table_ULPow()
{
	unsigned long* tmp = new unsigned long[20];
	tmp[19] = 1;
	int i = 18;
	while(i >= 0)
	{
		tmp[i] = tmp[i + 1] * 10;
		i--;
	}
	return tmp;
}

unsigned long* terminput::ulpow = terminput::Ini::Table_ULPow();

void terminput::free_Table()
{
	delete [] pow;
	delete [] llpow;
	delete [] ulpow;
}

void terminput::NoAllowed()
{
	int i = 0;
	while(i < 128)
	{
		Allowed[i++] = 0;
	}
}

void terminput::AllAllowed()
{
	int i = 0;
	while(i < 128)
	{
		Allowed[i++] = INF_TIME;
	}
	Allowed[27] = 0;
	Allowed[127] = 0;
	Allowed['\n'] = 0;
	Allowed['\b'] = 0;
}

void terminput::DefaultEnded()
{
	int i = 0;
	while(i < 128)
	{
		Ended[i++] = false;
	}
	Ended['\n'] = true;
}

void terminput::DefaultAttr()
{
	AutoClean = false;
	WANT_ESC = false;
	CHANGABLE = true;
	SWIFTABLE = true;
	ECHO_BACK = true;
	allowed_num_of_chars = 0;
	INPUTMODE = false;
}

terminput::terminput():SIGNAL_ESC(27)
{
	Allowed = new long long[128];
	Ended = new bool[128];
	AllAllowed();
	DefaultEnded();
	DefaultAttr();
}

terminput::terminput(terminput& that):SIGNAL_ESC(27)
{
	int i = 0;
	Allowed = new long long[128];
	Ended = new bool[128];
	while(i < 128)
	{
		Allowed[i] = that.Allowed[i];
		Ended[i] = that.Ended[i++];
	}
	AutoClean = that.AutoClean;
	WANT_ESC = that.WANT_ESC;
	CHANGABLE = that.CHANGABLE;
	SWIFTABLE = that.SWIFTABLE;
	ECHO_BACK = that.ECHO_BACK;
	allowed_num_of_chars = that.allowed_num_of_chars;
	INPUTMODE = that.INPUTMODE;
}

terminput::terminput(terminput&& that):SIGNAL_ESC(27)
{
	that.Ended = nullptr;
	that.Allowed = nullptr;
	Allowed = that.Allowed;
	Ended = that.Ended;
	AutoClean = that.AutoClean;
	WANT_ESC = that.WANT_ESC;
	CHANGABLE = that.CHANGABLE;
	SWIFTABLE = that.SWIFTABLE;
	ECHO_BACK = that.ECHO_BACK;
	allowed_num_of_chars = that.allowed_num_of_chars;
	INPUTMODE = that.INPUTMODE;
}

terminput::terminput(bool a):SIGNAL_ESC(27)
{
	Allowed = new long long[128];
	Ended = new bool[128];
	AllAllowed();
	DefaultEnded();
	DefaultAttr();
	AutoClean = true;
}

terminput::terminput(char a):SIGNAL_ESC(27)
{
	Allowed = new long long[128];
	Ended = new bool[128];
	AllAllowed();
	DefaultEnded();
	DefaultAttr();
	me["-0123456789"];
}

static terminput SYM_IN('-');

terminput::terminput(int a):SIGNAL_ESC(27)
{
	Allowed = new long long[128];
	Ended = new bool[128];
	AllAllowed();
	DefaultEnded();
	DefaultAttr();
	me["0123456789"];
}

static terminput INT_IN((int)1);

terminput::terminput(double a):SIGNAL_ESC(27)
{
	Allowed = new long long[128];
	Ended = new bool[128];
	AllAllowed();
	DefaultEnded();
	DefaultAttr();
	me["1234567890"] + ".";
}

static terminput DOUB_IN((double)1);

terminput::~terminput()
{   
	delete [] Allowed;
	Allowed = nullptr;
	delete [] Ended;
	Ended = nullptr;
}

bool terminput::isAllowed(const char which)
{
	if(Allowed[(int)which] == INF_TIME)
		return true;
	else if(Allowed[(int)which] != 0){
		Allowed[(int)which]--;
		return true;
	}
	else
		return false;
}

bool terminput::isEnded(const char which)
{
	return Ended[(int)which];
}

itself terminput::operator [] (int Allowed_time)
{
	allowed_num_of_chars = Allowed_time;
	return me;
}

itself terminput::operator [] (const char* Allowed_charset)
{
	NoAllowed();
	int i = 0;
	while(Allowed_charset[i])
	{
		Allowed[Allowed_charset[i++]] = INF_TIME;
	}
	Allowed[27] = 0;
	Allowed['\n'] = 0;
	Allowed['\b'] = 0;
	Allowed[127] = 0;
	return me;
}

itself terminput::operator [] (inputControll& Code_Allowed_charset) 
{
	NoAllowed();
	int i = 0;
	int* tmp = Code_Allowed_charset.dump();
	while(i < 128)
	{
		if(tmp[i])
			Allowed[i] = INF_TIME;
		i++;
	}
	Allowed[27] = 0;
	Allowed['\n'] = 0;
	Allowed['\b'] = 0;
	Allowed[127] = 0;
	return me;
}

itself terminput::operator () (const char* src)
{
	int i = 0;
	Ended['\n'] = false;
	while(src[i])
	{
		Ended[src[i++]] = true;
	}
	return me;
}

itself terminput::operator () (inputControll& Code)
{
	int i = 0;
	Ended['\n'] = false;
	int* tmp = Code.dump();
	while(i < 128)
	{
		if(tmp[i]){
			Ended[i] = true;
		}
		i++;
	}
	return me;
}

itself terminput::operator >> (char& des) throw(inputControll)
{
	char tmp;
	while(true){
		tmp = getchar();
		if(tmp == 27)
			if(WANT_ESC)
				throw SIGNAL_ESC;
		if(isAllowed(tmp)){
			des = tmp;
			if(ECHO_BACK)
				putchar(des);
			break;
		}
	}
	return me;
}


itself terminput::operator >> (char* des) throw(inputControll)
{
	unsigned long record_char = 0;
	unsigned long write_at_char = 0;
	unsigned long i;
	unsigned long len;
	list<char> M;
	char mid; 
	char tmp;
	while(record_char < allowed_num_of_chars)
	{
		mid = getchar();
		if(mid == '\r'){
			mid = '\n';
		}
		if(isEnded(mid)){
			if(!INPUTMODE)
				putchar('\n');
			break;
		}
		else if(isAllowed(mid)){
			M.Insert(mid,write_at_char++);
			record_char++;
			if(ECHO_BACK){
				i = write_at_char - 1;
				len = M.length();
				while(i < len){
					putchar(M[i]);
					i++;
				}
				i = write_at_char;
				while(i < len){
					putchar('\b');
					i++;
				}
			}
			if(record_char >= allowed_num_of_chars) 
				break;
		}
		else if(mid == 27){
			if((mid = getchar()) == 91){
				if((tmp = getchar()) == 'C'){
					if(write_at_char < record_char){
						//right
						putchar(M[write_at_char++]);
					}
				}
				else if (tmp == 'D') {
					//left
					if(write_at_char > 0){
						putchar('\b');
						write_at_char--;
					}
				}
				else if (tmp == 'A') {
				 //up	
				}
				else if (tmp == 'B') {
				//down
				}
				else{
					if(WANT_ESC) 
						throw SIGNAL_ESC;
				}
			}
			else{
				if(WANT_ESC) 
					throw SIGNAL_ESC;
			}	
		}
		else if(mid == '\b' || mid == 127){
			if(CHANGABLE){
				if(write_at_char > 0){
					write_at_char--;
					record_char--;
					M.Delete(write_at_char);
					putchar('\b');
					if(ECHO_BACK){
						len = record_char - write_at_char;
						i = 0;
						while(i < len){
							putchar(M[write_at_char + i]);
							i++;
						}
						putchar(' ');
						putchar('\b');
						i = 0;
						while(i < len){
							putchar('\b');
							i++;
						}
					}
				}
			}
		}
	}

	char* temp;
	temp = M.Array();
	write_at_char = 0;
	while(write_at_char < record_char){
		des[write_at_char] = temp[write_at_char++];
	}
	if(record_char == allowed_num_of_chars)
		if(!INPUTMODE)
			putchar('\n');
	if(AutoClean) 
		cleanAttrs();
	fflush(stdin);
	return me;
}

itself terminput::operator >> (int& des)
{
	char tmp[10];
	int i = 0;
	bool neg = false;
	while(i < 10)
	{
		tmp[i++] = 0;
	}

	SYM_IN >> tmp[0];
	if(tmp[0] == '-'){
		neg = true;
		INT_IN[10] >> tmp;
	}
	else{
		INT_IN[9] >> tmp + 1;
	}
	int mid = 0;
	int len = 0;
	i = 0;
	while(tmp[i])
	{
		len++;
		i++;
	}
	i = 10 - len;
	int j = 0;
	while(i < 10)
	{
		mid += (tmp[j++] - '0') * pow[i];
		i++;
	}
	des = mid;
	if(neg)
		des = -des;
	return me;
}

itself terminput::operator >> (long int& des)
{
	char tmp[19];
	int i = 0;
	bool neg = false;
	while(i < 19)
	{
		tmp[i++] = 0;
	}

	SYM_IN >> tmp[0];
	if(tmp[0] == '-'){
		neg = true;
		INT_IN[19] >> tmp;
	}
	else{
		INT_IN[18] >> tmp + 1;
	}
	long long mid = 0;
	int len = 0;
	i = 0;
	while(tmp[i])
	{
		len++;
		i++;
	}
	i = 19 - len;
	int j = 0;
	while(i < 19)
	{
		mid += (tmp[j++] - '0') * llpow[i];
		i++;
	}
	des = mid;
	if(neg)
		des = -des;
	return me;
}

itself terminput::operator >> (long long int& des)
{
	char tmp[19];
	int i = 0;
	bool neg = false;
	while(i < 19)
	{
		tmp[i++] = 0;
	}
	SYM_IN >> tmp[0];
	if(tmp[0] == '-'){
		neg = true;
		INT_IN[19] >> tmp;
	}
	else{
		INT_IN[18] >> tmp + 1;
	}
	long long mid = 0;
	int len = 0;
	i = 0;
	while(tmp[i])
	{
		len++;
		i++;
	}
	i = 19 - len;
	int j = 0;
	while(i < 19)
	{
		mid += (tmp[j++] - '0') * llpow[i];
		i++;
	}
	des = mid;
	if(neg)
		des = -des;
	return me;
}

itself terminput::operator >> (unsigned int& des)
{
	char tmp[10];
	int i = 0;
	while(i < 10)
	{
		tmp[i++] = 0;
	}
	INT_IN[10] >> tmp;
	unsigned int mid = 0;
	int len = 0;
	i = 0;
	while(tmp[i])
	{
		len++;
		i++;
	}
	i = 10 - len;
	int j = 0;
	while(i < 10)
	{
		mid += (tmp[j++] - '0') * pow[i];
		i++;
	}
	des = mid;
	return me;
}

itself terminput::operator >> (unsigned long& des)
{
	char tmp[20];
	int i = 0;
	while(i < 20)
	{
		tmp[i++] = 0;
	}
	INT_IN[20] >> tmp;
	unsigned int mid = 0;
	int len = 0;
	i = 0;
	while(tmp[i])
	{
		len++;
		i++;
	}
	i = 20 - len;
	int j = 0;
	while(i < 20)
	{
		mid += (tmp[j++] - '0') * pow[i];
		i++;
	}
	des = mid;
	return me;
}

itself terminput::operator + (const char* src)
{
	int i = 0;
	while(src[i])
	{
		Allowed[src[i++]]++;
	}
	return me;
}

itself terminput::operator + (inputControll& Code)
{
	int* tmp = Code.dump();
	int i = 0;
	while(i < 128)
	{
		if(tmp[i]){
			Allowed[i]++;
		}
		i++;
	}
	return me;
}

itself terminput::operator - (const char* src)
{
	int i = 0;
	while(src[i])
	{
		Allowed[src[i++]] = 0;
	}
	return me;
}

itself terminput::operator - (inputControll& Code)
{
	int* tmp = Code.dump();
	int i = 0;
	while(i < 128)
	{
		if(tmp[i]){
			Allowed[i] = 0;
		}
		i++;
	}
	return me;
}

itself terminput::operator + (controllCMD&& CMD)
{
	switch(CMD)
	{
		case QUIET:
		case PASSWD_MODE:
			ECHO_BACK = false;
		break;
		case NEED_ESC:
		case ESC_AS_MENU_SIGNAL:
			WANT_ESC = true;
		break;
		case RECORD_ENTER:
		case FILE_STRUCTURE:
			Ended['\n'] = false;
			Allowed['\n'] = INF_TIME;
		break;
		case NO_CHANGE:
			CHANGABLE = false;
		break;
		case NO_SWIFT:
			SWIFTABLE = false;
		break;
		case NO_AUTO_BREAK:
			INPUTMODE = true;
		break;
	}
	return me;
}

void terminput::cleanAttrs()
{
	AllAllowed();
	DefaultAttr();
	DefaultEnded();
	AutoClean = true;
}




