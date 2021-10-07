#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>
#include<conio.h>
int main()
{

    //addData(str);
    //removeData2(str);
    //modifyData(str);
    //createList();

    menu2();
    return 0;

}
bool check2arrays(char data[],char data2[]){
    if(strlen(data)==strlen(data2)){
        for(int i=0;i<strlen(data);i++){
            if(data[i]!=data2[i]){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}
void addData(char data[]){
    FILE *fp;
    fp=fopen("data.txt","a+");
    fputs(data,fp);
    fputc('\n',fp);
    fclose(fp);
}

void removeData(char data[]){
    FILE *fp1 = fopen("data.txt","r");
    FILE *fp2 = fopen("temp.txt","w");
    int temp=1;
    int linetoDel=findLineNo(data);
    //char line[1000];
    char c = fgetc(fp1);
    while(c!=EOF){
        if(c=='\n'){
            temp++;
        }
        if(temp != linetoDel ){
            fputc(c,fp2);
        }
        c=fgetc(fp1);
    }
    fclose(fp1);
    fclose(fp2);
    remove("data.txt");
    rename("temp.txt","data.txt");




}
void removeData2(char data[]){
    FILE *fp1 = fopen("data.txt","r");
    FILE *fp2 = fopen("temp.txt","w");
    int temp=0;
    int linetoDel=findLineNo(data);
    char line[10000];
    while(fgets(line,10000,fp1)!= NULL){
        temp++;
        if(temp!=linetoDel){
            fputs(line,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("data.txt");
    rename("temp.txt","data.txt");

}
void modifyData(char data[]){
    FILE *fp1 = fopen("data.txt","r");
    FILE *fp2 = fopen("temp.txt","w");

    int temp=0;
    int linetoDel=findLineNo(data);
    char line[1000];

    while(fgets(line,1000,fp1)!= NULL){
        temp++;
        if(temp != linetoDel){
            fputs(line,fp2);

        }
        else {
            printf("Give me the complete new data: ");
            scanf("%[^\n]%*c", &line);
            fputs(line,fp2);
            fputc('\n',fp2);

        }




    }
    fclose(fp1);
    fclose(fp2);
    remove("data.txt");
    rename("temp.txt","data.txt");




}
int findLineNo(char data[]){
    FILE *fp;
    fp=fopen("data.txt","r");
    char line[1000];
    int lineno=0;

    while(fgets(line,1000,fp)!= NULL){

        lineno++;


        char *name = strtok(line,",");

        if(check2arrays(name,data)){
            fclose(fp);
            return lineno;
        }



    }
    fclose(fp);
    printf("No given name found\n");
    return 0;



}
void createList(){
    FILE *fp = fopen("data.txt","r");
    char line[1000];
    while(fgets(line,1000,fp)!= NULL){
        printf("%s",line);
    }
    fclose(fp);

}
void menu2(){
    int num;
    char line[1000];
    do{

        printf("Welcome to the vaccination registration\n");
        printf("The data you have to provide are: name, birth year, phone number and are you willing to pay for the vaccine\n");
        printf("choose the options below\n");
        printf("1)Add data\n");
        printf("2)Modify data\n");
        printf("3)Remove data\n");
        printf("4)Create a list\n");
        printf("0)Exit\n");
        scanf("%d",&num);
        switch(num){
        case 1:
            printf("Add data: ");
            fflush(stdin);
            fgets(line,1000,stdin);
            line[strlen(line)-1]=0;
            addData(line);
            break;
        case 2:
            printf("Enter the name of the participant you want to modify data: ");
            fflush(stdin);
            fgets(line,1000,stdin);
            line[strlen(line)-1]=0;
            modifyData(line);
            break;
        case 3:
            printf("Enter the name of the participant you want to remove data: ");
            fflush(stdin);
            fgets(line,1000,stdin);
            line[strlen(line)-1]=0;
            removeData2(line);
            break;
        case 4:
            printf("List of the applicants\n");
            createList();
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Invalid command");
            break;


        }

    }while(num!=0);



}

