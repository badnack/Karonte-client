
/*
 * File:   File.h
 * Author: redo86
 *
 * Created on 3 luglio 2010, 20.54
 */

#ifndef FILE_H
#define	FILE_H
#endif	/* FILE_H */

#include<iostream>
using namespace std;

#define SIZE 30
#define NAME_SIZE MAX_PATH+20
#define BUFF4K 4096
#define SIZECP 50

//definizioni funzioni
void Percentuale(double,double);//calcola percentuali
void CopyRemoteFile(string);//copia un singolo file da server al client
void CopyFiles(string);//seleziona piu file, uno per uno, del server e richiama la CopyRemoteFile
void Touch(string);//crea un file sul server
void DelFile(string);//cancella un file sul server
void Find(string);//trova file sul server
int FileSize(string);//calcola il file size
void SendRemoteFile(string);//mando un file al server
int copyLocalFile(string,string);//copio un file locale, in locale
int CopyRemoteFileDir(void);



void Percentuale(double file_size,double fs){

     BackSpace(4);
     double div=1-(file_size/fs);
     div=div*100;
     cout<<int(div)<<"%";
     return;

}

void CopyRemoteFile(string cmd){

     char size[NAME_SIZE];
     char buffer[MAX_PATH];
     long int file_size=0,fs=0;
     int fine;
     int dwbr;
     fine=recv(cl_sk,size,NAME_SIZE,0);
     size[fine]='\0';
     file_size=atoi(size);
     fs=file_size;
     if(file_size<=0){cout<<"Il file non esiste, e\' vuoto o in esecuzione"<<endl<<endl;return;}
     FILE *fp;
     fp=fopen(cmd.c_str(),"wb");

     while (1){
           dwbr=recv(cl_sk,buffer,MAX_PATH,0);
           fwrite (buffer , 1 , dwbr , fp );
           Percentuale(file_size,fs);
           file_size-=dwbr;
           if(file_size<=0)break;

     }

     BackSpace(4);
     cout<<"100%   Trasferimento "<<cmd<<" completato"<<endl<<endl;
     fclose(fp);
     return;

}

int CopyRemoteFileDir(){

     char size[NAME_SIZE];
     char buffer[MAX_PATH];
     long int file_size=0,fs=0;
     int fine;
     int dwbr;
     char* siz;
     char* name;
     fine=recv(cl_sk,size,NAME_SIZE,0); //ricevo nome e lunghezza file
     size[fine]='\0';
     
     
     if(!strcmp(size,"ENDOFFRAME"))return 1;

     name=strtok(size,"////");//separo
     siz=strtok(NULL,"////");
     file_size=atoi(siz);
     
     fs=file_size;
     if(file_size<=0){cout<<"Il file non esiste, e\' vuoto o in esecuzione"<<endl<<endl<<siz;return 0;}
     FILE *fp;
     fp=fopen(name,"wb");
     send(cl_sk,"o",1,0);
     while (1){
           dwbr=recv(cl_sk,buffer,MAX_PATH,0);
           fwrite (buffer , 1 , dwbr , fp );
           Percentuale(file_size,fs);
           file_size-=dwbr;
           if(file_size<=0)break;

     }

     BackSpace(4);
     cout<<"100%   Trasferimento "<<name<<" completato"<<endl<<endl;
     fclose(fp);
     return 0;

}

void CopyFiles(string cmd){


	if(cmd[0] == '-' && cmd[1] == 'r' && cmd[2] == ' '){

		char Nome_file[MAX_PATH];
		int fine=0;
                //controllo se posso accedere alla cartelle
		fine=recv(cl_sk,Nome_file,10,0);
		Nome_file[fine]='\0';
                
		string Access=Nome_file;
                
		if(Access=="NOACCESS"){

			cout<<"Accesso negato alla cartella indicata"<<endl<<endl;
			return;

		}

		string Cp_Directory=&cmd[3];
                size_t posfile;
                string nfile;
                
                posfile=Cp_Directory.find(" -f ");
                if (posfile!=string::npos) //se esiste un -f
                {

                   nfile=Cp_Directory.substr (posfile+4,Cp_Directory.length());
                   Cp_Directory=Cp_Directory.substr(0,posfile);
                   //if non esiste directory
			  
		   
                }

                mkdir(Cp_Directory.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		chdir(Cp_Directory.c_str());

		while(1){
			if(CopyRemoteFileDir())break;
                        send(cl_sk," ",1,0);//NUOVA


		}

		chdir("..");

	}


        else CopyRemoteFile(cmd);

	return;


}

void Touch(string cmd){
	char a;
	send(cl_sk,cmd.c_str(),cmd.size(),0);
        recv(cl_sk,&a,1,0);

	if(a=='1')cout<<"File creato con successo"<<endl<<endl;

	else cout<<"Si e' verificato un errore o era gia' presente un file con il nome indicato"<<endl<<endl;

	return;

}

void DelFile(string cmd){
     char a;
     send(cl_sk,cmd.c_str(),cmd.size(),0);
     recv(cl_sk,&a,1,0);
     if(a=='1')cout<<"File eliminato con successo"<<endl<<endl;
     else cout<<"File non esistente o in uso da qualche applicazione"<<endl<<endl;
     return;

}

void Find(string cmd){

     int fine;
     char size[SIZE],*buffer;;
     long int file_size=0;
     send(cl_sk,cmd.c_str(),cmd.size(),0);
     cout<<endl<<"Attendere prego...";
     if(cmd[5]=='-'){

         
         fine = recv(cl_sk,size,SIZE,0);
         size[fine] = '\0';
         file_size=atoi(size);
         if(file_size<=0){BackSpace(15);cout<<"Si e\' verificato un errore"<<endl<<endl;return;}
         int dwbr=0;
         buffer = new char [MAX_PATH];
         BackSpace(15);
         FILE *hFile=fopen("Find.txt","wb");
         cout<<"Find terminata,attendere ricezione file";

          while (1){
           dwbr=recv(cl_sk,buffer,MAX_PATH,0);
           fwrite (buffer , 1 , dwbr , hFile );
           file_size-=dwbr;
           if(file_size<=0)break;

          }

     BackSpace(38);
     cout<<"Operazione completata,i risultati sono nel file Find.txt della cartella corrente"<<endl<<endl;
     fclose(hFile);
     return;

     }

     cout<<endl;
     char cre;
     buffer=new char [4096];

     while(1){

           fine=recv(cl_sk,buffer,4096,0);
           buffer[fine]='\0';
           cout<<buffer;
           if(buffer[strlen(buffer)-1]=='\n' && buffer[strlen(buffer)-2]=='\n'){;delete[]buffer;return;}
           cre=getchar();
           send(cl_sk,&cre,1,0);

     }

}

int FileSize(string filename){
     struct stat file_info;
     if(!stat(filename.c_str(),&file_info))
     return file_info.st_size;
     return -1;
}



//copia un file residente in from, in to
int copyLocalFile(string from,string to){
    FILE *ffrom=fopen(from.c_str(),"rb");
    char buff[SIZECP];
    int ret=0;
    int filesize=FileSize(from);

    if(filesize==-1 || ffrom==NULL){

        if(ffrom!=NULL)fclose(ffrom);
        return -1;
    }

    FILE* fto=fopen(to.c_str(),"wb");
    if(fto==NULL)return -2;

    while(1){
        ret=fread(buff,1,SIZECP,ffrom);
        fwrite(buff,1,ret,fto);
        filesize-=ret;
        if(filesize<=0)break;
    }

    fclose(fto);
    fclose(ffrom);
    return 0;

}

int FileExists(string cmd){
     int file_size;
     file_size=FileSize(cmd);
     if(file_size<=0){cout<<"Il file non esiste nella directory corrente"<<endl<<endl;return 0;}
     return file_size;
}
//cmd contiene il nome del file
void SendRemoteFile(string cmd,int file_size){
     string size;
     char buff[BUFF4K];
     cout<<"Invio file in corso"<<endl;
     my_itoa(file_size,size,10);
     int len=size.length();
     send(cl_sk,size.c_str(),len,0);//mando la dimensione

     string app=cmd;
     FILE *fp=fopen(app.c_str(),"rb");

     recv(cl_sk,&size[0],2,0);

     int tosend=BUFF4K;
     while(1){
        if(file_size<BUFF4K)tosend=file_size;
				strcpy(buff,"");
				fread (buff,1,tosend,fp);
				send(cl_sk, buff,tosend,0);
				if(file_size<BUFF4K)break;
				file_size-=BUFF4K;

     }

     fclose(fp);
     recv(cl_sk,&size[0],2,0);
     cout<<"File inviato con successo"<<endl<<endl;
     return;

}
