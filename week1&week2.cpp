// Declaration: creating a name oject
#include <iostream>

int main() {
  bool is_enrolled = false;
  char letter_grade = 'a';
  int credit_hours = 3;
  double gpa = 3.98;

  std::cout << "is_enrolled: " << is_enrolled << std::endl;
  std::cout << "letter_grade: " << letter_grade << std::endl;
  std::cout << "credit_hours: " << credit_hours + 1 << std::endl;
  std::cout << "gpa: " << gpa << std::endl;

  return 0;
}


// Constants
//Naming convention: Constants are named with a leading k followed by mixed case
constexpr double kP = 10.2;
const int kH = 5;


//Scope
//A scope is the region of the program in which a name has meaning, and curly braces delimit it
constexpr int kA = 10;
int main() {
  int b = kA + 2;
  {
    int c = 8;
    b = b + c;
  }
  return 0;
}

//Type conversions
int a = static_cast<int>('A');


//Expressions and statements
//std::cout writes true as 1 and false as 0.

//Selection
switch (grade) {
  case 'A':
  case 'B':
    std::cout << "passed with distinction" << std::endl;
    break;
  case 'C':
    std::cout << "passed" << std::endl;
    break;
  default:
    std::cout << "not passed" << std::endl;
    break;
}
//fall through: A break statement leaves the switch. Without it, execution continues into the next label's statements, and that continuation is called fall-through.


//The ternary operator
//The ternary operator ?: is selection inside an expression. It takes three operands, written condition ? value_if_true : value_if_false
#include <iostream>

int main() {
  const int kPassBand = 70;
  const int kQuizScore = 82;

  char band_mark = (kQuizScore >= kPassBand) ? 'p' : 'f';
  double bonus_rate = (kQuizScore >= kPassBand) ? 1.5 : 1;

  std::cout << "mark: " << band_mark << std::endl;
  std::cout << "rate: " << bonus_rate << std::endl;

  return 0;
}
//mark: p
//rate: 1.5


//iteration
//The do-while statement
#include <iostream>

int main() {
  int fuel = 0;

  while (fuel > 0) {
    std::cout << "while body ran" << std::endl;
  }
  std::cout << "while never ran with fuel = " << fuel << std::endl;

  do {
    std::cout << "do-while body ran once" << std::endl;
  } while (fuel > 0);

  return 0;
}
//while never ran with fuel = 0
//do-while body ran once



//break and continue
//break     → leave loop/switch
//continue  → skip to next loop iteration
#include <iostream>

int main() {
  const int kSearchLimit = 10;
  const int kMultiple = 4;
  for (int i = 1; i <= kSearchLimit; ++i) {
    if (i % kMultiple == 0) {
      std::cout << "break: found " << i << ", leaving" << std::endl;
      break;
    }
    std::cout << "break: checked " << i << std::endl;
  }

  const int kSkipLimit = 6;
  for (int i = 1; i <= kSkipLimit; ++i) {
    if (i % 2 == 0) {
      continue;
    }
    std::cout << "continue: kept " << i << std::endl;
  }
  std::cout << "after both loops" << std::endl;
  return 0;
}

/*
break: checked 1
break: checked 2
break: checked 3
break: found 4, leaving
continue: kept 1
continue: kept 3
continue: kept 5
after both loops
*/

