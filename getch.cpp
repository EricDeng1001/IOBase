#include "getch.h"

#define ECHOFLAGS (ECHO | ECHOE | ECHOK | ECHONL)
static struct termios stored_settings;
int getch_ini(void)
{
     struct termios new_settings;
     tcgetattr (0, &stored_settings);
     new_settings = stored_settings;
     new_settings.c_lflag &= (~ICANON);
     new_settings.c_lflag &= (~ECHOFLAGS);
     new_settings.c_cc[VTIME] = 0;
     new_settings.c_cc[VMIN] = 1;
     tcsetattr (0, TCSANOW, &new_settings);
}

void close_getch(void)
{
     tcsetattr (0, TCSANOW, &stored_settings);
}