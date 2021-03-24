//first come first serve//
#include"iostream"
using namespace std;

void findwt(int pid[],int n,int bt[],int wt[])
{
  wt[0]=0;//first process will not wait

  for(int i=1;i<n;i++)
  {
    wt[i]=wt[i-1]+bt[i-1];//waiting time=waiting time og prev process + burst time of prev proceess
  }
}

void findtat(int pid[],int n,int bt[],int wt[],int tat[])
{
  for(int i=0;i<n;i++)
  {
    tat[i]=wt[i]+bt[i];//turn arround=waiting+burst
  }
}

void averageWTandTAT(int pid[],int n,int bt[])
{
  int wt[n];//weighting time array
  int totalwt=0;
  int tat[n];//turn arround time array
  int totaltat=0;

  findwt(pid,n,bt,wt);//to create array of waiting time

  findtat(pid,n,bt,wt,tat);//to create array of turnarround time

  for(int i=0;i<n;i++)
  {
    totalwt+=wt[i];//total waiting time
    totaltat+=tat[i];//total turn arround time
  }

  cout<<"Average waiting time is: "<< (totalwt/(float)n)<<endl;
  cout<<"Average turn arround time is:"<<(totaltat/(float)n)<<endl;
}

main()
{
  int pid[]={1,2,3,4,5};//array of processID
  int noOfProcesses=5;
  int bt[]={10,4,8,6,5};//burst time

  averageWTandTAT(pid,noOfProcesses,bt);//average waiting time

  return 0;
}
