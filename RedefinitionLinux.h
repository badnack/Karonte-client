/* 
 * File:   RedefinitionLinux.h
 * Author: redo86
 *
 * Created on 8 luglio 2010, 16.19
 */

#ifndef REDEFINITIONLINUX_H
#define	REDEFINITIONLINUX_H



#endif	/* REDEFINITIONLINUX_H */


#include<iostream>
using namespace std;
#define fflush(stdin) while ((getchar()) != '\n')
#include <termios.h>

//dichiarazioni
void my_itoa(int,std::string&,int);//itoa per linux
int mygetch(void);
void Beep(string);

int mygetch() {
  struct termios oldt,newt;
  int ch;
  tcgetattr( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
  return ch;
}

void my_itoa(int value, std::string& buf, int base){
	int i = 30;
	buf = "";
	for(; value && i ; --i, value /= base) buf = "0123456789abcdef"[value % base] + buf;

}

void Beep(string sound){
//devo aprirlo e richiuderlo altrimenti non produce suoni
          FILE *fp=fopen("/dev/dsp","wb");
          if(fp!=NULL){
          fwrite (sound.c_str(),1, sound.length(),fp);//riproduco un suono
          
          fclose(fp);}
}