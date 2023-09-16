#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    int instance[5],count,sequence[5],safe,s=0,j,completed,i;
    int avaliable[5],allocation[10][5],max[10][5];
    int need[10][5],process,P[10],countofr,countofp,running[10];
    cout<<"\nEnter the number of resources (<=5): ";
    cin>>countofr;

    for(i=0;i<countofr;i++)
    {
        cout<<"\n enter the max instances of resource R["<<i<<"]:";
        cin>>instance[i];
        avaliable[i]=instance[i];
    }
    cout<<"\nEnter the number of processes (<=10):";
    cin>>countofp;
    cout<<"\n Enter the allocation matrix\n";

    for(i=0;i<countofp;i++)
    {
        cout<<"For The process P :p["<<i<<"]"<<endl;
        for(j=0;j<countofr;j++)
        {
            cout<<"allocation of resource R["<<j<<"] is :";
            cin>>allocation[i][j];
            avaliable[j]=allocation[i][j];
        }
    }
    cout<<"\n Enter the MAX matrix \n\n";

    for(i=0;i<countofp;i++)
    {
        cout<<"FOR THE PROCESS P["<<i<<"]"<<endl;
        for(j=0;j<countofr;j++)
        {
            cout<<"max diamond of resource R["<<j<<"] is :";
            cin>>max[i][j];
        }
    }

    cout<<"\n The given data are: \n";

    cout<<endl<<"\n Total resources in system:\n\n ";
    for(i=0;i<countofr;i++)
        cout<<"R["<<i<<"] ";
    cout<<endl;
    for(i=0;i<countofr;i++)
        cout<<"  "<<instance[i];

    cout<<"\n\n ALLOCATION matrix \n\n\t";
    for(j=0;j<countofr;j++)
        cout<<"R["<<j<<"] ";
    cout<<endl;

    for(i=0;i<countofp;i++)
    {
        cout<<"P["<<i<<"] ";
        for(j=0;j<countofr;j++)
        cout<<"  "<<allocation[i][j];
        cout<<endl;
    }

    cout<<"\n\nMAX matrix \n\n\t:";
    for(j=0;j<countofr;j++)
        cout<<"R["<<j<<"] ";
    cout<<endl;

    for(i=0;i<countofp;i++)
    { cout<<"P["<<i<<"] ";
    for(j=0;j<countofr;j++)
        cout<<"  "<<max[i][j];
    cout<<endl;
    }
    for(i=0;i<countofp;i++)
    {
        for(j=0;j<countofr;j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }

    cout<<"\n\n NEED matrix \n\n\t";
    for(j=0;j<countofr;j++)
        cout<<"R["<<j<<"] ";
    cout<<endl;

    for(i=0;i<countofp;i++)
    { cout<<"P["<<i<<"] ";
        for(j=0;j<countofr;j++)
            cout<<"  "<<need[i][j];
        cout<<endl;
    }
    cout<<"\n NOW to check whether above state is safe";
    cout<<"\n sequence in which above request can be fulfilled";
    cout<<"\n press any key to continue";
    getch();

    count= countofp;

    for(i=0;i<countofp;i++)
    { running[i]=1;}

    while(count)
    {
        safe=0;
        for(i=0;i<countofp;i++)
        {
            if(running[i])
            { completed=1;
            for(j=0;j<countofr;j++)
            {
                if(need[i][j]>avaliable[j])
                {
                    completed=0;
                    break;
                }
            }
            if(completed)
            {
                running[i]=0;
                count--;
                safe=1;
                for(j=0;j<countofr;j++)
                {
                    avaliable[i]+=allocation[i][j];
                }
                sequence[s++]=i;
                cout<<"\n\n Running process P["<<i<<"] ";
                cout<<endl<<"\n\n Total resources now available:\n\n";
                for(i=0;i<countofr;i++)
                    cout<<"R["<<i<<"] ";
                    cout<<endl;
                    for(i=0;i<countofr;i++)
                        cout<<"  "<<avaliable[i];
                    break;
            }
            }

        }
        if(!safe)
            break;
    }

    if(safe)
    {
        cout<<"\n the system is in safe state";
        cout<<"\n Safe sequence is";
        for(i=0;i<countofp;i++)
        {
            cout<<"\t"<<"P["<<sequence[i]<<"] ";
        }
    }
    else
    {
        cout<<"\nThe system is in unsafe state";
    }
    getch();
}
