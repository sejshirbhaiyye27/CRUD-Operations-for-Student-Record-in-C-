#include <stdio.h>
#include <stdlib.h>
int n;
struct student
{
    int roll_number,p1,p2,p3,search_student;
    char name[30];
    float Tmarks,res;

}e[1000];
void add()//func for add
{
  int i;
  printf("Enter the number of students : ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
      printf("student %d\n",i+1);
      printf("Enter the student roll number :",i+1);
      scanf("%d",&e[i].roll_number);
      printf("Enter the student name :",i+1);
      scanf("%s",&e[i].name);
      printf("Enter the marks of paper 1 :",i+1);
      scanf("%d",&e[i].p1);
      printf("Enter the marks of paper 2 :",i+1);
      scanf("%d",&e[i].p2);
      printf("Enter the marks of paper 3 :",i+1);
      scanf("%d",&e[i].p3);
      e[i].Tmarks= e[i].p1+e[i].p2+e[i].p3;

}
printf("Record saved ......!\n");
}
void show()//fung for show
{
    int i;
    for(i=0;i<n;i++)
    {

        printf("Student %d roll number : %d\n",i+1,e[i].roll_number);
        printf("Student %d name : %s\n",i+1,e[i].name);
        printf("show the marks of student %d marks of paper 1 :%d\n",i+1,e[i].p1);
        printf("Show the marks of student  %d marks of paper 2 :%d\n",i+1,e[i].p2);
        printf("show the marks of student  %d marks of paper 3 :%d\n",i+1,e[i].p3);
              e[i].res=e[i].Tmarks/3;
printf("Result is : %.2f\n",e[i].res);

    }
}
void search()
{
int i, found= 0, search_student,roll;
printf("Enter   roll number  you want to search: ");
scanf("%d",&roll);
for( i=0;i<n;i++)
{

if(e[i].roll_number==roll)
{
printf("STUDEND FOUND...!\n");
printf("Enter the roll number of the student you want to search :%d\n",e[i].roll_number);
printf("Name: %s\n",e[i].name);
printf("Marks in paper 1 :%d\n",e[i].p1);
printf("Marks in paper 2 :%d\n",e[i].p2);
printf("Marks in paper 3 :%d\n",e[i].p3);
printf("Result is : %.2f\n",e[i].res);
found = 1  ;
break;
}
}
if(found==0)
{
    printf("Student is not found!\n");
}

}
void update()

{
    int roll,choice,i,name,found=0;
    printf("RECORED UPDATE\n");
 printf("Enter the roll number you want to update :\n");
 scanf ("%d",&roll);

 for (i=0;i<n;i++)
    {
       if(e[i].roll_number==roll)
       {
  printf("Update Record Choice\n");
  printf("1.Name\n");
  printf("2.Paper 1:\n");
  printf("3. Paper 2\n");
  printf("4. Paper 3\n");
  printf("Enter your choice :");
  scanf("%d",&choice);


           found=1;
           break;
       }

    }
    if(found==0)
    {
        printf("Student not found\n we cant update the record\n ");
    }



  switch(choice)
  {
  case 1:  // update student new name
    for (i=0;i<n;i++)
    {
       if(e[i].roll_number==roll)
       {
           printf("Enter new name you want to update : ");
           scanf("%s",&e[i].name);
           printf("Name updated succesfully....!\n");
           break;
       }

    }
break;

case 2://update for paper 1 marks
    for(i=0;i<n;i++)
    {
        if(e[i].roll_number==roll)
        {
            printf("Enter new marks you want to update : ");
            scanf("%d",&e[i].p1);
            e[i].Tmarks= e[i].p1+e[i].p2+e[i].p3;
           printf("paper 1 marks updated succesfully....!\n");
            break;
        }

    }



    break;
  case 3://update for paper 2 marks
      for(i=0;i<n;i++)
      {
          if(e[i].roll_number==roll)
          {
              printf("Enter the paper 2 marks you want to update : ");
              scanf("%d",e[i].p2);
                    e[i].Tmarks= e[i].p1+e[i].p2+e[i].p3;

              printf("Paper 2 marks updated succesfully...! ");
              break;
          }
      }
    break;

  case 4://update for paper 3 marks
      for(i=0;i<n;i++)
      {
          if(e[i].roll_number==roll)
          {
              printf("Enter the paper 3 marks you want to update : ");
              scanf("%d",e[i].p3);
                    e[i].Tmarks= e[i].p1+e[i].p2+e[i].p3;

              printf("paper 3 marks updated succesfully....!");
              break;
          }
      }
    break;

  default:
    printf("wrong choice\n");
    break;

  }




}
void dele()
{int roll,found=0,i;
    printf("Enter roll number you want to delete record ");
    scanf("%d",&roll);
    for(i=0;i<n;i++)
    {
        if(e[i].roll_number==roll)
        {
        e[i].roll_number=0;
        e[i].p1=0;
        e[i].p2=0;
        e[i].p3=0;
        e[i].res=0;
        e[i].Tmarks=0;
        printf("Your record is deleted succesfully ...!\n");

        found=1;
        break;
        }
    }
    if (found==0)
    {
        printf("student not found you cant delete record\n");
    }
}



void menu()//fung for menu
{
    printf("WELCOME TO STUDENT MANAGMENTSYSTEM\n");
printf("1. Add student\n");
printf("2. Show student\n");
printf("3.Delete student\n");
printf("4.Update student\n");
printf("5.search student\n");
printf("0.Exit\n");
}
void choice()
{
    int ch,lp=1;
    while(lp)
{
menu();
printf("Enter the choice :");
scanf("%d",&ch);
switch(ch)
{
 case 1:
     add ();
     break;
 case 2:
    show();
    break;
 case 3:
    dele();
    break;
  case 4:
    update();
    break;
    case 5:
    search();
    break;
    case 0:
    lp=0;
    printf("Exiting");
    break;
    default:
        printf("wrong choice \n");
}


}
}
int main()
{
    choice();
    return 0;
}
