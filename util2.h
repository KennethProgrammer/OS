#ifndef util2_h
#define util2_h

void reverse(char s[]);

int strlen(char string[]){
	int i;
	for(i = 0; string[i] != 0; i++){};
	return i;
};

void append_to_buffer(char string[], char n){
	int len = strlen(string);
	if (len == 256){return;};
	string[len] = n;
	string[len+1] = 0;
};

int strcmp(char s1[], char s2[]){
    int i;
    for (i = 0; s1[i] == s2[i]; i++){
        if (s1[i] == '\0') return 0;
    };
    return s1[i] - s2[i];
};

void itoa(int n, char str[]){
	int i, sign;
    	if ((sign = n) < 0) n = -n;
    	i = 0;
     	do {
         str[i++] = n % 10 + '0';
        } while ((n /= 10) > 0);

        if (sign < 0) str[i++] = '-';
        str[i] = '\0';

        reverse(str);
};

void reverse(char s[]){
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--){
         c = s[i];
         s[i] = s[j];
         s[j] = c;
	};
};

#endif
