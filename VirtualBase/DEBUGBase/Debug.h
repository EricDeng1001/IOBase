#ifndef _DEBUG_H_
#define _DEBUG_H_
#ifndef _NODEBUG_
#include <stdio.h>
#include <typeinfo>
#include <time.h>
#include <iostream>
static unsigned int test_order_do_not_use = 1;
static unsigned int loop_order_do_not_use = 0;
static clock_t speedtest_time1_do_not_use;
static clock_t speedtest_time2_do_not_use;
#define test_valid(s) printf("测试语句%d完成,%s合法\n",test_order_do_not_use++,s)
#define executed(s) printf("语句%s被执行了\n",s)
#define looptest() loop_order_do_not_use = 0
#define haslooped(s) printf("循环%s正在执行第%d次\n",s,loop_order_do_not_use)
#define success(s) printf("%s成功\n",s)
#define entering(s) printf("正在进入函数%s\n",s)
#define exiting(s) printf("正在退出函数%s\n",s)
#define var_dump(var) std::cout<<"name:"<<#var<<"    type:"<<typeid(var).name()<<"    value:"<<var<<std::endl;
#define speedtest(expr) speedtest_time1_do_not_use = clock();expr;speedtest_time2_do_not_use = clock();printf("代码\n\n%s\n\n运行时间%ldms\n",#expr,(speedtest_time2_do_not_use - speedtest_time1_do_not_use)/(CLOCKS_PER_SEC/1000));
#else
#define test_valid(s) 
#define executed(s) 
#define looptest() 
#define haslooped(s) 
#define success(s) 
#define entering(s) 
#define exiting(s) 
#define var_dump(var) 
#define speedtest(expr)
#endif // _NODEBUG_
#endif