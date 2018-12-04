#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE* fp;
	char name[100];
	char word[100];
	
	printf("input a file name : ");
	scanf("%s",&name);
	
	fp = fopen(name, "r");
	
	if(fp==NULL)
	{
		printf("ERROR! check the file name : %s\n",name);
		return -1;
	}
	
	printf("%c\n",fgetc(fp));
	
	fclose(fp);
	

	return 0;
}

int is_whitespace(char c)
{
	if( c==' '||
	    c=='\t'||
		c=='\n'||
		c=='\r'||
		c=='(' ||
		c==')')
		
		return 1;
		
		return 0;
}

int fget_word(FILE* fp, char* word){
	char c;
	int cnt;
	
	
	       //word processing
	while((c=fgetc(fp)) != EOF){ //1 문자 받음.
	
	    if(is_whitespace(c) == 0){ //유의미한 숫자이면 나감
			
		           
				   break; 
     	} 
	}       


    if(c == EOF) //최초 읽은 문자가 마지막 일때 
    {
    	return 0;
	}
	//단어 한글자씩 읽 
	cnt = 0;
	word[cnt++] = c;
	word[cnt] = '\0';
	
	while((word[cnt] = fgetc(fp)) != EOF)
	{
		if(is_whitespace(word[cnt]) == 1)
		{
			word[cnt] = '\0';
			break;
		}
		
		cnt++;
	}
	
	return cnt;
}


