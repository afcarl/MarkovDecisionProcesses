#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<bits/stdc++.h>

#define SET(a,b) memset(a,b,sizeof(a))
#define scan(n) scanf("%d",&n)
#define print(n) printf("%d\n",n)
#define scanl(n) scanf("%lld",&n)
#define printl(n) printf("%lld\n",n)

using namespace std;

int main()
{
       float ar[10][10],prev[10][10];
       int dir[10][10];
       int i,j,k;
       for(i=0;i<10;i++)
       {
              for(j=0;j<10;j++)
              {
                     prev[i][j]=0.0;
                     ar[i][j]=0.0;
                     dir[i][j]=0;
              }
       }
       float team_val;
       team_val = 8.0;
       ar[1][1]=-team_val;
       ar[0][2]=team_val;
       prev[1][1]=-team_val;
       prev[0][2]=team_val;
       float delta,maxdif=100.0;
       delta=team_val*(1.0/20);	
       for(i=0;i<3;i++)
       {
              for(j=0;j<4;j++)
                     printf("%f ",ar[i][j]);
              printf("\n");
       }
       printf("-----------\n");

       while(maxdif>=delta)
       {
              maxdif=0;
              for(i=0;i<3;i++)
              {
                     for(j=0;j<4;j++)
                     {
                            if(i==0 && j==2 || i==1 && j==1 || i==1 && j==2);
                            else
                            {
                                   float val;
                                   float valeast,valwest,valnorth,valsouth,unitcost=-team_val/20.0;
                                   int x[4][2];
                                   x[0][0]=i;
                                   x[0][1]=j+1;
                                   x[1][0]=i;
                                   x[1][1]=j-1;
                                   x[2][0]=i-1;
                                   x[2][1]=j;
                                   x[3][0]=i+1;
                                   x[3][1]=j;

                                   int k;
                                   for(k=0;k<4;k++)
                                   {
                                          if(x[k][0]<0 || x[k][0]>2 || x[k][1]<0 || x[k][1]>3 || x[k][0]==1 && x[k][1]==2)
                                          {
                                                 x[k][0]=i;
                                                 x[k][1]=j;
                                          }
                                   }

                                   valeast=unitcost+ 0.8*prev[x[0][0]][x[0][1]]+ 0.1*prev[x[2][0]][x[2][1]]+ 0.1*prev[x[3][0]][x[3][1]];
                                   val=valeast;
                                   dir[i][j]=4;

                                   valwest=unitcost+ 0.8*prev[x[1][0]][x[1][1]]+ 0.1*prev[x[2][0]][x[2][1]]+ 0.1*prev[x[3][0]][x[3][1]];
                                   if(valwest>val){
                                          val=valwest;
                                          dir[i][j]=3;
                                   }

                                   valnorth=unitcost+ 0.8*prev[x[2][0]][x[2][1]]+ 0.1*prev[x[0][0]][x[0][1]]+ 0.1*prev[x[1][0]][x[1][1]];
                                   if(valnorth>val){
                                          val=valnorth;
                                          dir[i][j]=1;
                                   }

                                   valsouth=unitcost+ 0.8*prev[x[3][0]][x[3][1]]+ 0.1*prev[x[0][0]][x[0][1]]+ 0.1*prev[x[1][0]][x[1][1]];
                                   if(valsouth>val){
                                          val=valsouth;
                                          dir[i][j]=2;
                                   }

                                   if(val-ar[i][j]>maxdif)
                                          maxdif=val-ar[i][j];

                                   ar[i][j]=val;

                            }
                     }
              }
              for(i=0;i<3;i++)
              {
                     for(j=0;j<4;j++)
                     {
                            prev[i][j]=ar[i][j];
                            printf("%f ",ar[i][j]);
                     }
                     printf("\n");
              }
              printf("--------------\n");
       }
       printf("--------------\n");
       printf("--------------\n");
       printf("The Final Expected Reward is %f\n", ar[2][0]);
       int starti = 2;
       int startj = 0;
       while(starti>=0 && starti<=2 && startj>=0 && startj<=3){
             printf("--------------\n");
             cout << "Current State: " << starti << " " << startj << endl;
             string direction = "";
             if(dir[starti][startj]==1)
                 direction = "Above";
             if(dir[starti][startj]==2)
                 direction = "Below";
             if(dir[starti][startj]==3)
                 direction = "Left";
             if(dir[starti][startj]==4)
                 direction = "Right";
             if(dir[starti][startj]==1)
                 starti-=1;
             else if(dir[starti][startj]==2)
                 starti+=1;
             else if(dir[starti][startj]==3)
                 startj-=1;
             else if(dir[starti][startj]==4)
                 startj+=1;
             else
                 break;
             cout << "Action to take: " << direction << endl;
       }
       return 0;
}       
