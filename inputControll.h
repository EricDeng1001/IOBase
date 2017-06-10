#ifndef _INPUTCONTROLL_H_
#define _INPUTCONTROLL_H_

#include "getch.h"
#define LEFT -112
#define RIGHT -18
#define UP -75
#define DOWN -104
namespace Antinus{
	enum controllCMD : int
	{
		QUIET = 1234,
		NEED_ESC = 89, // warning -- if wanted ESC signal ,please CATCH it; use try{} catch{};
		RECORD_ENTER = 90,
		NO_CHANGE = 10042,
		NO_SWIFT = 10046,
		FILE_STRUCTURE = 9,
		PASSWD_MODE = 674,
		ESC_AS_MENU_SIGNAL = 98, // warning -- if wanted ESC signal ,please CATCH it; use try{} catch{};
		NO_AUTO_BREAK = 1
	};
	class inputControll
	{
	private:
		int* charset;
	public:
		inputControll(void);
		inputControll(const char init);
		inputControll(const char* init);
		inputControll(inputControll& that);
		inputControll(inputControll&& that);
		~inputControll();
	public:
		void Add(const char*);
		int* dump(void);
	public:
		inputControll operator + (inputControll& another);
		inputControll operator - (inputControll& another);
	public:
		inputControll operator + (const char* Added);
	public:
		inputControll operator * (int times);
	public:
		friend inputControll operator + (const char* Added,inputControll _this_);
		friend inputControll operator * (int times,inputControll _this_);
	};
	extern inputControll operator + (const char* Added,inputControll _this_);
	extern inputControll operator * (int times,inputControll _this_);
} 

#endif