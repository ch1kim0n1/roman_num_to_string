#include <iostream>

std::string numberToWords(int num) {
    if (num == 0) return "zero";

    std::string belowTwenty[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    std::string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    std::string thousands[] = {"", "thousand", "million", "billion"};

    std::string result = "";
    int i = 0;

    while (num > 0) {
        if (num % 1000 != 0) {
            std::string chunk = "";
            int n = num % 1000;

            if (n >= 100) {
                chunk += belowTwenty[n / 100] + " hundred ";
                n %= 100;
            }
            if (n >= 20) {
                chunk += tens[n / 10] + " ";
                n %= 10;
            }
            if (n > 0) {
                chunk += belowTwenty[n] + " ";
            }

            result = chunk + thousands[i] + " " + result;
        }
        num /= 1000;
        i++;
    }

    return result;
}

int romanToInt(const std::string& s) {
    int total = 0;
    int prevValue = 0;

    for (int i = s.size() - 1; i >= 0; --i) {
        int value = 0;
        switch (s[i]) {
            case 'I': value = 1; break;
            case 'V': value = 5; break;
            case 'X': value = 10; break;
            case 'L': value = 50; break;
            case 'C': value = 100; break;
            case 'D': value = 500; break;
            case 'M': value = 1000; break;
            default: return -1; // Invalid character
        }

        if (value < prevValue) {
            total -= value;
        } else {
            total += value;
        }
        prevValue = value;
    }

    return total;
}

int main() {
    std::string roman;
    std::cout << "Enter Roman numeral: ";
    std::cin >> roman;

    int result = romanToInt(roman);
    if (result == -1) {
        std::cout << "Invalid Roman numeral!" << std::endl;
    } else {
        std::cout << "Integer: " << result << std::endl;
        std::cout << "Word: " << numberToWords(result) << std::endl;
    }
    return 0;
}
