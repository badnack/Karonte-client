/* 
 * File:   Help.h
 * Author: redo86
 *
 * Created on 3 luglio 2010, 22.19
 */

#ifndef HELP_H
#define	HELP_H



#endif	/* HELP_H */

//Pagina con la spiegazione sui vari comandi
#include<iostream>
using namespace std;

void Man_Cd(){

      cout<<"cd [Percorso]                                 Cambia directory"<<endl;
      cout<<"   [..]                                       Direcory precendente"<<endl;
      cout<<"   [/]                                        Radice Disco"<<endl;
      cout<<"   [Path]                                     Percorso assoluto"<<endl;
      return;

}

void Man_CloseCD(){

     cout<<"closecd                                       Chiude il cassetto cd"<<endl;
     return;

}

void Man_Clear(){

     cout<<"clear                                         Ripulisce lo schermo"<<endl;
     return;

}

void Man_Color(){

     cout<<"color [Num/Lettera]                           Cambia il colore della finestra"<<endl;
     return;

}

void Man_Cp(){

     cout<<"cp [File]                                     Copia il file indicato"<<endl;
     cout<<"cp -r [Directory]                        Copia la directory indicata"<<endl;
     cout<<"cp -r [Directory] -f [File]    Copia la directory a partire dal file indicato"<<endl;
     return;

}

void Man_Cplog(){

     cout<<"cplog                                         Copia il file di log"<<endl;
     return;

}

//D
void Man_Destroy(){

     cout<<"cleanall                                       Cancella definitivamente il server"<<endl;
     return;

}

void Man_Device(){

     cout<<"device                                        Visualizza la lista dei device"<<endl;
     return;

}

//E
void Man_Exec(){

     cout<<"exec [[*]-i Iter][Comando][[*]Path/Url]       Esegue comando"<<endl;
     cout<<"execb [[*]-i Iter][Comando][[*]Path/Url]      Come sopra ma in background"<<endl;
     return;

}

//F
void Man_Find(){

     cout<<"find [File]				      Cerca un file nella directory corrente"<<endl;
     cout<<"     [-a] [File]			      Cerca anche in tutte le subdirectory"<<endl;
     return;

}

//H
void Man_Hello(){

     cout<<"hello                                         Visualizza You\'re been hacked by me"<<endl;
     return;

}

void Man_Help(){

     cout<<"help                                          Visualizza questo menu\'"<<endl;
     return;

}

//K
void Man_Kill(){

     cout<<"kill [Pid]                                    Termina il processo indicato dal pid"<<endl;
     return;

}

//l
void Man_Logout(){

     cout<<"logout                                        Chiusura client"<<endl;
     return;

}

void Man_Ls(){

     cout<<"ls                                            Mostra il contenuto della directory, la sigla N//S indica che il file (o la cartella) e\' nascosto o di sistema."<<endl;
     return;

}

//M
void Man_Man(){

     cout<<"man [Comando]                                 Manuale dei comandi"<<endl;
     return;

}

void Man_Mkdir(){

     cout<<"mkdir [Directory]                             Crea una directory"<<endl;
     return;

}

void Man_Mm(){

      cout<<"mm [[*]-i Iter]                               Mouve il mouse i volte"<<endl;
      cout<<"   [-a]                                       Prende il controllo del mouse"<<endl;
     return;

}

void Man_Msg(){

     cout<<"msg [Messaggio]                               Visualizza [messaggio] a schermo"<<endl;
     return;

}

void Man_Msn(){

     cout<<"msn                                           Ruba tutti i contatti di msn usati"<<endl;
     return;

}

//O
void Man_Opencd(){

     cout<<"openccd                                       Espelle il cassetto cd"<<endl;
     return;

}

void Man_Outdos(){

     cout<<"outdos                                        Chiusura server e client"<<endl;
     return;

}

//P
void Man_Pcinfo(){

     cout<<"pcinfo                                        Ricava le informazioni generali"<<endl;
     return;

}

void Man_Piano(){

     cout<<"piano                                         Puoi usare la tastiera come una pianola"<<endl;
     return;

}

//R
void Man_Rmdir(){

     cout<<"rmdir [Directory]                             Rimuove una directory"<<endl;
     return;

}

void Man_Rm(){

     cout<<"rm [File]                                     Rimuove un file"<<endl;
     return;

}

//S
void Man_Screen(){

     cout<<"screen                                        Visualizza screenshot"<<endl;
     return;

}

void Man_Sd(){

     cout<<"sd [File]                                     Invia il file indicato"<<endl;
     return;

}

void Man_Shutdown(){

     cout<<"shutdown [-h]                                 Shutdown"<<endl;
     cout<<"         [-l]                                 Logout"<<endl;
     cout<<"         [-r]                                 Reboot"<<endl;
     return;

}

//T
void Man_Top(){

     cout<<"top                                           Visualizza i task in esecuzione"<<endl;
     return;

}

void Man_Touch(){

     cout<<"touch [File]                                  Crea un file"<<endl;
     return;

}

//U
void Man_Upgrade(){

     cout<<"Upgrade                                       Aggiorna il server con una nuova versione"<<endl;
     return;

}

void View_Dir(){

    cout<<"Viewdir                                        Visualizza la directory del server in locale"<<endl;
    return;
}

void Help(){

      cout<<endl;

      Man_Cd();
      cout<<endl;
      Man_CloseCD();
      cout<<endl;
      Man_Clear();
      cout<<endl;
      Man_Color();
      cout<<endl;
      Man_Cp();
      cout<<endl;
      Man_Cplog();
      cout<<endl;
      Man_Destroy();
      cout<<endl;
      Man_Device();
      cout<<endl;
      Man_Exec();
      cout<<endl;
      Man_Find();
      cout<<endl;
      Man_Hello();
      cout<<endl;
      Man_Help();
      cout<<endl;
      Man_Kill();
      cout<<endl;
      Man_Logout();
      cout<<endl;
      Man_Ls();
      cout<<endl;
      Man_Man();
      cout<<endl;
      Man_Mkdir();
      cout<<endl;
      Man_Mm();
      cout<<endl;
      Man_Msg();
      cout<<endl;
      Man_Msn();
      cout<<endl;
      Man_Opencd();
      cout<<endl;
      Man_Outdos();
      cout<<endl;
      Man_Pcinfo();
      cout<<endl;
      Man_Piano();
      cout<<endl;
      Man_Rmdir();
      cout<<endl;
      View_Dir();
      cout<<endl;
      Man_Rm();
      cout<<endl;
      Man_Screen();
      cout<<endl;
      Man_Sd();
      cout<<endl;
      Man_Shutdown();
      cout<<endl;
      Man_Top();
      cout<<endl;
      Man_Touch();
      cout<<endl;
      Man_Upgrade();
      cout<<endl;
      
	  return;

}

void Man(string cmd){

     if(cmd=="cd")Man_Cd();
     else if(cmd=="closecd")Man_CloseCD();
     else if(cmd=="clear")Man_Clear();
     else if(cmd=="color")Man_Color();
     else if(cmd=="cp")Man_Cp();
     else if(cmd=="cplog")Man_Cplog();
     else if(cmd=="cleanall")Man_Destroy();
     else if(cmd=="device")Man_Device();
     else if(cmd=="exec")Man_Exec();
     else if(cmd=="find")Man_Find();
     else if(cmd=="hello")Man_Hello();
     else if(cmd=="help")Man_Help();
     else if(cmd=="kill")Man_Kill();
     else if(cmd=="logout")Man_Logout();
     else if(cmd=="ls")Man_Ls();
     else if(cmd=="man")Man_Man();
     else if(cmd=="mkdir")Man_Mkdir();
     else if(cmd=="mm")Man_Mm();
     else if(cmd=="msg")Man_Msg();
     else if(cmd=="msn")Man_Msn();
     else if(cmd=="viewdir")View_Dir();
     else if(cmd=="opencd")Man_Opencd();
     else if(cmd=="outdos")Man_Outdos();
     else if(cmd=="pcinfo")Man_Pcinfo();
     else if(cmd=="piano")Man_Piano();
     else if(cmd=="rmdir")Man_Rmdir();
     else if(cmd=="rm")Man_Rm();
     else if(cmd=="screen")Man_Screen();
     else if(cmd=="sd")Man_Sd();
     else if(cmd=="shutdown")Man_Shutdown();
     else if(cmd=="top")Man_Top();
     else if(cmd=="touch")Man_Touch();
     else if(cmd=="upgrade")Man_Upgrade();
     else cout<<"Comando non presente nel manuale Karonte"<<endl;
     cout<<endl;

     return;

}
