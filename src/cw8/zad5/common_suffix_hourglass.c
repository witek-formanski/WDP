/*
T(n) = O(n)
M(n) = O(1)
*/

typedef struct elem elem;

struct elem {
    int val;
    elem* next;
};

typedef elem* list;

list get_common_suffix(list l, list m) {

}

/*
prefiks l = x
prefiks m = y
wspólny sufiks = z

pointer i niech przejdzie przez całe l,
a potem przez początek m, czyli:
x + z + y
pointer j niech przejdzie przez całe m,
a potem przez początek l, czyli:
y + z + x

więc spotkają się na początku wspólnego sufiksu


*/