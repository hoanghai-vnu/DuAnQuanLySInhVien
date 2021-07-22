#include "PhanSo.h"
#include "tuan.h"
#include "tuan.cpp"

template int add(int const& a, int const& b);
template double add(double const& a, double const& b);

template int sub(int const& a, int const& b);
template double sub(double const& a, double const& b);

template int multiple(int const& a, int const& b);
template double multiple(double const& a, double const& b);

template int divide(int const& a, int const& b);
template double divide(double const& a, double const& b);

template PhanSo add(PhanSo const& a, PhanSo const& b);
template PhanSo multiple(PhanSo const& a, PhanSo const& b);
