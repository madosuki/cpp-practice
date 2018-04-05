#include <iostream>
#include <array>
#include <string>

// 整形
std::string shape(const std::string& str) {
    char pre;
    std::string r = "";
    int count = 1;
    int power = 1;
    for(const auto& n : str) {
        if(count == 1) {
            pre = n;
            r = r + n;
        } else if(pre == n && n != '*' && n != ' ') {
            power++;
            if(str.size() == count) {
                r = r + "^" + std::to_string(power);
            }
        } else if(pre != n && n != '*' && n != ' ') {
            if(power != 1) {
                r = r + "^" + std::to_string(power) + " * " + n;
                power = 1;
            } else {
                r = r + " * " + n;
            }
            pre = n;
        }

        count++;
    }

    return r;
}

// 素因数分解関数
std::string factoring(const int &num, std::array<int, 10> prime, const int& point, std::string r) {
    if((num % prime[point]) == 0) {
        int result = num / prime[point];
        std::string o = r + " * " + std::to_string(prime[point]);
        return factoring(result, prime, point, o);
    } else if((int)prime.size() == point) {
        std::string fr = r.substr(3);
        return fr;
    } else {
        return factoring(num, prime, (point + 1), r);
    }
}

int main() {
    // 素数コレクション。適当。
    constexpr std::array<int, 10> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    
    // 素因数分解したい数。
    constexpr int num = 600;
    
    std::string result = factoring(num, prime, 0, "");
    std::string finalresult = shape(result);
    printf("素因数分解 整形前 %s\n", result.c_str());
    printf("素因数分解 整形後 %s\n", finalresult.c_str());
    return 0;
}
