#include <stdlib.h>

typedef struct
{
    int length;
    double *elements;
} sequence;

typedef struct
{
    sequence *seq;
    sequence_of_sequences *next;
} sequence_of_sequences;

sequence *differential_sequence(sequence *seq)
{
    sequence *diff_seq = (sequence *)malloc(sizeof(sequence));
    diff_seq->length = seq->length - 1;
    double *l; //= //malloc
    diff_seq->elements = l;
    // for..
    return diff_seq;
}