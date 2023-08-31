#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(){	
    printf("Welcome user, This is a code for Encryption and Decryption using a Symmetric key\n");
    printf("--> symmetric key means , same key is used for both encryption and decryption\n");
/*------VARIABLES USED IN THE CODE-------*/    
    int key;              /*-used to get key from user-*/
    int i;                /*-used in functioning of loops-*/
    int usedkey;          /*-key used for alphabets-*/
    int usednumkey;       /*-key used for integers-*/
    int unlock;           /*-used to chceck the value of key at decryption-*/
    int stepup=0;         /*-used to move to next step-*/
    char sample;          /*-used to ask user , wheater he want to go to next step*/
    char str[200];        /*-used to store the data , provided by user-*/
/*------CODE TO GET THE DATA-------*/    
    printf("\nKindly provide the data for encryption:\n--> ");
    gets(str);
/*------CODE TO GET THE KEY-------*/    
    printf("\nPlease input the key for encryption and decryption (must be an integer): ");
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
    printf("\nHere is your encrypted text, also referred to as cipher text:\n--> ");
    puts(str);
/*------CODE TO ASK , WHETER YOU WANT TO DO DECRYPTION OR NOT-------*/
    printf("\nWould you like to proceed to the Decryption phase? Y/N\n-->");
    fflush(stdin);scanf("%c",&sample);
    if(sample=='y'||sample=='Y' ||sample=='yes'|| sample=='YES'|| sample=='Yes'|| sample=='yEs' || sample=='yeS' || sample=='yES' || sample=='yeS'|| sample=='YEs' || sample=='YeS'){stepup++;}
    else if(sample=='n'||sample=='N' ||sample=='no'|| sample=='NO'|| sample=='No' || sample=='nO'){printf("ok , as you wish, we will stop the code here. (press any key to quit)");getch();}
    else{printf("invalid respond , we will consider this as NO. (press any key to quit)",sample);getch();}
       
    
/*------CODE WHICH ASKING FOR CORRECT KEY-------*/    
    if(stepup>0){
    	printf("\e[1;1H\e[2J");
    	printf("The Encrypted Text is , LET's see you can decrypt it!!!\n-->");
    	puts(str);
    	
    	printf("\n Please Enter the Correct Key, you will only get 3 attempts\n");
    	for(i=1;i<4;i++){
    		if(i==3){printf("\nTHIS IS THE LAST CHANCE, DO || DIE ");}
    		printf("\nPlease Enter the key --> ");
    		fflush(stdin);
    		scanf("%d",&unlock);
    		if(unlock==key){printf("\nAuthentication successful.\n");stepup++;break;}
    		else{printf("Decryption attempt %d unsuccessful. You have %d remaining chances.\n",i,3-i);}
    		if(i==3){printf("\nSince all attempts have been exhausted, data decryption is not possible.(press any key to quit)");getch();}
	   }
	}    
/*------CODE WHICH IS DOING DECERYPTION-------*/
    if(stepup>1){ 
	 printf("The Decrypted Data is as follows:\n--> "); 
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
	   printf("\n\nWe extend our gratitude to you. We trust that our code has been of service. (press any key to quit)\n"); 
	   getch();
   }	
   return 0;    
}
