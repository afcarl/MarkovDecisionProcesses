#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define SET(a,b) memset(a,b,sizeof(a))
#define scan(n) scanf("%d",&n)
#define print(n) printf("%d\n",n)
#define scanl(n) scanf("%lld",&n)
#define printl(n) printf("%lld\n",n)

int main()
{
       float ar[10][10],prev[10][10];
       int i,j,k;
       for(i=0;i<10;i++)
       {
              for(j=0;j<10;j++)
              {
                     prev[i][j]=0.0;
                     ar[i][j]=0.0;
              }
       }
       ar[1][1]=-9.0;
       ar[0][2]=9.0;
       prev[1][1]=-9.0;
       prev[0][2]=9.0;
       float delta,maxdif=100.0;
       delta=(float)9/20;	
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
                                   float valeast,valwest,valnorth,valsouth,unitcost=-9.0/20.0;
                                   int x[4][2];
                                   x[0][0]=i-1;
                                   x[0][1]=j;
                                   x[1][0]=i+1;
                                   x[1][1]=j;
                                   x[2][0]=i;
                                   x[2][1]=j+1;
                                   x[3][0]=i;
                                   x[3][1]=j-1;

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

                                   valwest=unitcost+ 0.8*prev[x[1][0]][x[1][1]]+ 0.1*prev[x[2][0]][x[2][1]]+ 0.1*prev[x[3][0]][x[3][1]];
                                   if(valwest>val)
                                          val=valwest;

                                   valnorth=unitcost+ 0.8*prev[x[2][0]][x[2][1]]+ 0.1*prev[x[0][0]][x[0][1]]+ 0.1*prev[x[1][0]][x[1][1]];
                                   if(valnorth>val)
                                          val=valnorth;

                                   valsouth=unitcost+ 0.8*prev[x[3][0]][x[3][1]]+ 0.1*prev[x[0][0]][x[0][1]]+ 0.1*prev[x[1][0]][x[1][1]];
                                   if(valsouth>val)
                                          val=valsouth;

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
       return 0;
}       
