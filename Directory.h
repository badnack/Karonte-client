/* 
 * File:   Directory.h
 * Author: redo86
 *
 * Created on 3 luglio 2010, 20.14
 */

#ifndef DIRECTORY_H
#define	DIRECTORY_H



#endif	/* DIRECTORY_H */

#include<iostream>
using namespace std;

//dichiarazione funzioni
void StampaDir(string); // stampa la directory corrente
void Cd(string);//naviga sul server
void MkDir(string);//crea una directory sul server
void RMDir(string);//rimuove una directory sul server

void StampaDir(string cmd){
     char cre,dati[4096];
     int fine;
     send(cl_sk,cmd.c_str(),cmd.size(),0);
     cout<<endl<<"< Tipo >\t< Nome >\t\t< Size >"<<endl;
     while(1){

          fine=recv(cl_sk,dati,4096,0);
          dati[fine]='\0';
          cout<<dati;
          if(dati[strlen(dati)-1]=='\n' && dati[strlen(dati)-2]=='\n')return;
          cout<<endl<<"Premere ENTER per continuare..."<<endl;
          cre=getchar();
          send(cl_sk,&cre,1,0);

     }

     cout<<endl;
	 return;

}

void Cd(string cmd){
     char path2[MAX_PATH];
     send(cl_sk,cmd.c_str(),cmd.size(),0);
     int fine=recv(cl_sk,path2,MAX_PATH,0);
     path2[fine]='\0';
     if(strcmp(path,path2)==0)cout<<"La cartella non esiste"<<endl<<endl;
     else strcpy(path,path2);
     return;

}

void MkDir(string cmd){
     char a;
     send(cl_sk,cmd.c_str(),cmd.size(),0);
     recv(cl_sk,&a,1,0);
     if(a=='0')cout<<"Si è verificato un errore o cartella gia\' esistente"<<endl<<endl;
     else cout<<"Cartella """<<&cmd[6]<<""" creata con successo"<<endl<<endl;
     return;

}

void RmDir(string cmd){
     char a;
     send(cl_sk,cmd.c_str(),cmd.size(),0);
     recv(cl_sk,&a,1,0);
     if(a=='0')cout<<"La cartella non esiste o non e\' vuota"<<endl<<endl;
     else cout<<"Cartella eliminata con successo"<<endl<<endl;
     return;

}