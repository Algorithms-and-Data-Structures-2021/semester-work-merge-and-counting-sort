#include "qsort.hpp"
#include <vector>

namespace itis {

  using namespace std;

  // Вычсление опорного элемента (pivot) через медиану, первого, среднего и последнего элементов.
  int calculationPivot(int low, int mid, int high) {
    int tmp;
    if (mid < low) {
      tmp = low;
      low = mid;
      mid = tmp;
    }
    if (high < low) {
      tmp = low;
      low = high;
      high = tmp;
    }
    if (high < mid) {
      tmp = high;
      high = mid;
      mid = tmp;
    }
    return mid;
  }

  int qsortRecursive(vector<int> &mas, int size) {

    // Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    // Опорный элемент массива
    int pivot = calculationPivot(mas[i], mas[(i + j) / 2], mas[j]);

    // Делим массив
    while (i <= j) {
      // Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
      // В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
      while (mas[i] < pivot) {
        i++;
      }
      // В правой части пропускаем элементы, которые больше центрального
      while (mas[j] > pivot) {
        j--;
      }
      // Меняем элементы местами
      if (i <= j) {
        int tmp = mas[i];
        mas[i] = mas[j];
        mas[j] = tmp;
        i++;
        j--;
      }
    }

    // Рекурсивные вызовы, если осталось, что сортировать
    if (j > 0) {
      // "Левый кусок"
      qsortRecursive(mas, j + 1);
    }
    if (i < size) {
      // "Првый кусок"
      qsortRecursive(mas, size - i);
    }
  }
}  // namespace itis