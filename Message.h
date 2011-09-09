/* 
 * File:   Message.h
 * Author: redo86
 *
 * Created on 4 luglio 2010, 15.13
 */

#ifndef MESSAGE_H
#define	MESSAGE_H



#endif	/* MESSAGE_H */
#include<iostream>
using namespace std;

void SendHello(string cmd){

     char fuck;
     cout<<"Sei sicuro di volerlo fare?[Il server visualizzera\' una finestra windows] (S/N): ";

     while(1){

           fuck=getchar();
           cout<<endl;
           if(fuck=='s' || fuck=='S'){send(cl_sk,cmd.c_str(),5,0);return;}
           if(fuck=='n' || fuck=='N')return;
           cout<<"SE CE\' SCRITTO S/N UN POI PIGIA\' COSA TI PARE"<<endl;
           cout<<"RIPROVA (S/N): ";

     }

}