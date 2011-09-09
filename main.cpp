/*Sintassi: clientkaronte [Path directory principale] [porta] [yes/no]*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <signal.h>
using namespace std;

int sk,cl_sk;
string Path_User_Directory;//contiene il percorso dove verranno salvati i file prelevati dal server
bool Set;//variabile usata per prendere il percorso preferito in caso sia segnalato
bool Iphone;
#include "RedefinitionLinux.h"
//#include "Graphics.h"
#include "Connect.h"
#include "Init.h"
#include "CheckCmd.h"

int main(int argc, char *argv[]){
    string cmd;
    
    signal (SIGINT, InitCloseUser);
    signal (SIGTERM,InitCloseUser);

    Set=false;
    Iphone=false;
    //se sono indicate le opzioni
    if(argc>1)
    {
        Set=true;
        UserDir=argv[1];
        if(argc>=3)SRV_PORT=atoi(argv[2]);
        if(argc==4)        
            if(!(strcmp(argv[3],"yes")))Iphone=true;
    }
    
 
    
    InitKaronte();
         
    
        while(1){

              getline(cin,cmd, '\n');

              if(!cmd.empty())Check(cmd);

              if(strlen(path)==0){cout<<"Connessione Persa"<<endl<<endl;break;}

              cout<<path<<">";

           }
    sleep(5);
       return 0;
}
