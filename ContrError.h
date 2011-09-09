/* 
 * File:   ContrError.h
 * Author: redo86
 *
 * Created on 13 luglio 2010, 17.43
 */

#ifndef CONTRERROR_H
#define	CONTRERROR_H



#endif	/* CONTRERROR_H */
#include<iostream>
using namespace std;
bool Check_Error(string);
bool contrCp(string);
bool ContrExec(string,int);

bool ContrExec(string cmd,int type){
    size_t pos;
    string test;
    pos=cmd.find(" -i");
    if(pos!=string::npos)//se esiste
    {
        //controllo che ci sia qualcosa dopo -r
        test=cmd.substr(pos,cmd.length());
        if(test.length()<=4){Man_Exec();return false;}
        //sistemare spazi
    }

    

    return true;
}

bool contrCp(string cmd){ //controllo parametri nella copy
    size_t pos;
    string test;
    pos=cmd.find(" -r");
    if(pos!=string::npos)//se esiste
    {
        //controllo che ci sia qualcosa dopo -r
        test=cmd.substr(pos,cmd.length());
        if(test.length()<=4){Man_Cp();return false;}
    }
    pos=cmd.find(" -f");
    if(pos!=string::npos)//se esiste
    {
        //controllo che ci sia qualcosa dopo -r
        test=cmd.substr(pos,cmd.length());
        if(test.length()<=4){Man_Cp();return false;}
    }

    return true;

}

bool Check_Error(string cmd){

   if(cmd[0]=='f' && cmd[1]=='i' && cmd[2]=='n' && cmd[3]=='d' && (cmd[4]==' ' || cmd[4]=='\0')){

           cout<<"Comando non correttamente implementato:"<<endl;
           Man_Find();
           cout<<endl;
           return true;

     }

     else if(cmd[0]=='m' && cmd[1]=='m' && cmd[2]==' '){

           cout<<"Comando non correttamente implementato:"<<endl;
           Man_Mm();
           cout<<endl;
           return true;

     }

     else if(cmd[0]=='s' && cmd[1]=='h' && cmd[2]=='u' && cmd[3]=='t' && cmd[4]=='d' && cmd[5]=='o' && cmd[6]=='w' && cmd[7]=='n' && (cmd[8]==' ' || cmd[8]=='\0')){

           cout<<"Comando non correttamente implementato:"<<endl;
           Man_Shutdown();
           cout<<endl;
           return true;

     }

     else if(cmd == "cd" || cmd=="cd ")
     {

           cout<<"Comando non correttamente implementato:"<<endl;
           Man_Cd();
           cout<<endl;
           return true;

     }

     else if(cmd == "kill" || cmd == "kill "){

           cout<<"Comando non correttamente implementato:"<<endl;
           Man_Kill();
           cout<<endl;
           return true;

     }

     else if(cmd == "exec" || cmd == "execb" || cmd == "exec " || cmd == "execb "){

           cout<<"Comando non correttamente implementato:"<<endl;
           Man_Exec();
           cout<<endl;
           return true;

     }

     else if(cmd=="cp" || cmd=="cp "){

           cout<<"Comando non correttamente implementato:"<<endl;
           Man_Cp();
           cout<<endl;
           return true;

     }

     else if(cmd=="msg" || cmd=="msg "){

           cout<<"Comando non correttamente implementato:"<<endl;
           Man_Msg();
           cout<<endl;
           return true;

     }

     else if(cmd=="sd" || cmd=="sd "){

           cout<<"Comando non correttamente implementato:"<<endl;
           Man_Sd();
           cout<<endl;
           return true;

     }

     else if(cmd=="rm" || cmd=="rm "){

           cout<<"Comando non correttamente implementato:"<<endl;
           Man_Rm();
           cout<<endl;
           return true;

     }

     else if(cmd=="mkdir" || cmd=="mkdir "){

           cout<<"Comando non correttamente implementato:"<<endl;
           Man_Mkdir();
           cout<<endl;
           return true;

     }

     else if(cmd=="rmdir" || cmd=="rmdir "){

           cout<<"Comando non correttamente implementato:"<<endl;
           Man_Rmdir();
           cout<<endl;
           return true;

     }
	/* else if (cmd=="viewcam"){

		send(sock,cmd.c_str(),7,0);
		cout<<"Attendere ricezione file"<<endl;
		RecieveFile("C:\\documents and settings\\redo86\\desktop\\CamShoot.bmp");


	 }
*/
     else if(cmd=="touch" || cmd=="touch "){

           cout<<"Comando non correttamente implementato:"<<endl;
           Man_Touch();
           cout<<endl;
           return true;
     }

     return false;

}