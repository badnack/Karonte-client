/* 
 * File:   Connect.h
 * Author: redo86
 *
 * Created on 3 luglio 2010, 17.00
 */
#ifndef CONNECT_H
#define	CONNECT_H
#endif	/* CONNECT_H */
#include <curl/curl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#ifdef WIN32
#include <io.h>
#else
#include <unistd.h>
#endif
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdlib>

using namespace std;



#define LOCAL_FILE      "callme"
#define UPLOAD_FILE_AS  "callme"
#define REMOTE_URL      "ftp://<server to host callme>"  UPLOAD_FILE_AS
#define RENAME_FILE_TO  "callme"
#define SA struct sockaddr
#define BACKLOG_SIZE 5

#define EXENAME "clientkaronte"
string IpNew;
u_short SRV_PORT=2222;

//dichiarazione funzioni
int writer(char *data, size_t size, size_t nmemb, string *buffer);
static size_t readFile(void *ptr, size_t size, size_t nmemb, void *stream);
int uploadCallme(void);
int connectServer(void);
string GetIp(const string &url);
void GetOwnIp(void);
bool ContrIp(void);


static size_t readFile(void *ptr, size_t size, size_t nmemb, void *stream)
{

  size_t retcode = fread((char*)ptr, size, nmemb, (FILE*)stream);
  return retcode;
}

int uploadCallme()
{
  CURL *curl;
  CURLcode res;
  FILE *hd_src;
  struct stat file_info;
  curl_off_t fsize;

  struct curl_slist *headerlist=NULL;
  static const char buf_1 [] = "RNFR " UPLOAD_FILE_AS;
  static const char buf_2 [] = "RNTO " RENAME_FILE_TO;

  fsize = (curl_off_t)file_info.st_size;

  

  /* get a FILE * of the same file */
  hd_src = fopen(LOCAL_FILE, "rb");

  /* In windows, this will init the winsock stuff */
  curl_global_init(CURL_GLOBAL_ALL);

  /* get a curl handle */
  curl = curl_easy_init();
  if(curl) {

    headerlist = curl_slist_append(headerlist, buf_1);
    headerlist = curl_slist_append(headerlist, buf_2);
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, readFile);
    
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
    curl_easy_setopt(curl,CURLOPT_URL, REMOTE_URL);
    curl_easy_setopt(curl, CURLOPT_POSTQUOTE, headerlist);
    curl_easy_setopt(curl, CURLOPT_READDATA, hd_src);
    curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE,(curl_off_t)fsize);

    /* Now run off and do what you've been told! */
    res = curl_easy_perform(curl);

    /* clean up the FTP commands list */
    curl_slist_free_all (headerlist);

    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  fclose(hd_src); /* close the local file */
  curl_global_cleanup();
  system("rm callme");
  return 0;

}

int connectServer()
{
    int ret, len;
    

    int optval;
    struct sockaddr_in my_addr, cl_addr;
    char cl_paddr[INET_ADDRSTRLEN];
    uint16_t cl_port;

    unsigned int msg_len;


    /* create a new socket */
    sk = socket(AF_INET, SOCK_STREAM, 0);
    if(sk == -1){
        cout<<"KARONTE: Can't crete a new socket\n";
        exit(1);
    }

    /* reuse a TIME_WAIT socket */
    optval = 1;
    ret = setsockopt(sk, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
    if(ret == -1){
        cout<<"KARONTE: Error on setting SO_REUSEADDR\n";
        exit (1);
    }

    /* bind it to all available IP addresses and a to SRV_PORT */
    memset(&my_addr, 0, sizeof(my_addr)); /* blank with 0 */
    my_addr.sin_family = AF_INET; /* IPv4 address */
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY); /* all addresses */
    my_addr.sin_port = htons(SRV_PORT); /* SRV_PORT, network order */

    ret = bind(sk, (SA *) &my_addr, sizeof(my_addr));
    if(ret == -1){
        cout<<"KARONTE: Impossibile fare il bind del socket\n"<<endl;
        cout<<"Provare a terminare gli altri processi Client Karonte?[s/n]: ";
        char c=mygetch();
        string exec="killall ";
        exec+=EXENAME;
        if(c=='s'){cout<<endl<<"Ora puoi riavviare Karonte Client";system(exec.c_str());}//altri client attaccati, li scollego
        else
         exit (1);
    }

    /* create the backlog queue */
    ret = listen(sk, BACKLOG_SIZE);
    if(ret == -1){
        cout<<"KARONTE: Can't create a" <<BACKLOG_SIZE<<"long backlog queue\n",
        exit (1);
    }
        /* accept incoming request on sk */
        len = sizeof(cl_addr);
       cout<<"OK"<<endl<<endl<<" * Karonte in attesa di connessioni remote [Porta "<<SRV_PORT<<"] ..."<<endl;

       if(Iphone)system("<Push notify> \'Karonte:\' \'Finally i am ready!!!\'");

       cl_sk = accept(sk, (SA *) &cl_addr,(socklen_t*) &len);
        if(cl_sk == -1){
            cout<<"SERVER: Error while waiting for connections"<<endl;
            exit (1);
        }
        inet_ntop(AF_INET, &cl_addr.sin_addr, cl_paddr, sizeof(cl_paddr));
        cl_port = ntohs(cl_addr.sin_port);

}

//ricava l'indirizzo ip
string GetIp(const string &url)
{
    string buffer;

    CURL *curl;
    CURLcode result;

    curl = curl_easy_init();

    if (curl)
    {
      curl_easy_setopt(curl, CURLOPT_URL, url.c_str()  );
      curl_easy_setopt(curl, CURLOPT_HEADER, 0);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

      result = curl_easy_perform(curl);//http get performed

      curl_easy_cleanup(curl);//must cleanup

      //error codes: http://curl.haxx.se/libcurl/c/libcurl-errors.html
      if (result == CURLE_OK){
          return buffer;
      }
      //curl_easy_strerror was added in libcurl 7.12.0
      cerr << "ERRORE: caricare a mano l'ip su server KARONTE... " << result << " " << curl_easy_strerror(result) <<endl;
      return "";
    }

    cerr << "ERRORE: impossibile inizializzare Curl, caricare a mano l'ip su server KARONTE..." << endl;
    return "";
}

int writer(char *data, size_t size, size_t nmemb, string *buffer)
{
  int result = 0;
  if (buffer != NULL)
  {
      buffer->append(data, size * nmemb);
      result = size * nmemb;
  }
  return result;
}

//ricava l'inidirizzo ip e lo mette in una stringa
void GetOwnIp()
{    
    IpNew=GetIp("<sito con script ip>");
    if(IpNew.length()==0){
        cout<<endl<<"Impossibile ricavare un indirizzo Ip valido. Indicare il proprio IP: ";
        cin>>IpNew;
    }
    cout<<"OK"<<endl<<"   Indirizzo IP attuale: "<<IpNew;
    FILE *fp;
    fp=fopen("callme","wb");
    fprintf(fp,"%s",IpNew.c_str());
    fclose(fp);

}


bool ContrIp(){
    string OldIp=GetIp("<Sito callme>");

    if(OldIp==IpNew){cout<<endl<<" * Ip ostato corretto... ";return false;}
    return true;

}
