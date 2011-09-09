/* 
 * File:   PcInfo.h
 * Author: redo86
 *
 * Created on 4 luglio 2010, 16.19
 */

#ifndef PCINFO_H
#define	PCINFO_H



#endif	/* PCINFO_H */
#include<iostream>
using namespace std;

//definzione funzioni
void PcInfo(string);//informazioni sul pc: processore, os etc

void PcInfo(string cmd){
     char Info[500];
     send(cl_sk,cmd.c_str(),cmd.size(),0);
     int fine=recv(cl_sk,Info,500,0);
     Info[fine]='\0';
     cout<<endl<<Info<<endl<<endl;
     return;

}