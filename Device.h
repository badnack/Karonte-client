/* 
 * File:   Device.h
 * Author: redo86
 *
 * Created on 4 luglio 2010, 15.08
 */

#ifndef DEVICE_H
#define	DEVICE_H



#endif	/* DEVICE_H */
#include<iostream>
using namespace std;

void GetDevice(string);//stampa una lista dei device presenti sul server
void OpenCD(string);//apre il cassetto dei cd
void CloseCD(string);//chiude il cassetto dei cd

void GetDevice(string cmd){
     char a[255];
     send(cl_sk,cmd.c_str(),cmd.size(),0);
     int fine=recv(cl_sk,a,255,0);
     a[fine]='\0';
     if(strcmp(a,"0")==0){cout<<"Errore in lettura dei device"<<endl<<endl;return;}
     else
     cout<<endl<<"<Dev>     <Type>\t     <Label>"<<endl<<endl;
     cout<<a<<endl;
     return;

}

/*void Mv_Mouse(string cmd){

     bool Left=false;
     bool Right=false;
//     POINT mPoint;
     char xc[11],yc[5],c=0;
     int x,y,fine=0;
     send(cl_sk,cmd.c_str(),cmd.size(),0);
     if(cmd[4]=='a'){

             while(1){    



                              if(GetAsyncKeyState(VK_ESCAPE))break;

                              else if(GetAsyncKeyState(MK_LBUTTON)){send(sock,"KLdown",6,0);Left=true;}
                              else if(Left==true){send(sock,"KLup",4,0);Left=false;}

                              else if(GetAsyncKeyState(MK_RBUTTON)){send(sock,"KRdown",6,0);Right=true;}
                              else if(Right==true){send(sock,"KRup",4,0);Right=false;}

                              Sleep(50);

                              GetCursorPos(&mPoint);
                              x=mPoint.x;
                              y=mPoint.y;
							  SecureZeroMemory(xc,11);
							  SecureZeroMemory(yc,5);
							  _itoa_s(x,xc,11,10);
                              _itoa_s(y,yc,5,10);
                              strcat_s(xc,11," ");
                              strcat_s(xc,11,yc);
                              send(sock,xc,strlen(xc),0);
                              recv(sock,xc,3,0);
//

             }

             send(sock,"end",3,0);
             cout<<"Non umiliare cosi Karonte "<<char(1)<<endl<<endl;
             Sleep(1000);
             recv(sock,xc,3,0);
             //FlushFileBuffers((HANDLE)sock);

     }

     return;

}*/

void OpenCD(string cmd){

     char a;
     send(cl_sk,cmd.c_str(),cmd.size(),0);
     recv(cl_sk,&a,1,0);
     if(a=='0')
     cout<<"Cassetto cd aperto"<<endl<<endl;
     else
     cout<<"Errore nella apertura del cassetto"<<endl<<endl;
     return;

}

void CloseCD(string cmd){

     char a;
     send(cl_sk,cmd.c_str(),cmd.size(),0);
     recv(cl_sk,&a,1,0);
     if(a=='0')
     cout<<"Cassetto cd chiuso"<<endl<<endl;
     else
     cout<<"Errore nella chiusura del cassetto"<<endl<<endl;
     return;

}