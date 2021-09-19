#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
const int M=3;
const int N=3;
int counter=0;
void display(char arr[M][N])
{
    int i,j;
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%c\t",arr[i][j]);
        }
        printf("\n");
    }
}
int check_row(char arr[M][N],int row,char c)
{
    int b,flag=0;
    for(b=0;b<N;b++)
    {
        if(arr[row][b]==c)
        {
            flag++;
        }
    }
    return(flag);
}
int check_column(char arr[M][N],int col,char c)
{
    int a,flag=0;
    for(a=0;a<M;a++)
    {
        if(arr[a][col]==c)
        {
            flag++;
        }
    }
    return(flag);
}
int check_diagonal(char arr[M][N],char c)
{
    int a,flag1=0,flag2=0;
    for(a=0;a<3;a++)
    {
        if(arr[a][a]==c)
            flag1++;
        if(arr[3-a-1][a]==c)
            flag2++;
    }
    if(flag1==3||flag2==3)
        return(3);
    else
        return(0);
}
void mark(char arr[M][N],char p,char c,char *s)
{
int i,j,count_r,count_c,count_d;
char k;
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            if(arr[i][j]==p)
            {
                arr[i][j]=c;
                display(arr);//Displays different positions
                count_r=check_row(arr,i,c);
                count_c=check_column(arr,j,c);
                count_d=check_diagonal(arr,c);
                if((count_r==3||count_c==3||count_d==3))
                {
                  printf("%s won",s);

                  do
                  {
                  printf("\nPress 1 to exit:\n");
                  scanf("%c",&k);
                  fflush(stdin);
                  if(k=='1')
                  {
                      exit(0);
                  }
                  }while(k!='1');
                }

            }
        }

    }
}

void human_turn(char arr[M][N],char ch)
{
    char pos;
    printf("Enter the position:\n");
    scanf("%c",&pos);
    fflush(stdin);
    mark(arr,pos,ch,"User");//Marking at specific position

}
void computer_turn(char arr[M][N],char chcom)
{
    char pos;
    srand(time(0));
    do
    {
        pos=arr[rand()%M][rand()%N];

    }while(pos=='x'||pos=='X'||pos=='o'||pos=='O');

    printf("%c\n",pos);
    mark(arr,pos,chcom,"Computer");

}

int main()
{
    char arr[][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};//Depicts Different positions
    char ch,chcomp,press;
    int i=0;
    printf("Choose X or O:\n");
    scanf("%c",&ch);
    fflush(stdin);

    if(ch!='X'&&ch!='x'&&ch!='o'&&ch!='O')//Message when rules violated
    {
        printf("Invalid choice---You cannot play the game");
        exit(0);
    }

    if(ch=='X'||ch=='x')//Determining computer's choice
    chcomp='O';
    else
    chcomp='X';

    system("cls");
    display(arr);//Displays different positions
    printf("Your turn\n");
    human_turn(arr,ch);


    do
    {
    system("cls");
    printf("Computer's turn\n");
    computer_turn(arr,chcomp);

    printf("Your turn\n");
    human_turn(arr,ch);

    i++;

    }while(i<=3);

    display(arr);
    printf("Press 1 to exit");
    scanf("%c",&press);
    if(press=='1')
    {
        exit(0);
    }
    getch();
    return 0;
}
