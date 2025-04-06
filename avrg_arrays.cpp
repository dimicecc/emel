#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int findMinIndex(const std::vector<int>& arr) {
    return std::min_element(arr.begin(), arr.end()) - arr.begin();
}

int findMaxIndex(const std::vector<int>& arr) {
    return std::max_element(arr.begin(), arr.end()) - arr.begin();
}

double averageOfEvens(const std::vector<int>& part) {
    int sum = 0, count = 0;
    for (int val : part) {
        if (val % 2 == 0) {
            sum += val;
            count++;
        }
    }
    return count == 0 ? 0.0 : static_cast<double>(sum) / count;
}

bool isValidArray(const std::vector<int>& arr) {
    if (arr.empty()) return false;

    int minVal = *std::min_element(arr.begin(), arr.end());
    int maxVal = *std::max_element(arr.begin(), arr.end());

    if (minVal == maxVal) return false;

    int minCount = std::count(arr.begin(), arr.end(), minVal);
    int maxCount = std::count(arr.begin(), arr.end(), maxVal);

    return minCount == 1 && maxCount == 1;
}

int main() {
    std::vector<int> arr;
    int n;

    std::cout << "Введите количество элементов: ";
    std::cin >> n;

    if (n < 3) {
        std::cerr << "Массив должен содержать минимум 3 элемента.\n";
        return 1;
    }

    std::cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        arr.push_back(val);
    }

    if (!isValidArray(arr)) {
        std::cerr << "Массив некорректен (одинаковые элементы или дубликаты минимума/максимума).\n";
        return 1;
    }

    int minIndex = findMinIndex(arr);
    int maxIndex = findMaxIndex(arr);

    int start = std::min(minIndex, maxIndex);
    int end = std::max(minIndex, maxIndex);

    std::vector<int> part1(arr.begin(), arr.begin() + start);
    std::vector<int> part2(arr.begin() + start + 1, arr.begin() + end);
    std::vector<int> part3(arr.begin() + end + 1, arr.end());

    std::cout << "Среднее чётных в части 1: " << averageOfEvens(part1) << "\n";
    std::cout << "Среднее чётных в части 2: " << averageOfEvens(part2) << "\n";
    std::cout << "Среднее чётных в части 3: " << averageOfEvens(part3) << "\n";

    return 0;
}
