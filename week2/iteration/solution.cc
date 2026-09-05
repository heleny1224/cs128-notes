#include "solution.hpp"

int BatchSignature(int first, int last, int step) {
  // TODO: Sum the serials first, first + step, first + 2 * step, ... for
  // every serial that is at most last.
  int sum = 0;
  while (first <= last) {
    sum = sum + first;
    first = first + step;
  }
  return sum;
}

int DigitSum(int serial) {
  // TODO: Sum the decimal digits of serial with a loop that applies % and
  // / by a named digit-base constant (a bare 10 fails the clear-code
  // checks).
  int sum = 0;
  const int kDigi = 10;
  while (serial > 0) {
    sum = sum + serial % kDigi;
    serial = serial / kDigi;
  }
  return sum;
}

int ChecksumFolds(int serial) {
  // TODO: Count how many times the digit sum must be applied before the
  // value is a single digit. Calling your DigitSum is allowed.
  const int kDigi = 10;
  int count = 0;
  while (serial >= kDigi) {
    serial = DigitSum(serial);
    count = count + 1;
  }
  return count;
}
