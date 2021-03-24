//Shortest jpb first (NON PREMTIVE)
#include"iostream"
using namespace std;

//create a metrix of [10][5]
int matrix[10][6];//global 2D array 
/*  user input
    matrix[i][0]=process id
    matrix[i][1]=Arrival time
    matrix[i][2]=Burst time 

    program to calculate
    matrix[i][3]=completion time
    matrix[i][4]=Trn arround time
    matrix[i][5]=waiting time
*/
//swap to cols of 2D array
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
//arrange matrix by ARRIVAL TIME
void arrangeByArrival(int m[][6],int n)//col is mandetory, row is not
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)     //as total n process not 10
        {
            if(m[j][1]>m[j+1][1])   //[j][1] as Arrival time is at [1]th col
            {
                for(int k=0;k<6;k++)
                {
                    swap(m[j][k],m[j+1][k]);//swap j and j+1 row with all of its col
                }
            }
        }
    }
}
//calculate total time, TAT, 
//process id | Arival time | Burst time |   CT      |   TAT     |     WT     |
// [][0]     |  [][1]      |    [][2]   |   [][3]   |   [][4]   |   [][5]    |
void waitingTime(int m[][6],int n)
{
    int temp,val;
    //first process will complete it's entire wrk as it is non premtive
    m[0][3]=m[0][1]+m[0][2];//CT
    m[0][4]=m[0][3]-m[0][1];//TAT
    m[0][5]=m[0][4]-m[0][2];//WT

    //from second process
    for(int i=1;i<n;i++)
    {
        temp=m[i-1][3];//store previous process's CT
        int low=m[i][2];//store current process's BT
        for(int j=i+1;j<n;j++)
        {
            if(temp>=m[j][1] && low>=m[j][2])
            {
                low=m[j][2];//store lowest BT
                val=j;//store "j" in "val"
            }
        }

        //find every process's CT,TAT,WT
        m[val][3]=temp+m[val][2];//we can't m[val][1]+m[val][2] bcz make sure CPU is not idle before bcz CT of previous process may be very less compare to AT of ncurr process
        m[val][4]=m[val][3]-m[val][1];//TAT
        m[val][5]=m[val][4]-m[val][2];//WT

        //swap row of i with row of val
        for(int k=0;k<6;k++)
        {
            swap(m[val][k],m[i][k]);
        }
    }
}
int main()
{
    int n;      //no of process
    cout<<"Enter total no of proceses"<<endl;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter Process id"<<endl;
        cin>>matrix[i][0];

        cout<<"Enter Arrival time"<<endl;
        cin>>matrix[i][1];

        cout<<"Enter Burst time"<<endl;
        cin>>matrix[i][2];
    }

    arrangeByArrival(matrix,n);
    waitingTime(matrix,n);
    cout<<"After SJF: "<<endl;
    cout<<"process id | Arival time | Burst time |   CT      |       TAT     |         WT     |"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<matrix[i][0]<<"\t\t"<<matrix[i][1]<<"\t\t"<<matrix[i][2]<<"\t\t"<<matrix[i][3]<<"\t\t"<<matrix[i][4]<<"\t\t"<<matrix[i][5]<<"\t\t"<<endl;          
    }
    return 0;
}