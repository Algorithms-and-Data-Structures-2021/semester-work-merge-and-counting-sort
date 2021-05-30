#include <fstream>      // ifstream, ofstream
#include <iostream>     // cout
#include <sstream>      // stringstream
#include <string>       // string, getline
#include <string_view>  // string_view
#include <random>       // mt19937_64, random_device
#include <chrono>       // system_clock

using namespace std;

// абсолютный путь до набора данных
static constexpr auto kDatasetPathQuickSort = string_view{PROJECT_DATASET_DIR_QUICK_SORT};
//static constexpr auto kDatasetPathSelection = string_view{PROJECT_DATASET_DIR_SELECTION_SORT};

int main() {
  //const auto pathToSelectionSort = string(kDatasetPathSelection);
  const auto pathToQuickSort = string(kDatasetPathQuickSort);
  cout << "Dataset path To Data Quick Sort: " << pathToQuickSort << endl;
  //cout << "Dataset path To Data SelectionSort: " << pathToSelectionSort << endl;


  vector<string> output_streams;
  output_streams.emplace_back("/100.csv");
  output_streams.emplace_back("/500.csv");
  output_streams.emplace_back("/1000.csv");
  output_streams.emplace_back("/5000.csv");
  output_streams.emplace_back("/10000.csv");
  output_streams.emplace_back("/50000.csv");
  output_streams.emplace_back("/100000.csv");
  output_streams.emplace_back("/500000.csv");
  output_streams.emplace_back("/1000000.csv");


  vector<int> integers = {100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000};

  while (!integers.empty()) {
    /*
    auto outputStreamSelectionSort01 = ofstream(pathToSelectionSort + "/01" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamSelectionSort02 = ofstream(pathToSelectionSort + "/02" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamSelectionSort03 = ofstream(pathToSelectionSort + "/03" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamSelectionSort04 = ofstream(pathToSelectionSort + "/04" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamSelectionSort05 = ofstream(pathToSelectionSort + "/05" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamSelectionSort06 = ofstream(pathToSelectionSort + "/06" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamSelectionSort07 = ofstream(pathToSelectionSort + "/07" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamSelectionSort08 = ofstream(pathToSelectionSort + "/08" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamSelectionSort09 = ofstream(pathToSelectionSort + "/09" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamSelectionSort10 = ofstream(pathToSelectionSort + "/10" + output_streams.front(), ios::ios_base::trunc);
    */
    auto outputStreamQuickSort01 = ofstream(pathToQuickSort + "/01" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamQuickSort02 = ofstream(pathToQuickSort + "/02" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamQuickSort03 = ofstream(pathToQuickSort + "/03" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamQuickSort04 = ofstream(pathToQuickSort + "/04" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamQuickSort05 = ofstream(pathToQuickSort + "/05" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamQuickSort06 = ofstream(pathToQuickSort + "/06" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamQuickSort07 = ofstream(pathToQuickSort + "/07" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamQuickSort08 = ofstream(pathToQuickSort + "/08" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamQuickSort09 = ofstream(pathToQuickSort + "/09" + output_streams.front(), ios::ios_base::trunc);
    auto outputStreamQuickSort10 = ofstream(pathToQuickSort + "/10" + output_streams.front(), ios::ios_base::trunc);

    const auto seed = chrono::system_clock::now().time_since_epoch().count();
    auto engine = mt19937(seed);  // без seed`а генератор будет выдавать одни и те же значения
    auto dist = uniform_int_distribution(0, 10000000);  // равновероятное распределение генерируемых чисел

    /*
    if (outputStreamSelectionSort01) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamSelectionSort01 << dist(engine) << ',';
      }
      outputStreamSelectionSort01 << dist(engine) << '\n';
    }

    if (outputStreamSelectionSort02) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamSelectionSort02 << dist(engine) << ',';
      }
      outputStreamSelectionSort02 << dist(engine) << '\n';
    }

    if (outputStreamSelectionSort03) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamSelectionSort03 << dist(engine) << ',';
      }
      outputStreamSelectionSort03 << dist(engine) << '\n';
    }

    if (outputStreamSelectionSort04) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamSelectionSort04 << dist(engine) << ',';
      }
      outputStreamSelectionSort04 << dist(engine) << '\n';
    }

    if (outputStreamSelectionSort05) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamSelectionSort05 << dist(engine) << ',';
      }
      outputStreamSelectionSort05 << dist(engine) << '\n';
    }

    if (outputStreamSelectionSort06) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamSelectionSort06 << dist(engine) << ',';
      }
      outputStreamSelectionSort06 << dist(engine) << '\n';
    }

    if (outputStreamSelectionSort07) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamSelectionSort07 << dist(engine) << ',';
      }
      outputStreamSelectionSort07 << dist(engine) << '\n';
    }

    if (outputStreamSelectionSort08) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamSelectionSort08 << dist(engine) << ',';
      }
      outputStreamSelectionSort08 << dist(engine) << '\n';
    }

    if (outputStreamSelectionSort09) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamSelectionSort09 << dist(engine) << ',';
      }
      outputStreamSelectionSort09 << dist(engine) << '\n';
    }

    if (outputStreamSelectionSort10) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamSelectionSort10 << dist(engine) << ',';
      }
      outputStreamSelectionSort10 << dist(engine) << '\n';
    }
    */

    if (outputStreamQuickSort01) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamQuickSort01 << dist(engine) << ',';
      }
      outputStreamQuickSort01 << dist(engine) << '\n';
    }

    if (outputStreamQuickSort02) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamQuickSort02 << dist(engine) << ',';
      }
      outputStreamQuickSort02 << dist(engine) << '\n';
    }

    if (outputStreamQuickSort03) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamQuickSort03 << dist(engine) << ',';
      }
      outputStreamQuickSort03 << dist(engine) << '\n';
    }

    if (outputStreamQuickSort04) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamQuickSort04 << dist(engine) << ',';
      }
      outputStreamQuickSort04 << dist(engine) << '\n';
    }

    if (outputStreamQuickSort05) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamQuickSort05 << dist(engine) << ',';
      }
      outputStreamQuickSort05 << dist(engine) << '\n';
    }

    if (outputStreamQuickSort06) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamQuickSort06 << dist(engine) << ',';
      }
      outputStreamQuickSort06 << dist(engine) << '\n';
    }

    if (outputStreamQuickSort07) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamQuickSort07 << dist(engine) << ',';
      }
      outputStreamQuickSort07 << dist(engine) << '\n';
    }

    if (outputStreamQuickSort08) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamQuickSort08 << dist(engine) << ',';
      }
      outputStreamQuickSort08 << dist(engine) << '\n';
    }

    if (outputStreamQuickSort09) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamQuickSort09 << dist(engine) << ',';
      }
      outputStreamQuickSort09 << dist(engine) << '\n';
    }

    if (outputStreamQuickSort10) {
      for (int counter = 0; counter < integers.front() - 1; counter++) {
        outputStreamQuickSort10 << dist(engine) << ',';
      }
      outputStreamQuickSort10 << dist(engine) << '\n';
    }

    integers.erase(integers.begin());
    output_streams.erase(output_streams.begin());
  }

  return 0;
}