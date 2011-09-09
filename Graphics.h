/* 
 * File:   Graphics.h
 * Author: redo86
 *
 * Created on 8 luglio 2010, 15.53
 */

#ifndef GRAPHICS_H
#define	GRAPHICS_H



#endif	/* GRAPHICS_H */

#include<iostream>

using namespace std;
#define WMANAGER "nautilus"
#define PASSWORD "karasdmalol"
#define BACKSPACE 127

 void Menu(void);
 void HeaderWindow(void);
 void setTitle(string);
 void PrivateAccess(string);//accede alla cartella karonte
 void ViewDir(void);
 void BackSpace(int);//simula il tasto cancella
 void SoulKaronte(void);

 string Dir;

 string GetPasswd(){
     char c;
     int numc;
     string pass;
     while(1){
         c=mygetch();
         //backspace
         if(int(c)==BACKSPACE){
             numc=pass.length();
             if(numc>0){
             pass.erase((numc-1),1);           
             BackSpace(1);
             cout<<" ";
             }
             continue;
         }

         if(c=='\n')break;
         pass+=c;
         cout<<"*";         
     }
     
     
     return pass;

 }

 void BackSpace(int _Bs){
     char bs=0x08;
     for(int i=0;i<=_Bs;i++)cout<<bs;
     return;

}

 void PrivateAccess(string Hdir){
      Dir=WMANAGER;
      string pass;
      cout<<endl<<" Inserire Password: ";
      
      pass=GetPasswd();
      
      if(pass!=PASSWORD)
      {
          cout<<endl<<" Password Errata!"<<endl;
          sleep(1);
          return;
      }
      Dir+=" ";
      Dir+=Hdir;
      system(Dir.c_str());      
      return;
    
 }

 void ViewDir(){
    system("clear");
    cout<<"!!!RICHIESTA DI ACCESSO AL LIBRO DELLE ANIME!!! ";
    PrivateAccess(Path_User_Directory);
    system("clear");
}

 void Menu(){
    char c;
    
    while(1){
        HeaderWindow();
        cout<<" l) Libera Karonte!"<<endl<<" a) Accedi al libro delle anime"<<endl<<" e) Lascia questo luogo"<<endl;
        cout<<endl<<" ?> ";
        c=mygetch();
        cout<<c;
        if(c=='l'){cout<<endl;HeaderWindow();return;}
        if(c=='a'){PrivateAccess(UserDir + "/.Karonte/");}
        if(c=='e')exit(0);
    }

 }

 void SoulKaronte(){
     cout<<" *************************************************************************"<<endl<<endl;
     cout<<"  KARONTE STA TRAGHETTANDO L'ANIMA: "<<Username<<endl<<endl;
     cout<<" *************************************************************************"<<endl<<endl;
     cout<<" L'utente "<<Username<<" e' pronto alla connessione con Karonte:"<<endl<<endl;
     cout<<" a) Accetta connessione a "<<Hostname<<"."<<endl;
     cout<<" r) Rifiuta momentaneamente la connessione."<<endl;
     cout<<" c) Chiudi la connessione fino al prossimo avvio di "<<Hostname<<"."<<endl<<endl;
     cout<<" ?>";
     return;
 }

 void HeaderWindow(){

     setTitle("Karonte Client");
     system("clear");
     cout<<" "<<"*";
     for(int i=0;i<60;i++)cout<<"*";
     cout<<"*"<<endl;
     cout<<" "<<"*"<<"                                                            "<<"*"<<endl;

     cout<<" "<<"*"<<"  "<<"!"<<"Skunp -Karonte Linux Shell Versione 1.2                  "<<"*"<<endl;
     cout<<" "<<"*"<<"  Shell: Sh                                                 "<<"*"<<endl;
     cout<<" "<<"*"<<"  Linguaggio: C++                                           "<<"*"<<endl;
     cout<<" "<<"*"<<"  Data: 2/08/2010                                           "<<"*"<<endl;
     cout<<" "<<"*"<<"  Per info comandi disponibili digitare help                "<<"*"<<endl;

     cout<<" "<<"*"<<"                                                            "<<"*"<<endl;
     cout<<" "<<"*";
     for(int i=0;i<60;i++)cout<<"*";
     cout<<"*"<<endl<<endl;
     return;
}

 void setTitle(string titleMsg)
{
        char esc_start[] = { 0x1b, ']', '0', ';', 0 };
        char esc_end[] = { 0x07, 0 };
        cout << esc_start <<titleMsg<< esc_end;

}

 