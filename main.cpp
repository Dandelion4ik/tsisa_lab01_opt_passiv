#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

void print(const double N, const double sigma, const double znach) {
  std::cout << '|' << std::setw(5) << std::right << N << '|' << std::setw(5)
            << std::right << std::setprecision(3) << znach << "+-"
            << std::setw(5) << std::left << sigma << '|' << std::endl;
}

double func(const double &coordinat) {
  return (-sqrt(coordinat) * sin(coordinat) + 2);
}

void opt_pass(double &a, double &b, const double &eps) {
  double N = 1;
  while ((b - a) / (N + 1) >= eps) {
    std::vector<std::pair<double, double>> coord_znach = {};
    for (auto k = 1; k <= N; ++k) {
      double coordinat = ((b - a) / (N + 1)) * k + a;
      std::pair<double, double> min{coordinat, func(coordinat)};
      coord_znach.push_back(min);
    }
    auto v = std::min_element(
        coord_znach.begin(), coord_znach.end(),
        [](std::pair<double, double> lhs, std::pair<double, double> rhs) {
          return lhs.second < rhs.second;
        });
    double sigma = (b - a) / (N + 1);
    print(N, sigma, v->first);
    N++;
  }
}

int main() {
  double a = 1;
  double b = 4;
  const double eps = 0.1;
  opt_pass(a, b, eps);
  return 0;
}
