#include<stdio.h>

#include<string.h>
char ss[20] = "john nonphala";
char ch = 'A';






char *insertString(char *str, char ch, int setcur) {
  char *buff; // buffer  = index *buffer = value
  int i = 0;
  buff = str;
  char strfirst[20]; // strF
  memset(strfirst, '\0', strlen(strfirst)); // clear str
  char strlast[20];  // strL
  memset(strlast, '\0', strlen(strlast));

  while (1) {  // separate str to stfF and strLast
    strfirst[i]  = *buff;  // strf = str index 0 - index setcur 
    i++;
    buff++;
    if (i == setcur ) {
    //  strfirst[i] = ch;

      i = 0;
      while (1) {
        strlast[i] = *buff;       // strl  = str index setcur - strlen(str)
        i++;
        buff++;
        if (i == setcur + strlen(str)) {
            memset(str, '\0', strlen(str));
         	//strcat(strfirst,strlast);
			//strcat(str,strfirst);
   		    buff = strfirst;
            i = 0;
            while (1) {
            str[i] = *buff;
            i++;
            buff++;
            if (i == strlen(strfirst) ) {
              buff = strlast;
              i = 0;
              while (1) {
            	str[i+strlen(strfirst)] = *buff;
                i++;
                buff++;
                if (i == strlen(strlast) ) {
                  break;
                }
              } 

              break;
            }

          } 
          break;
        }


      }



      break;
      
    }
    
    
  }
  
  printf("\r\nstrF = %s\r\n",strfirst);
  printf("\r\nstrL = %s\r\n",strlast);
  

}


struct{
	
	int i;
	int cursor;
	int setcursor;
	char ch;
	char *buff;
	char *buff2;
	char str_ram[40];
	char str_rom[4096];
	
}note;

char *insertshift(char *str, char ch, int setcur) { // insert mind str

	note.buff = str;
	note.buff += setcur;
	*note.buff = ch;

}


char *insertString(char *str, char ch, int setcur) {
  // char *buff; // buffer  = index *buffer = value
  if (setcur == 0) { // insert First str
    // str = aaa
    note.buff = &ch; // ch = A
    strcpy(note.strfirst, note.buff); // F = A
    strcpy(note.strlast, str); //  L =  aaa
    strcat(note.strfirst, note.strlast); // F = A + L = aaa = Aaaa
    strcpy(note.str_ram, note.strfirst); // Aaaa
    memset(note.strfirst, 0, strlen(note.strfirst));
    memset(note.strlast, 0, strlen(note.strlast));
  }
  else {
    note.buff = str;
    note.i = 0;
    /*    div  strF/index 0 + index(setcur)   strL = /(intdex setcur + strlen(str) */
    while (1) {  // separate str to stfF and strLast
      note.strfirst[note.i]  = *note.buff;  // strf = str index 0 - index setcur
      note.i++;
      note.buff++;
      if (note.i == setcur) {
        note.i = 0;
        while (1) {
          note.strlast[ note.i] = *note.buff;       //
          note.i++;
          note.buff++;
          if ( note.i == setcur + strlen(str)) {
            break;
          }
        }
        break;
      }
    }

    note.buff = &ch;
    strcat(note.strfirst, note.buff);
    strcat(note.strfirst, note.strlast);
    strcpy(note.str_ram, note.strfirst);


    /*  Debugger
      printf("\r\n------------------\r\n");
      printf("insert strF =  %s",note.strfirst);
      printf("\r\n------------------\r\n");

      printf("\r\n------------------\r\n");
      printf(" insert strL = %s",note.strlast);
      printf("\r\n------------------\r\n");
    */

    memset(note.strfirst, 0, strlen(note.strfirst));
    memset(note.strlast, 0, strlen(note.strlast));

  }
}

int  main() {
  printf(" str = %s \n", ss);
  printf("setcur = %d\n", 7);
 
  insertshift(ss,'B',7);
  
  printf("%s",ss);


  return 0;
}
