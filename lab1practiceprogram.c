#include<stdio.h>
int main()
{
    int age,studid,i,n;
    float marks;
    printf("enter the number of students- ");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
    printf("enter student id- ");
    scanf("%d",&studid);
    printf("enter student age-");
    scanf("%d",&age);
    printf("enter student marks-");
    scanf("%f",&marks);
    if(age>20 && marks<=100)
    printf("student has qualified exam\n");
    else
    printf("student hasnt qualified\n");
    if(age>20 && marks>=65)
    printf("student has qualified for admission\n");
    else
    printf("student hasnt qualified for admission\n");
    }
    return 0;
}
