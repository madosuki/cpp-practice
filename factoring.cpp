
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<int> GetPrimeCollection(const int &n)
{

  std::vector<int> tmp = {};
  std::vector<int> result = {};
  const int period = sqrt(n);

  
  for(int i = 2; i <= n; ++i) {
    tmp.push_back(i);
  }

  int index = 0;

  while(true)
    {

      if(tmp[0] >= period) {
        result.insert(result.end(),
                      std::make_move_iterator(tmp.begin()), std::make_move_iterator(tmp.end()));

        return result;
      }
      
      result.push_back(tmp[0]);

      int target = tmp[0];
      
      auto a = std::remove_if(tmp.begin(), tmp.end(), [target](int x) { return x % target == 0; });
      
      tmp.erase(a, tmp.end());

      ++index;
    }

  
}


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
std::string fact_in_prime(const int &num, const std::vector<int> &prime, const int& point, std::string r) {

  if((int)prime.size() == point) {
    auto fr = r.substr(3);
    return fr;
  }
  
  if((num % prime[point]) == 0) {
    int result = num / prime[point];
    std::string o = r + " * " + std::to_string(prime[point]);
    return fact_in_prime(result, prime, point, o);
  } else {
    return fact_in_prime(num, prime, (point + 1), r);
  }
}

int main() {
  // 素数コレクション。適当。
  // constexpr std::array<int, 10> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

  auto list = GetPrimeCollection(128);
  for(const auto &i : list) {
    std::cout << i << "\n";
  }
  
  // 素因数分解したい数。
  constexpr int num = 600;
    
  std::string result = fact_in_prime(num, list, 0, "");
  std::string finalresult = shape(result);
  printf("素因数分解 整形前 %s\n", result.c_str());
  printf("素因数分解 整形後 %s\n", finalresult.c_str());
  
  return 0;
}
