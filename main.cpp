#include <iostream>
#include "bigint.hpp"

int main()
{
    std::cout << "=== Constructor Tests ===" << std::endl;
    bigint b0;
    bigint b1(123);
    bigint b2(456);
    bigint b3("99999999999999999999");
    
    std::cout << "b0 (default): " << b0 << std::endl;
    std::cout << "b1 (123): " << b1 << std::endl;
    std::cout << "b2 (456): " << b2 << std::endl;
    std::cout << "b3 (big string): " << b3 << std::endl;

    std::cout << "\n=== Addition Tests ===" << std::endl;
    std::cout << b1 << " + " << b2 << " = " << (b1 + b2) << std::endl;
    std::cout << "99 + 1 = " << (bigint(99) + bigint(1)) << std::endl;
    std::cout << "999 + 1 = " << (bigint(999) + bigint(1)) << std::endl;
    std::cout << "0 + 0 = " << (bigint(0) + bigint(0)) << std::endl;
    std::cout << "0 + 123 = " << (bigint(0) + bigint(123)) << std::endl;
    
    bigint big1("99999999999999999999");
    bigint big2("1");
    std::cout << big1 << " + " << big2 << " = " << (big1 + big2) << std::endl;

    std::cout << "\n=== Digit Shift Left (<<) Tests ===" << std::endl;
    std::cout << "42 << 3 = " << (bigint(42) << 3) << " (expected: 42000)" << std::endl;
    std::cout << "1 << 5 = " << (bigint(1) << 5) << " (expected: 100000)" << std::endl;
    std::cout << "0 << 3 = " << (bigint(0) << 3) << " (expected: 0)" << std::endl;
    std::cout << "123 << 0 = " << (bigint(123) << 0) << " (expected: 123)" << std::endl;

    std::cout << "\n=== Digit Shift Right (>>) Tests ===" << std::endl;
    std::cout << "1337 >> 2 = " << (bigint(1337) >> 2) << " (expected: 13)" << std::endl;
    std::cout << "42000 >> 3 = " << (bigint(42000) >> 3) << " (expected: 42)" << std::endl;
    std::cout << "123 >> 5 = " << (bigint(123) >> 5) << " (expected: 0)" << std::endl;
    std::cout << "0 >> 3 = " << (bigint(0) >> 3) << " (expected: 0)" << std::endl;
    std::cout << "123 >> 0 = " << (bigint(123) >> 0) << " (expected: 123)" << std::endl;

    std::cout << "\n=== Comparison Tests ===" << std::endl;
    std::cout << "123 == 123: " << (bigint(123) == bigint(123) ? "true" : "false") << " (expected: true)" << std::endl;
    std::cout << "123 == 456: " << (bigint(123) == bigint(456) ? "true" : "false") << " (expected: false)" << std::endl;
    std::cout << "123 != 456: " << (bigint(123) != bigint(456) ? "true" : "false") << " (expected: true)" << std::endl;
    std::cout << "123 < 456: " << (bigint(123) < bigint(456) ? "true" : "false") << " (expected: true)" << std::endl;
    std::cout << "456 < 123: " << (bigint(456) < bigint(123) ? "true" : "false") << " (expected: false)" << std::endl;
    std::cout << "123 > 456: " << (bigint(123) > bigint(456) ? "true" : "false") << " (expected: false)" << std::endl;
    std::cout << "456 > 123: " << (bigint(456) > bigint(123) ? "true" : "false") << " (expected: true)" << std::endl;
    std::cout << "99 < 100: " << (bigint(99) < bigint(100) ? "true" : "false") << " (expected: true)" << std::endl;
    std::cout << "100 <= 100: " << (bigint(100) <= bigint(100) ? "true" : "false") << " (expected: true)" << std::endl;
    std::cout << "100 >= 100: " << (bigint(100) >= bigint(100) ? "true" : "false") << " (expected: true)" << std::endl;
    std::cout << "99 <= 100: " << (bigint(99) <= bigint(100) ? "true" : "false") << " (expected: true)" << std::endl;
    std::cout << "100 >= 99: " << (bigint(100) >= bigint(99) ? "true" : "false") << " (expected: true)" << std::endl;

    std::cout << "\n=== Comparison with unsigned long int ===" << std::endl;
    std::cout << "bigint(123) == 123: " << (bigint(123) == 123 ? "true" : "false") << " (expected: true)" << std::endl;
    std::cout << "bigint(123) < 456: " << (bigint(123) < 456 ? "true" : "false") << " (expected: true)" << std::endl;
    std::cout << "bigint(456) > 123: " << (bigint(456) > 123 ? "true" : "false") << " (expected: true)" << std::endl;

    std::cout << "\n=== Increment Tests ===" << std::endl;
    bigint inc(99);
    std::cout << "inc = " << inc << std::endl;
    std::cout << "++inc = " << ++inc << " (expected: 100)" << std::endl;
    std::cout << "inc++ = " << inc++ << " (expected: 100)" << std::endl;
    std::cout << "inc after inc++ = " << inc << " (expected: 101)" << std::endl;

    std::cout << "\n=== Compound Assignment Tests ===" << std::endl;
    bigint ca(100);
    ca += bigint(50);
    std::cout << "100 += 50: " << ca << " (expected: 150)" << std::endl;
    ca += 10;
    std::cout << "then += 10: " << ca << " (expected: 160)" << std::endl;
    ca <<= 2;
    std::cout << "then <<= 2: " << ca << " (expected: 16000)" << std::endl;
    ca >>= 1;
    std::cout << "then >>= 1: " << ca << " (expected: 1600)" << std::endl;

    std::cout << "\n=== Copy Constructor and Assignment ===" << std::endl;
    bigint orig(12345);
    bigint copy1(orig);
    bigint copy2;
    copy2 = orig;
    std::cout << "orig: " << orig << std::endl;
    std::cout << "copy1 (copy constructor): " << copy1 << std::endl;
    std::cout << "copy2 (assignment): " << copy2 << std::endl;

    std::cout << "\n=== Edge Cases ===" << std::endl;
    std::cout << "bigint(0): " << bigint(0) << std::endl;
    std::cout << "bigint(\"0\"): " << bigint("0") << std::endl;
    std::cout << "bigint(\"000123\"): " << bigint("000123") << " (expected: 123)" << std::endl;

    std::cout << "\n=== All Tests Complete ===" << std::endl;
    return 0;
}