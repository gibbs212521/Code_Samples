#include "test_findPrime.h"


void prime_test_suite()
{
    test_1_is_number_prime();
    // test_2_find_next_prime();
    // test_3_list_out_primes();
    // test_4_follows_prime_trends();
    test_1_uint_is_number_prime();
    // test_2_uint_list_out_primes();
    // test_3_uint_follows_prime_trends();
}



int known_primes_array[500] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,\
    37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107,\
    109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,\
    191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, \
    269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, \
    353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, \
    439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, \
    523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, \
    617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, \
    709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, \
    811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, \
    907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, \
    1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069,\
    1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, \
    1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, \
    1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, \
    1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, \
    1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, \
    1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, \
    1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, \
    1697, 1699, 1709, 1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, \
    1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, \
    1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, \
    1993, 1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069, \
    2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143, \
    2153, 2161, 2179, 2203, 2207, 2213, 2221, 2237, 2239, 2243, 2251, 2267, \
    2269, 2273, 2281, 2287, 2293, 2297, 2309, 2311, 2333, 2339, 2341, 2347, \
    2351, 2357, 2371, 2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423};

unsigned long known_uint_primes_array[500] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,\
    37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107,\
    109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,\
    191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, \
    269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, \
    353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, \
    439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, \
    523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, \
    617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, \
    709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, \
    811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, \
    907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, \
    1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069,\
    1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, \
    1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, \
    1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, \
    1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, \
    1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, \
    1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, \
    1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, \
    1697, 1699, 1709, 1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, \
    1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, \
    1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, \
    1993, 1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069, \
    2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143, \
    2153, 2161, 2179, 2203, 2207, 2213, 2221, 2237, 2239, 2243, 2251, 2267, \
    2269, 2273, 2281, 2287, 2293, 2297, 2309, 2311, 2333, 2339, 2341, 2347, \
    2351, 2357, 2371, 2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423};

void test_1_is_number_prime(){
    bool test_passed = true;
    bool condition;
    char test_name[] = "Is Prime Number Test";

    /// CASE 1
//  char _t_guide_[30] = "                             "
    char test_case[30] = "Compare to Known Primes      ";
//  char _method_guide[30] = "                         ";
    char method_tested[30] = "isPrime function         ";
    condition = true;
    int index_increment = 5;
    for (int i=0; i<350; i+=index_increment)
    {
        // condition = (condition && isPrime(known_primes_array[i]));
        condition = (condition && brute_force_prime(known_primes_array[i]));
        if (abs(condition-1))
            printf("\n\t%d claimed to not be prime", known_primes_array[i]);
    }
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 2
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Stack Push to Top            ");
    strcpy(method_tested,"Stack.push               ");
    
    // runTest(condition, method_tested, test_case, &test_passed);

    testResult(test_name,test_passed);
}

void test_2_find_next_prime(){
    bool test_passed = true;
    bool condition;
    char test_name[] = "Next Prime Test (incomplete)";

    // testResult(test_name,test_passed);
}

void test_3_list_out_primes(){
    bool test_passed = true;
    bool condition;
    char test_name[] = "List Out Primes Test";

    // testResult(test_name,test_passed);
}

void test_4_follows_prime_trends(){
    bool test_passed = true;
    bool condition;
    char test_name[] = "Follow Prime Trends Test";

    // testResult(test_name,test_passed);
}





void test_1_uint_is_number_prime(){
    bool test_passed = true;
    bool condition;
    char test_name[] = "Is Prime Uint Test";

    /// CASE 1
//  char _t_guide_[30] = "                             "
    char test_case[30] = "Compare to Known Primes      ";
//  char _method_guide[30] = "                         ";
    char method_tested[30] = "PrimeList function       ";
    condition = true;
    // making new brute force algorithm
    // struct StackBinHandler prime_stack;
    // _bin_initializeStack(&prime_stack);
    unsigned long prime_list[500]={};

    bool cond_test_value;

    // setPrimeListUint(prime_stack, 500);
    unsigned long list_run = 350;
    setPrimeListUint(prime_list, list_run);
    for (unsigned long i = 0; i < list_run; i++)
    {
        cond_test_value = prime_list[i] ^ known_uint_primes_array[i];
        if (abs(cond_test_value))
        condition = false;
    }
    
    runTest(condition, method_tested, test_case, &test_passed);

    /// CASE 2
//  strcpy(_t_guide_,"                             ");
    strcpy(test_case,"Stack Push to Top            ");
    strcpy(method_tested,"Stack.push               ");
    
    // runTest(condition, method_tested, test_case, &test_passed);

    testResult(test_name,test_passed);
}

void test_2_uint_list_out_primes(){
    bool test_passed = true;
    bool condition;
    char test_name[] = "List Out Primes Test";

    // testResult(test_name,test_passed);
}

void test_3_uint_follows_prime_trends(){
    bool test_passed = true;
    bool condition;
    char test_name[] = "Follow Prime Trends Test";

    // testResult(test_name,test_passed);
}






