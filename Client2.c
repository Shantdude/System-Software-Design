#include"stdio.h"
#include"string.h"
#include"sys/socket.h"
#include"netinet.h"
struct student
{
    int roll;
    char name[20];
    char branch[10];
};
main()
{

        int sid,status,len;

        char temp[5];                   //used later

        struct student x;               //student struct

        struct sockaddr_in q;           //socket struct

        len=sizeof(struct sockaddr_in );//size of socket structure

        sid=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);

                q.sin_family=PF_INET;

                q.sin_port=1500;        //any port number between 1023-65535

                q.sin_addr.s_addr=0;

        status=connect(sid,&q,len);     //pass sid, q, and len

        if(status==-1)
        {
                printf("Connection failure");
                return 0;
        }
        while(1)
        {
                printf("Enter name\n");
                scanf("%s",x.name);
                printf("Enter roll\n");
                scanf("%d",&x.roll);
                printf("Enter branch");
                scanf("%s",x.branch);

                write(sid,&x,sizeof(struct student));

                printf("You want to continue?\n");
                scanf("%s",x);
                if(strcmp(x,"no"))
                {
                        x.roll=-1;
                        write(sid,&x,sizeof(struct student));
                }
        }
}
