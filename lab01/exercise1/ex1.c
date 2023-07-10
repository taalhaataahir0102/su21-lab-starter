#include <string.h>
#include "ex1.h" 

/* Returns the number of times LETTER appears in STR.
There are two different ways to iterate through a string.
1st way hint: strlen() may be useful
2nd way hint: all strings end in a null terminator */
int num_occurrences(char *str, char letter) {
    /* TODO: implement num_occurances */
    int count = 0;
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == letter) {
            count++;
        }
    }
    return count;
}

/* Populates DNA_SEQ with the number of times each nucleotide appears.
Each sequence will end with a NULL terminator and will have up to 20 nucleotides.
All letters will be upper case. */
void compute_nucleotide_occurrences(DNA_sequence *dna_seq) {
    /* TODO: implement compute_nucleotide_occurances */
    int occurrences[4] = {0};

    char *sequence = dna_seq->sequence;
    while (*sequence != '\0') {
        switch (*sequence) {
            case 'A':
                occurrences[0]++;
                break;
            case 'C':
                occurrences[1]++;
                break;
            case 'G':
                occurrences[2]++;
                break;
            case 'T':
                occurrences[3]++;
                break;
            default:
                break;
        }
        sequence++;
    }

    dna_seq->A_count = occurrences[0];
    dna_seq->C_count = occurrences[1];
    dna_seq->G_count = occurrences[2];
    dna_seq->T_count = occurrences[3];
    return;
}
