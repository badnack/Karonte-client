/* 
 * File:   Piano.h
 * Author: redo86
 *
 * Created on 5 luglio 2010, 1.50
 */

#ifndef PIANO_H
#define	PIANO_H
#endif	/* PIANO_H */

#include<iostream>
using namespace std;



//Dichiarazione funzioni

void Menu_Pianola(void);
int Cambial(void);
void Piano(string);




void Menu_Pianola(){

     system("clear");
     cout<<"IMPORTANTE: Lasciare passare un breve istante tra una nota e l'altra!"<<endl<<endl;
     cout<<" ";
     for(int i=0;i<26;i++)cout<<"*"<<" ";

     cout<<endl<<"   "<<"q"<<"   "<<"w"<<"   "<<"e"<<"   "<<"r"<<"   "<<"t"<<"   "<<"y"<<"   "<<"u"<<"   "<<"i"<<"   "<<"o"<<"   "<<"p";
     cout<<endl<<"     "<<"a"<<"   "<<"s"<<"   "<<"d"<<"   "<<"f"<<"   "<<"g"<<"   "<<"h"<<"   "<<"j"<<"   "<<"k"<<"   "<<"l";
     cout<<endl<<"          "<<"z"<<"   "<<"x"<<"   "<<"c"<<"   "<<"v"<<"   "<<"b"<<"   "<<"n"<<"   "<<"m";

     cout<<endl<<" ";
     for(int i=0;i<26;i++)cout<<"*"<<" ";

     for(int i=0;i<13;i++)cout<<endl;
     cout<<"                  "<<"Usa la tua tastiera come pianola (Versione Beta)  "<<"   ";
     cout<<endl<<endl<<endl<<"Premere: SPAZIO per cambiare la durata delle note   ";
     cout<<"-   ENTER per uscire"<<endl;
     return;

}

int Cambial(){

     system("clear");
     cout<<endl<<endl<<"Immettere una nuova lunghezza delle note "<<endl<<endl;
     cout<<"puoi inserire un valore compreso tra 0-2000 (il valore di default e\' 300): ";
     int lun;
     while(1){
          cin>>lun;
          if(lun>=0 && lun<=2000)break;
          cout<<endl<<"Valore errato riprova e sarai piu fortunato: ";
     }

     Menu_Pianola();
     return lun;

}




void Piano(string cmd){

     send(cl_sk,cmd.c_str(),cmd.size(),0);
     int lunghezza=300,a=1;
     int b_s=50,suono;
     char c;
     string buff,buff2;
     Menu_Pianola();
     
     while(1){
         c=0;
     
         tcflush(fileno(stdin), TCIFLUSH);
          switch(c=mygetch()){      
                case 'q': a=1;break;
                case 'w': a=2;break;
                case 'e': a=3;break;
                case 'r': a=4;break;
                case 't': a=5;break;
                case 'y': a=6;break;
                case 'u': a=7;break;
                case 'i': a=8;break;
                case 'o': a=9;break;
                case 'p': a=10;break;
                case 'a': a=11;break;
                case 's': a=12;break;
                case 'd': a=13;break;
                case 'f': a=14;break;
                case 'g': a=15;break;
                case 'h': a=16;break;
                case 'j': a=17;break;
                case 'k': a=18;break;
                case 'l': a=19;break;
                case 'z': a=20;break;
                case 'x': a=21;break;
                case 'c': a=22;break;
                case 'v': a=23;break;
                case 'b': a=24;break;
                case 'n': a=25;break;
                case 'm': a=26;break;
                case ' ': {a=1; lunghezza=Cambial();fflush(stdin);break;}
                case 10: {buff="2250 100";send(cl_sk,buff.c_str(),buff.length(),0);HeaderWindow();return;}
                default : a=1;break;

          }
          suono=b_s*a;
          buff="";
          my_itoa(suono,buff,10);          
          buff+=" ";
          my_itoa(lunghezza,buff2,10);
          buff+=buff2;
          //sleep(0.7);//forzo le send ad un ritmo accettabile
          send(cl_sk,buff.c_str(),buff.length(),0); 
          Menu_Pianola();
          
          Beep(buff);

     }
   
}


