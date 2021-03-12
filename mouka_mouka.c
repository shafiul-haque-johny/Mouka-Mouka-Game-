#include <stdio.h>
#include <string.h>

struct player
{
    char name[50];
    char country[50];
    int run[3];
    int w[3];
    int point[3];
    int total_point;

};

int main()
{
    FILE *info;

    if ((info = fopen("player.txt","r")) == NULL)
    {
        printf("Error! opening file");
    }
    struct player p[5];
    int i,j;

    for(i=0; i<5; i++)
    {
        fscanf(info,"%s%s",p[i].name,p[i].country);

        for(j=0; j<3; j++)
        {
            fscanf(info,"%d", &p[i].run[j]);

            if(p[i].run[j] >= 25 && p[i].run[j]<50)
            {
                p[i].point[j] = 5;
            }
            else  if(p[i].run[j] >= 50 && p[i].run[j]<75)
            {
                p[i].point[j] = 10;
            }
            else  if(p[i].run[j] >= 75 && p[i].run[j]<100)
            {
                p[i].point[j] = 15;
            }
            else  if(p[i].run[j] >= 100)
            {
                p[i].point[j] = 20;
            }
            else
            {
                p[i].point[j] = 0;
            }
        }
        for(j=0; j<3; j++)
        {
            fscanf(info,"%d", &p[i].w[j]);

            p[i].point[j] = p[i].point[j]+(p[i].w[j]*12);
        }
        p[i].total_point = 0;

        for(j=0; j<3; j++)
        {
            p[i].total_point =  p[i].total_point + p[i].point[j];
        }
    }

    int max = -999;
    char manofthematch [3][50];
    char manoftheseries[50];

    for(i=0; i<3; i++)
    {
        max = -999;
        for(j=0; j<5; j++)
        {
            if(max < p[j].point[i])
            {
                max = p[j].point[i];
                strcpy(manofthematch[i] , p[j].name);
            }
        }
    }
    max = -999;
    int sum;
    for(i=0; i<5; i++)
    {

        if(max < p[i].total_point)
        {
            max = p[i].total_point;
            strcpy(manoftheseries,p[i].name);
        }
    }
    fclose(info);
    FILE *res;
    res = fopen("result.txt","w");
    for(j=0; j<3; j++)
    {
       fprintf(res,"Man of the match no. %d is : %s\n",j+1,manofthematch[j]);
    }
    fprintf(res,"Man of the Series is : %s\n",manoftheseries);
    fclose(res);
    return 0;
}
