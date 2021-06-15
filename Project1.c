#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

    
    void Encrypt(char name[200]) {
        char *mm =name;
        FILE *fr;
        FILE *fw;
        
        char m;
        fr = fopen(mm,"r");
        if (fr ==NULL) 
        {
            
            printf("File invalid \n ");
            printf("Please type proper file location again \n ");
           return ;
        }
        fw =fopen("temp99.txt","w");
        
        
        
        while ((m =fgetc(fr))!=EOF)
        {
            m =m+991;
            fputc(m,fw);
        }
        fclose(fw);
        fclose(fr);
        fw =fopen("temp99.txt","r");
        fr = fopen(name,"w");
        while ((m=fgetc(fw))!=EOF)
        {
            fputc(m,fr);
        }
        fclose(fw);
        fclose(fr);
        if ( remove("temp99.txt")==0 ) 
        {
            printf("Your file is encrypted \n");
        
        }

        
        
    }
     void Decrypt(char name[200]) {
          char *mm =name;
         FILE *fr;
        FILE *fw;
    
        char m;
        
        fr = fopen(mm,"r");
        if (fr ==NULL) 
        {
            
            printf("File invalid \n ");
            printf("Please type proper file location again \n ");
           return ;
        }
        fw =fopen("temp99.txt","w");
        while ((m =fgetc(fr))!=EOF)
        {
            m =m-991;
            fputc(m,fw);
        }
        fclose(fw);
        fclose(fr);
        fw =fopen("temp99.txt","r");
        fr = fopen(name,"w");
        while ((m=fgetc(fw))!=EOF)
        {
            fputc(m,fr);
        }
        fclose(fw);
        fclose(fr);
        if ( remove("temp99.txt")==0 ) 
        {
            printf("Your file is Decryped \n");
        
        }
     }
int main(){

    char filename[200];
    int choice;
    char c;
    FILE *fs;
    FILE *ft;
    
    fs =fopen("password.txt","r");
    ft =fopen("password2.txt","w");
    xy:
    printf(" \t Press 1 to encrypt the file \t \n ");
    printf(" \t Press 2 to Decrypt  the file \t \n ");
    printf(" \t Press 3 to Exit \t \n ");
    scanf("%d",&choice);
    if (choice ==1 )
    {
        printf("You have procced to Decrypt the file \n");
        printf("Type the file path  \n \t  ");
        printf("Example : C:\\home\\abc.txt \n");
        scanf("%s",&filename);
        Encrypt(filename);
        goto xy;

        

    }
    else if(choice ==2) {
        printf("You have procced to Decrypt the file \n");
        printf("Type the file path  \n \t  ");
        printf("Example : C:\\home\\abc.txt \n");
        scanf("%s",&filename);
        Decrypt(filename);
        goto xy;
    }
    else if (choice==3) {
        return 0;
    }
    else {
        printf("You blind bro ? \n");
        goto xy;
    }
    return 0;
    

    

}  
    
