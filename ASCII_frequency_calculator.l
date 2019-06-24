%{
    #include "cJSON/cJSON.h"
    
    #define ASCII_CHARACTERS 128
    int ASCII_frequencies[ASCII_CHARACTERS];         
%}

%%

\0              { ASCII_frequencies['\0']++; }
\a              { ASCII_frequencies['\a']++; }
\b              { ASCII_frequencies['\b']++; }
\t              { ASCII_frequencies['\t']++; }
\n              { ASCII_frequencies['\n']++; }
\v              { ASCII_frequencies['\v']++; }
\f              { ASCII_frequencies['\f']++; }
\r              { ASCII_frequencies['\r']++; }
" "             { ASCII_frequencies[' ']++;  }
!               { ASCII_frequencies['!']++;  }
\"              { ASCII_frequencies['"']++;  }
#               { ASCII_frequencies['#']++;  }
\$              { ASCII_frequencies['$']++;  }
%               { ASCII_frequencies['%']++;  }
&               { ASCII_frequencies['&']++;  }
\'              { ASCII_frequencies['\'']++; }
\(              { ASCII_frequencies['(']++;  }
\)              { ASCII_frequencies[')']++;  }
\*              { ASCII_frequencies['*']++;  }
\+              { ASCII_frequencies['+']++;  }
,               { ASCII_frequencies[',']++;  }
\-              { ASCII_frequencies['-']++;  }
\.              { ASCII_frequencies['.']++;  }
\/              { ASCII_frequencies['/']++;  }
0               { ASCII_frequencies['0']++;  }
1               { ASCII_frequencies['1']++;  }
2               { ASCII_frequencies['2']++;  }
3               { ASCII_frequencies['3']++;  }
4               { ASCII_frequencies['4']++;  }
5               { ASCII_frequencies['5']++;  }
6               { ASCII_frequencies['6']++;  }
7               { ASCII_frequencies['7']++;  }
8               { ASCII_frequencies['8']++;  }
9               { ASCII_frequencies['9']++;  }
:               { ASCII_frequencies[':']++;  }
;               { ASCII_frequencies[';']++;  }
\<              { ASCII_frequencies['<']++;  }
=               { ASCII_frequencies['=']++;  }
\>              { ASCII_frequencies['>']++;  }
\?              { ASCII_frequencies['?']++;  }
@               { ASCII_frequencies['@']++;  }
A               { ASCII_frequencies['A']++;  }
B               { ASCII_frequencies['B']++;  }
C               { ASCII_frequencies['C']++;  }
D               { ASCII_frequencies['D']++;  }
E               { ASCII_frequencies['E']++;  }
F               { ASCII_frequencies['F']++;  }
G               { ASCII_frequencies['G']++;  }
H               { ASCII_frequencies['H']++;  }
I               { ASCII_frequencies['I']++;  }
J               { ASCII_frequencies['J']++;  }
K               { ASCII_frequencies['K']++;  }
L               { ASCII_frequencies['L']++;  }
M               { ASCII_frequencies['M']++;  }
N               { ASCII_frequencies['N']++;  }
O               { ASCII_frequencies['O']++;  }
P               { ASCII_frequencies['P']++;  }
Q               { ASCII_frequencies['Q']++;  }
R               { ASCII_frequencies['R']++;  }
S               { ASCII_frequencies['S']++;  }
T               { ASCII_frequencies['T']++;  }
U               { ASCII_frequencies['U']++;  }
V               { ASCII_frequencies['V']++;  }
W               { ASCII_frequencies['W']++;  }
X               { ASCII_frequencies['X']++;  }
Y               { ASCII_frequencies['Y']++;  }
Z               { ASCII_frequencies['Z']++;  }
\[              { ASCII_frequencies['[']++;  }
\\              { ASCII_frequencies['\\']++; }
\]              { ASCII_frequencies[']']++;  }
\^              { ASCII_frequencies['^']++;  }
_               { ASCII_frequencies['_']++;  }
`               { ASCII_frequencies['`']++;  }
a               { ASCII_frequencies['a']++;  }
b               { ASCII_frequencies['b']++;  }
c               { ASCII_frequencies['c']++;  }
d               { ASCII_frequencies['d']++;  }
e               { ASCII_frequencies['e']++;  }
f               { ASCII_frequencies['f']++;  }
g               { ASCII_frequencies['g']++;  }
h               { ASCII_frequencies['h']++;  }
i               { ASCII_frequencies['i']++;  }
j               { ASCII_frequencies['j']++;  }
k               { ASCII_frequencies['k']++;  }
l               { ASCII_frequencies['l']++;  }
m               { ASCII_frequencies['m']++;  }
n               { ASCII_frequencies['n']++;  }
o               { ASCII_frequencies['o']++;  }
p               { ASCII_frequencies['p']++;  }
q               { ASCII_frequencies['q']++;  }
r               { ASCII_frequencies['r']++;  }
s               { ASCII_frequencies['s']++;  }
t               { ASCII_frequencies['t']++;  }
u               { ASCII_frequencies['u']++;  }
v               { ASCII_frequencies['v']++;  }
w               { ASCII_frequencies['w']++;  }
x               { ASCII_frequencies['x']++;  }
y               { ASCII_frequencies['y']++;  }
z               { ASCII_frequencies['z']++;  }
\{              { ASCII_frequencies['{']++;  }
\|              { ASCII_frequencies['|']++;  }
\}              { ASCII_frequencies['}']++;  }
~               { ASCII_frequencies['~']++;  }

%%


void main()
{
    yylex();

    // The code below was taken from (cJSON) https://github.com/DaveGamble/cJSON/tree/3c8935676a97c7c97bf006db8312875b4f292f6c
    cJSON *output = cJSON_CreateObject();

    cJSON *char_freq_enteries = cJSON_AddArrayToObject(output, "chars_and_frequencies");
    if(char_freq_enteries == NULL)
    {
        printf("Could not create the root JSON object or the JSON array\n");
        exit(0);
    }

    cJSON *entry;
    for(int i = 0; i < ASCII_CHARACTERS; i++)
    {
        if(ASCII_frequencies[i])
        {
            entry = cJSON_CreateObject();

            char c[1] = {i};    
            if(cJSON_AddStringToObject(entry, "character", c) == NULL)
            {
                printf("Could not create a JSON object or add a string item to the object");
                exit(0);
            }

            if(cJSON_AddNumberToObject(entry, "frequency", ASCII_frequencies[i]) == NULL)
            {
                printf("Could not add a number item to the object");
                exit(0);
            }

            cJSON_AddItemToArray(char_freq_enteries, entry);
        }
    }
    //*************************************************************************************************************

    FILE *fptr = fopen("frequencies_of_chars.json", "w");
    if(fptr == NULL)
    {
        printf("Could not open the file\n");
        exit(0);
    }
    fprintf(fptr, "%s", cJSON_Print(output));
    fclose(fptr);

    cJSON_Delete(output);

    //printf("I'm at the end zinah, so far seems so good\n");

}