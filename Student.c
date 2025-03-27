#include<stdio.h>
#include<string.h>
typedef struct studentDetail
{
    int id;
    char name[100];
    int age;
    char course[100];
    char status[100];
}student;
void addStudent(){
    FILE *data=fopen("stor.txt","a");
    if(data==NULL){
        printf("Error Open File\n");
        return;
    }
    int num;
    printf("Enter Number of Student:- ");
    scanf("%d",&num);
    student std[num]; 
    for(int i=0;i<num;i++){
        printf("-----Enter Detail------\n");
        printf("Enter ID:- ");
        scanf("%d",&std[i].id);
        getchar();

        printf("Enter Name:- ");
        fgets(std[i].name,sizeof(std[i].name),stdin);
        strtok(std[i].name,"\n");

        printf("Enter Age:- ");
        scanf("%d",&std[i].age);
        getchar();

        printf("Enter Course:- ");
        fgets(std[i].course,sizeof(std[i].course),stdin);
        strtok(std[i].course,"\n");

        printf("Enter Status:- ");
        fgets(std[i].status,sizeof(std[i].status),stdin);
        strtok(std[i].status,"\n");

        fprintf(data, "%d,%s,%d,%s,%s\n",std[i].id,std[i].name,std[i].age,std[i].course,std[i].status);
    }
    fclose(data);
    printf("Added\n");
}
// ------ View all Details------
void view(){
    FILE *data=fopen("stor.txt","r");
    if(data==NULL){
        printf("Error Opening\n");
        return;
    }
    student std; 
    
    while (fscanf(data, "%d,%99[^,],%d,%49[^,],%19[^\n]\n",&std.id, std.name, &std.age, std.course, std.status) == 5) {
        printf("ID: %d | Name: %s | Age: %d | Course: %s | Status: %s\n",std.id,std.name,std.age,std.course,std.status);
    }
    fclose(data);
    printf("Viewd\n");
}
// --------Search Student bY Id--------
void searchStudent(){
    FILE *data=fopen("stor.txt","r");
    if(data==NULL){
        printf("Error Open File\n");
        return;
    }
    student std;
    int search; 
    int found=0;
    printf("Enter Searching ID:- ");
    scanf("%d",&search);
    while(fscanf(data, "%d,%[^,],%d,%[^,],%[^\n]",&std.id,std.name,&std.age,std.course,std.status)==5){
        if(std.id==search){
            found=1;
            printf("%d\t%s\t%d\t%s\t%s\n",std.id,std.name,std.age,std.course,std.status);
        }
    }
    fclose(data);
    if(found==0){
        printf("Not Found\n");
    } else{
        printf("Searched\n");
    }
}
// ------Update Detail -----
void update(){
    FILE *data=fopen("stor.txt","r");
    FILE *temp=fopen("temp.txt","w");
    if(data==NULL || temp == NULL){
        printf("Error Open File\n");
        return;
    }
    student std;
    int search;
    int found=0;
    printf("Enter update ID:- ");
    scanf("%d",&search);
    while(fscanf(data, "%d,%[^,],%d,%[^,],%[^\n]",&std.id,std.name,&std.age,std.course,std.status)==5){
        if(std.id==search){
            found=1;
            getchar();
            printf("Enter new Name:- ");
            fgets(std.name,sizeof(std.name),stdin);
            strtok(std.name,"\n");

            printf("Enter new Age:- ");
            scanf("%d",&std.age);
            getchar();

            printf("Enter new Course:- ");
            fgets(std.course,sizeof(std.course),stdin);
            strtok(std.course,"\n");

            printf("Enter new Status:- ");
            fgets(std.status,sizeof(std.status),stdin);
            strtok(std.status,"\n");
        }
        fprintf(temp, "%d,%s,%d,%s,%s\n",std.id,std.name,std.age,std.course,std.status);
    }
    fclose(data);
    fclose(temp);
    remove("stor.txt");
    rename("temp.txt","stor.txt");
    if(found == 0){
        printf("Not Found\n");
    } else{
        printf("Update Successfully\n");
    }
}
// ------------- Status Update -----------
void statusUpdate(){
    FILE *data=fopen("stor.txt","r");
    FILE *temp=fopen("temp.txt","w");
    if(data == NULL || temp == NULL){
        printf("Error Open File\n");
        return;
    }
    student std; 
    int search;
    int found=0;
    printf("Enter search ID:- ");
    scanf("%d",&search);
    while(fscanf(data, "%d,%[^,],%d,%[^,],%[^\n]",&std.id,std.name,&std.age,std.course,std.status)==5){
        if(std.id==search){
            found=1;
            getchar();
            printf("Enter New Status:-");
            fgets(std.status,sizeof(std.status),stdin);
            strtok(std.status,"\n");
        }
        fprintf(temp, "%d,%s,%d,%s,%s\n",std.id,std.name,std.age,std.course,std.status);
    }
    fclose(data);
    fclose(temp);
    remove("stor.txt");
    rename("temp.txt","stor.txt");
    if(found == 0){
        printf("Not Found\n");
    } else{
        printf("Update Successfully\n");
    }
}
// -------- Delete Data --------
void deleteData(){
    FILE *data=fopen("stor.txt","r");
    FILE *temp=fopen("temp.txt","w");
    if(data==NULL || temp ==NULL){
        printf("Error open File\n");
        return;
    }
    student std; 
    int search;
    int found=0;
    printf("Enter Search ID:- ");
    scanf("%d",&search);
    while(fscanf(data, "%d,%[^,],%d,%[^,],%[^\n]",&std.id,std.name,&std.age,std.course,std.status)==5){
        if(std.id==search){
            found=1;
            continue;
        }
        fprintf(temp, "%d,%s,%d,%s,%s\n",std.id,std.name,std.age,std.course,std.status);
    }
    fclose(data);
    fclose(temp);
    remove("stor.txt");
    rename("temp.txt","stor.txt");
    if(found == 0){
        printf("Not Found\n");
    } else{
        printf("Update Successfully\n");
    }
}
int main(){
    int choose;
   
    
    while(choose!=7){
        
        printf("1 = AddStudent\n2 = View all Details\n3 = Search Student by ID\n4 = Update Detail\n5 = Status Update\n6 = Delete Data\n7 = Exit\n");
        printf("Select :- ");
        scanf("%d",&choose);
        

        switch (choose)
        {
            case 1:
            addStudent();
            break;

            case 2:
            view();
            break;

            case 3:
            searchStudent();
            break;

            case 4:
            update();
            break;
            
            case 5:
            statusUpdate();
            break;

            case 6:
            deleteData();
            break;

            case 7:
            printf("Exit\n");
            break;
        
            default:
            printf("Incorrect Order\n");
            break;
        }
    }
    

    return 0;
}