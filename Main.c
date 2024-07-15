/* Mini Student System in C programming,
Made by Haqim Maths on 15th July 2024*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "HmErrorCustomFuncs.h"

#define StrSize 100

struct Student {
 double ID;
 char Name[StrSize];
 char Username[StrSize];
 double PassportNumber;
 char Gender;
 int Single;
 unsigned int Age;
 char Course[StrSize];
 char University[StrSize];
 char Email[StrSize];
 char Nationality[StrSize];
 char Address[StrSize];
 struct Student *Link;
};

int MainMenu(){
  int UserInputMainMenu;
  //system("clear");
  printf("%s", "\n");
  printf("%s", "----------------------------\n");
  printf("%s", "Student Mini System\n");
  printf("%s", "Made By: Haqim Maths\n");
  printf("%s", "----------------------------\n");
  printf("%s", "[-1] Clear terminal\n");
  printf("%s", "[0] Quit program\n");
  printf("%s", "[1] Insert a Data\n");
  printf("%s", "[2] View Data\n");
  printf("%s", "[3] Delete a Data\n");
  printf("%s", "[4] Search a Data\n");
  printf("%s", "[5] Display Head and Rear Data\n");
  printf("%s", "[6] Explain the author\n");
  printf("%s", "----------------------------\n");
  printf("%s", "Input: ");
  scanf("%d", &UserInputMainMenu);
  printf("%s", "----------------------------\n");
  return UserInputMainMenu;
}

void InsertData(struct Student **Head, struct Student **Rear){
 struct Student *NewData;
 NewData = malloc(sizeof(struct Student));
 printf("%s", "Enter student details: \n");
 printf("%s", "ID: ");
 scanf("%lf", &NewData->ID);
 printf("%s", "Name: ");
 getchar();
 fgets(NewData->Name, sizeof(NewData->Name), stdin);
 printf("%s", "Username: ");
 scanf("%s", NewData->Username);
 printf("%s", "Passport Number: ");
 scanf("%lf", &NewData->PassportNumber);
 printf("%s", "Gender: ");
 getchar();
 scanf("%c", &NewData->Gender);
 printf("%s", "Single: ");
 scanf("%d", &NewData->Single);
 printf("%s", "Age: ");
 scanf("%d", &NewData->Age);
 printf("%s", "Course: ");
 getchar();
 fgets(NewData->Course, sizeof(NewData->Course), stdin);
 printf("%s", "University: ");
 fgets(NewData->University, sizeof(NewData->University), stdin);
 printf("%s", "Email: ");
 scanf("%s", NewData->Email);
 printf("%s", "Nationality: ");
 getchar();
 fgets(NewData->Nationality, sizeof(NewData->Nationality), stdin);
 printf("%s", "Address: ");
 fgets(NewData->Address, sizeof(NewData->Address), stdin);
 NewData->Link = NULL;
 if (*Head == NULL){
  *Head = NewData;
 } else {
  struct Student *LastData = *Head;
  while(LastData->Link != NULL){
   LastData = LastData->Link;
  }
  LastData->Link = NewData;
  *Rear = NewData;
 }
}

void DisplayData(struct Student *Head){
 if (Head == NULL){
  EmptyListError();
 } else {
  int StudentIndex = 0;
  struct Student *Current = Head;
  while (Current != NULL){
    printf("(No. %d) ID: [%lf], Name: %s, Username: %s, Passport Number: %lf, Gender: %c, Single: %d, Age: %d, Course: %s, University: %s, Email: %s, Nationality: %s, Address: %s, Data Address: %p, Linked Address: %p\n", ++StudentIndex, Current->ID, Current->Name, Current->Username, Current->PassportNumber, Current->Gender, Current->Single, Current->Age, Current->Course, Current->University, Current->Email, Current->Nationality, Current->Address, Current, Current->Link);
    Current = Current->Link;
  }
  printf("Total data: %d\n", StudentIndex);
 //getch();
 }
}

void DeleteData(struct Student **Head, int DeleteID){
 struct Student *Delete = *Head;
 if (Delete == NULL){
  EmptyListError();
 } else {
  if (Delete->ID == DeleteID){
  printf("Data to be deleted: Data Address: %p\n ID: %lf\nName: %s\nAge: %d\n Address Link: %p", Delete, Delete->ID, Delete->Name, Delete->Age, Delete->Link);
  *Head = Delete->Link;
  free(Delete);
 } else {
  while (!(Delete->Link == NULL)){
    Delete = Delete->Link;
    if (Delete->ID == DeleteID){
    printf("Data to be deleted:\n ID: %lf\nName: %s\nAge: %d\n", Delete->ID, Delete->Name, Delete->Age);
    struct Student *Prev = *Head;
    while (Prev->Link != NULL){
      if (Prev->Link == Delete){
      if (Delete->Link != NULL){
        Prev->Link = Delete->Link;
      } else {
        Prev->Link = NULL;
      }
      free(Delete);
      break;
      }
      Prev = Prev->Link;
    }
    }
  }
 }
 }
}

void SearchData(struct Student *Head, int SearchID){
 struct Student *SearchData = Head;
 if (SearchData == NULL){
  EmptyListError();
 } else {
  if (SearchData->ID == SearchID){
  printf("%s", "Data founded!\n");
  printf("Data Address: %p, ID: %lf, Name: %s, Age: %d, Linking Address: %p\n", SearchData, SearchData->ID, SearchData->Name, SearchData->Age, SearchData->Link);
    } else {
      while (SearchData->Link != NULL){
      SearchData = SearchData->Link;
      if (SearchData->ID == SearchID){
        printf("%s", "Data founded!\n");
        printf("Data Address: %p, ID: %lf, Name: %s, Age: %d, Linking Address: %p\n", SearchData, SearchData->ID, SearchData->Name, SearchData->Age, SearchData->Link);
        break;
      }
      }
    }
    printf("%s", "Do you want to modify the data?: ");
    int Modify;
    scanf("%d", &Modify);
    if (Modify == 1){
      //ModifyData(&SearchData);
      char WhichPart[100];
      printf("%s", "Which part of data you want to modify?: ");
      scanf("%s", WhichPart);
      if (strcmp(WhichPart, "ID") == 0){
        printf("%s", "Enter new ID: ");
        scanf("%lf", &SearchData->ID);
      } else if (strcmp(WhichPart, "Name") == 0){
        printf("%s", "Enter new name: ");
        scanf("%s", SearchData->Name);
      } else {
        printf("%s", "Enter new age: ");
        scanf("%d", &SearchData->Age);
      }
    } else {
      return;
    }
 }
}

void DisplayHeadAndRear(struct Student *Head, struct Student *Rear){
 if (Head == NULL){
  EmptyListError();
 } else {
  printf("%s", "Head\n");
  printf("Data Address: %p, ID: %lf, Name: %s, Age: %d. Linked Address: %p\n", Head, Head->ID, Head->Name, Head->Age, Head->Link);
  printf("%s", "Rear\n");
  printf("Data Address: %p, ID: %lf, Name: %s, Age: %d, Linked Address: %p\n", Rear, Rear->ID, Rear->Name, Rear->Age, Rear->Link);
 }
}

void ExplainTheAuthor(){
 printf("%s", "The author, Haqim Maths, is a handsome guy hehe :) \n");
}

// void ModifyData(struct Student **DataToModify){
//  printf("%s", "Enter new ID");
//  scanf("%d", **DataToModify->ID);
//  printf(DataToModify->Name);
// }

int main(void){
 bool InSystem = true;
 struct Student *Head = NULL;
 struct Student *Rear = NULL;
 do {
  switch (MainMenu()){
   case -1:
    ClearTerminal();
    break;
   case 0:
    //system("cls");
    printf("%s", "Goodbye\n");
    InSystem = false;
    break;
   case 1:
    InsertData(&Head, &Rear);
    break;
   case 2:
    DisplayData(Head);
    break;
   case 3:
    int DeleteID;
    printf("%s", "Enter the student ID to be deleted: ");
    scanf("%d", &DeleteID);
    DeleteData(&Head, DeleteID);
    break;
   case 4:
    int SearchID;
    printf("%s", "Enter the student ID to be search: ");
    scanf("%d", &SearchID);
    SearchData(Head, SearchID);
    break;
   case 5:
    DisplayHeadAndRear(Head, Rear);
    break;
   case 6:
    ExplainTheAuthor();
    break;
   default:
    InputError();
  }

 } while (InSystem == true);
 return 0;
}