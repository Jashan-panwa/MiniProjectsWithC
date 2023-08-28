#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(){	
    printf("Welcome user, This is a code for Encryption and Decryption using a Symmetric key\n");
    printf("--> symmetric key means , same key is used for both encryption and decryption\n");
/*------VARIABLES USED IN THE CODE-------*/    
    int key;                /*-used to get key from user-*/
	int i;                  /*-used in functioning of loops-*/
    int usedkey;            /*-key used for alphabets-*/
    int usednumkey;         /*-key used for integers-*/
    int unlock;             /*-used to chceck the value of key at decryption-*/
    int stepup=0;           /*-used to move to next step-*/
    char sample;            /*-used to ask user , wheater he want to go to next step*/
    char str[200];          /*-used to store the data , provided by user-*/
/*------CODE TO GET THE DATA-------*/    
    printf("\nPlease enter the data here :\n--> ");
    gets(str);
/*------CODE TO GET THE KEY-------*/    
    printf("\nPlease enter the key , this key will be used for encryption and decryption(it must be integer) : ");
    fflush(stdin);
	scanf("%d",&key);
 /*------ADJUSTING KEY SIZE FOR ALPHABETS-------*/   
    if(key>26 && key%26!=0){usedkey=key%26;}
    else if(key%26==0){usedkey=key/26;}
    else{usedkey=key;}
/*------ADJUSTING KEY SIZE FOR NUMBERS-------*/    
    if(key>10 && key%10!=0){usednumkey=key%10;}
	else if(key%10==0){usednumkey=key/10;}
	else{usednumkey=key;}	
/*------CODE WHICH IS DOING ENCRYPTION-------*/  
    for( i=0;str[i];i++){
      if(str[i]==' '){continue;}/*--FOR SPACES--*/
      else if(str[i]>='a' && str[i]<='z'){/*--FOR SMALL LETTERS--*/
    		if(str[i]+usedkey>'z'){str[i]=str[i]+usedkey-26;}
    		else{str[i]=str[i]+usedkey;}
	   }
	  else if(str[i]>='A' && str[i]<='Z'){/*--FOR CAPITAL LETTERS--*/
    		if(str[i]+usedkey>'Z'){str[i]=str[i]+usedkey-26;}
    		else{str[i]=str[i]+usedkey;}
	   } 
	  else if(str[i]>='0' && str[i]<='9'){/*--FOR SNUMERIC VALUES--*/
    		if(str[i]+usednumkey>'9'){str[i]=str[i]+usednumkey-10;}
    		else{str[i]=str[i]+usednumkey;}
	   } 
	} 
/*------CODE TO DISPLAY ENCRYPPTED TEXT-------*/      
    printf("\nHere is your encrypted text(also known as cipper text)\n--> ");
    puts(str);
/*------CODE TO ASK , WHETER YOU WANT TO DO DECRYPTION OR NOT-------*/
    printf("\nWant to move on to the Decryption part ? Y/N\n-->");
    fflush(stdin);scanf("%c",&sample);
    if(sample=='y'||sample=='Y' ||sample=='yes'|| sample=='YES'|| sample=='Yes'){stepup++;}
    else if(sample=='n'||sample=='N' ||sample=='no'|| sample=='NO'|| sample=='No'){printf("ok , as you wish, we will stop the code here");}
    else{printf("invalid respond , we will consider this as NO",sample);}
    
    
    
/*------CODE WHICH IS DOING DECERYPTION-------*/    
    if(stepup>0){
    	printf("\e[1;1H\e[2J");
    	printf("The Encrypted Text is , LET's see you can decrypt it!!!\n-->");
    	puts(str);
    	
    	printf("\n Please Enter the Correct Key, you will only get 3 attempts\n");
    	for(i=1;i<4;i++){
    		if(i==3){printf("\nTHIS IS THE LAST CHANCE, DO || DIE");}
    		printf("\nPlease Enter the key --> ");
    		fflush(stdin);
    		scanf("%d",&unlock);
    		if(unlock==key){printf("\nCorrect key\n");stepup++;break;}
    		else{printf("Attempt %d FAILED! , you have have T-%d chances left.\n",i,3-i);}
    		if(i==3){printf("\nAs your all attempts are wrrong, you cannot Decrypt the data.");}
	   }
	}    
/*------CODE WHICH IS DOING DECERYPTION-------*/
    if(stepup>1){
	   printf("\nThe Decrypted Data is\n--> ");
	   
	   for( i=0;str[i];i++){
      	 if(str[i]==' '){continue;}/*--FOR SPACES--*/
         else if(str[i]>='a' && str[i]<='z'){/*--FOR SMALL LETTERS--*/
    	 	  if(str[i]-usedkey<'a'){str[i]=str[i]-usedkey+26;}
    	      else{str[i]=str[i]-usedkey;}
	       }
	     else if(str[i]>='A' && str[i]<='Z'){/*--FOR CAPITAL LETTERS--*/
    	      if(str[i]-usedkey<'A'){str[i]=str[i]-usedkey+26;}
    	      else{str[i]=str[i]-usedkey;}
	       } 
	     else if(str[i]>='0' && str[i]<='9'){/*--FOR SNUMERIC VALUES--*/
    	      if(str[i]-usednumkey<'0'){str[i]=str[i]-usednumkey+10;}
    		  else{str[i]=str[i]-usednumkey;}
	       } 
	   } 
	   puts(str);
	   printf("\n\nThank you User, we hope that you liked our code\n"); 
   }	
   return 0;    
}
