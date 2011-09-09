/* 
 * File:   Process.h
 * Author: redo86
 *
 * Created on 4 luglio 2010, 15.06
 */

#ifndef PROCESS_H
#define	PROCESS_H



#endif	/* PROCESS_H */
#include<iostream>
using namespace std;

//dichiarazione funzioni
void ViewProc(string);//visualizza i processi sul server
void KillProc(string);//elimina processi
void Exec(string);//crea processi

void ViewProc(string cmd){

     int num_proc=0,fine;
     char Process[60];
     send(cl_sk,cmd.c_str(),cmd.size(),0);
     recv(cl_sk,Process,strlen(Process),0),
     num_proc=atoi(Process);

     if(num_proc==0){cout<<"ERRORE nel conteggio dei processi"<<endl<<endl;return;}
     for(int i=0;i<num_proc;i++){

          fine=recv(cl_sk,Process,60,0);
          Process[fine]='\0';
          send(cl_sk,"0",1,0);
          cout<<Process<<endl;

     }

     cout<<endl;
     return;

}

void KillProc(string cmd){
     char a;
     send(cl_sk,cmd.c_str(),cmd.size(),0);
     recv(cl_sk,&a,1,0);
     if(a=='0')cout<<"Processo terminato correttamente"<<endl<<endl;
     else cout<<"Pid non corretto"<<endl<<endl;
     return ;

}


void Exec(string cmd){
     char icmp[50];
     send(cl_sk,cmd.c_str(),cmd.size(),0);
     int fine=recv(cl_sk,icmp,50,0);
     icmp[fine]='\0';
     cout<<icmp<<endl<<endl;
     return;

}