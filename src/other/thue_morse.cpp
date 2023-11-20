/*
0 -> 01
1 -> 10

0
01
0110
01101001
0110100110010110

https://math.stackexchange.com/questions/4342938/subwords-of-the-thue-morse-sequence#:~:text=The%20Thue%2DMorse%20sequence%20can,0%20and%2010%20by%201.


101000011010
10 10 00 01 10 10
01 01 00 00 11 01 01

*/

unsigned int count_bits(int word) {
    int number_of_bits = 0;
    while (word) {
        word /= 2;
        ++number_of_bits;
    }

    return number_of_bits;
}

bool can_be_decreased(int word, unsigned int number_of_bits) {
    int last_two_bits;
    while (number_of_bits > 1) {
        last_two_bits = word & 3;
        if (last_two_bits == 3 || last_two_bits == 0)
            return false;
        word /= 4;
        number_of_bits -= 2;
    }

    return true;
}

unsigned int mirror_bits(unsigned int word, int number_of_bits) {
    unsigned int mirrored_word = 0;
    while (number_of_bits > 0) {
        mirrored_word += word & 1;
        --number_of_bits;
    }

    return mirrored_word;
}

unsigned int undo_thue_morse_case_one(unsigned int word, int number_of_bits) {
    int last_two_bits;
    unsigned int new_word;
    int new_bits = 0;
    while (number_of_bits > 1) {
        last_two_bits = word & 3;
        new_word *= 2;
        ++new_bits;
        if (last_two_bits == 2) {  // 10 -> 1
            new_word += 1;
        }
        // else // if (last_two_bits == 1) // 01 -> 0
        word /= 4;
        number_of_bits -= 2;
    }

    if (number_of_bits == 1) {
        new_word *= 2;
        ++new_bits;
        if (word & 1 == 0) {  // 10...
            new_word += 1;
        }
    }

    return mirror_bits(new_word, number_of_bits);
}

unsigned int undo_thue_morse_case_two(unsigned int word, int number_of_bits) {
    int last_two_bits;
    unsigned int new_word;
    int new_bits = 0;

    new_word *= 2;
    ++new_bits;
    if (word & 1 == 1) {  // ...10
        new_word += 1;
    }

    while (number_of_bits > 1) {
        last_two_bits = word & 3;
        new_word *= 2;
        ++new_bits;
        if (last_two_bits == 2) {  // 10 -> 1
            new_word += 1;
        }
        // else // if (last_two_bits == 1) // 01 -> 0
        word /= 4;
        number_of_bits -= 2;
    }

    if (number_of_bits == 1) {
        new_word *= 2;
        ++new_bits;
        if (word & 1 == 0) {  // 10...
            new_word += 1;
        }
    }

    return mirror_bits(new_word, number_of_bits);
}

bool is_thue_morse_subword(int word) {
    int last_two_bits;
    int new_word = 0;
    unsigned int number_of_bits = count_bits(word);
    while (number_of_bits > 2) {
        bool case_one = can_be_decreased(word, number_of_bits);  // case 1: ... 2 2 2
        if (case_one) {
            word = undo_thue_morse_case_one(word, number_of_bits);
            continue;
        }
        bool case_two = can_be_decreased(word / 2, number_of_bits - 1);  // case 2: ... 2 2 1
        if (case_two) {
            word = undo_thue_morse_case_two(word, number_of_bits);
            continue;
        }
        /*if (!case_one && !case_two)*/ return false;
    }
    return true;

    // if (number_of_bits % 2 == 0) {
    //     //  2 2 2 2
    //     // 1 2 2 2 1
    // } else {
    //     // 1 2 2 2
    //     // 2 2 2 1
    // }
}

int count_subwords(unsigned int n) {
    int count = 0;
    for (int i = 0; i < 1 << n; ++i) {
        if (is_thue_morse_subword(i))
            ++count;
    }

    return count;
}

#include <iostream>

int main() {
    std::cout << count_subwords(14);
}