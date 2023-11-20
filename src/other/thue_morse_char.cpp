#include <algorithm>
#include <vector>

using namespace std;

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

// unsigned int count_bits(int word) {
//     int number_of_bits = 0;
//     while (word) {
//         word /= 2;
//         ++number_of_bits;
//     }

//     return number_of_bits;
// }

bool can_be_decreased(vector<int> word) {
    int last_bit;
    int second_last_bit;
    while (word.size() > 1) {
        last_bit = word.end()[-1];
        second_last_bit = word.end()[-2];
        if ((last_bit == 1 && second_last_bit == 1) || (last_bit == 0 && second_last_bit == 0))
            return false;
        word.pop_back();
        word.pop_back();
    }

    return true;
}

// unsigned int mirror_bits(unsigned int word, int number_of_bits) {
//     unsigned int mirrored_word = 0;
//     while (number_of_bits > 0) {
//         mirrored_word += word & 1;
//         --number_of_bits;
//     }

//     return mirrored_word;
// }

vector<int> undo_thue_morse_case_one(vector<int> word) {
    vector<int> new_word;
    int last_bit;
    int second_last_bit;
    while (word.size() > 1) {
        last_bit = word.end()[-1];
        second_last_bit = word.end()[-2];
        if (last_bit == 0 && second_last_bit == 1) {  // 10 -> 1
            new_word.push_back(1);
        } else if (last_bit == 1 && second_last_bit == 0)  // 01 -> 0
            word.pop_back();
        word.pop_back();
    }

    if (word.size() == 1) {
        if (word[0] == 0) {  // 10...
            new_word.push_back(1);
        } else
            new_word.push_back(0);
    }

    // reverse(new_word.begin(), new_word.end());

    return new_word;
}

vector<int> undo_thue_morse_case_two(vector<int> word) {
    vector<int> new_word;
    int last_bit;
    int second_last_bit;

    if (word.end()[-1] == 1) {  // ...10
        new_word.push_back(1);
    } else
        new_word.push_back(0);

    while (word.size() > 1) {
        last_bit = word.end()[-1];
        second_last_bit = word.end()[-2];
        if (last_bit == 0 && second_last_bit == 1) {  // 10 -> 1
            new_word.push_back(1);
        } else if (last_bit == 1 && second_last_bit == 0)  // 01 -> 0
            word.pop_back();
        word.pop_back();
    }

    // reverse(new_word.begin(), new_word.end());

    return new_word;
}

unsigned int undo_thue_morse_case_two_old(unsigned int word, int number_of_bits) {
    int last_two_bits;
    unsigned int new_word;
    int new_bits = 0;

    if (number_of_bits == 1) {
        new_word *= 2;
        ++new_bits;
        if (word & 1 == 1) {  // ...10
            new_word += 1;
        }
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

    return new_word;
}

bool is_thue_morse_subword(vector<int> word) {
    // int last_two_bits;
    // vector<int> new_word;
    while (word.size() > 2) {
        bool case_one = can_be_decreased(word);  // case 1: ... 2 2 2
        if (case_one) {
            word = undo_thue_morse_case_one(word);
            continue;
        }
        vector<int> word_pop = word;
        word_pop.pop_back();
        bool case_two = can_be_decreased(word_pop);  // case 2: ... 2 2 1
        if (case_two) {
            word = undo_thue_morse_case_two(word);
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
        vector<int> word;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k <= 1; ++k) {
                word.push_back(k);
            }
        }
        if (is_thue_morse_subword(word))
            ++count;
    }

    return count;
}

#include <iostream>

int main() {
    std::cout << count_subwords(3);
}