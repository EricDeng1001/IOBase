#ifndef _TERMINPUT_H_
#define _TERMINPUT_H_
#include "inputControll.h"
#include "VirtualBase/ADTBase/list.h"
#define itself terminput&
namespace Antinus{
	class terminput
	{
	private:
		static long long* llpow;
		static int* pow;
		static unsigned long* ulpow;
	private:
		class Ini{
		public:
			static int* Table_Pow();
			static long long* Table_LLPow();
			static unsigned long* Table_ULPow();
		};
	public:
		static void free_Table();
	private:
		long long* Allowed;
		bool* Ended;
	private:
		long long allowed_num_of_chars;
		bool AutoClean;
		bool WANT_ESC;
		bool CHANGABLE;
		bool SWIFTABLE;
		bool ECHO_BACK;
		bool INPUTMODE;
	private:
		inputControll SIGNAL_ESC;
	public:
		terminput(char);
		terminput(int);
		terminput(double);
	public:
		terminput(bool);
	public:
		terminput();
		terminput(terminput& that);
		terminput(terminput&& that);
		~terminput();
	private:
		bool isAllowed(const char);
		bool isEnded(const char);
	private:
		void NoAllowed();
		void AllAllowed();
		void DefaultEnded();//means ENTER as END
		void DefaultAttr();
		//means |No clean|No esc|No enter|can change|can swift|echo each| 
	public:
		itself operator [] (int allowed_num_of_chars);
	public:
		itself operator [] (const char* allowed_charset);
		itself operator [] (inputControll& Code_of_allowed_charset);
	public:
		itself operator () (const char* when_hit_end_charset);
		itself operator () (inputControll& Code_of_when_hit_end_charset);
	public:
		itself operator + (const char* allowed_charset_only_once);
		itself operator + (inputControll& Code_of_allowed_charset_only_once);
	public:
		itself operator - (const char* Remove_allowed_charset);
		itself operator - (inputControll& Code_of_Remove_allowed_charset);
	public:
		itself operator + (controllCMD&& Special_Request);
	public:
		itself operator >> (char& des) throw(inputControll);
		itself operator >> (char* des) throw(inputControll);
		itself operator >> (int& des);
		itself operator >> (long int& des);
		itself operator >> (long long int& des);
		itself operator >> (unsigned int& des);
		itself operator >> (unsigned long& des);
		itself operator >> (double& des);
		itself operator >> (long double& des);
	public:
		void cleanAttrs();
	};
}
#undef itself
#endif