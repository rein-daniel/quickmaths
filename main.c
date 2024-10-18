#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int length;
  float *args;
} FloatArguments;

void print_manual();
FloatArguments convert_arguments_to_floats(int argc, char **argv);

int pi();
int euler();

int addition(FloatArguments args);
int subtraction(FloatArguments args);
int multiplication(FloatArguments args);
int division(FloatArguments args);

int square_root(FloatArguments args);
int cube_root(FloatArguments args);

int natural_logarithm(FloatArguments args);
int base_2_logarithm(FloatArguments args);
int common_logarithm(FloatArguments args);

int sine(FloatArguments args);
int hyperbolic_sine(FloatArguments args);
int arc_sine(FloatArguments args);

int cosine(FloatArguments args);
int hyperbolic_cosine(FloatArguments args);
int arc_cosine(FloatArguments args);

int tangent(FloatArguments args);
int hyperbolic_tangent(FloatArguments args);
int arc_tangent(FloatArguments args);

int cotangent(FloatArguments args);
int hyperbolic_cotangent(FloatArguments args);
int arc_cotangent(FloatArguments args);

int secant(FloatArguments args);
int hyperbolic_secant(FloatArguments args);
int arc_secant(FloatArguments args);

// TODO cosecant

int is_prime(FloatArguments args);

int factorial(FloatArguments args);

int main(int argc, char **argv) {
  if (argc < 2) {
    print_manual();
    return 0;
  }

  // commands
  char *cmd = argv[1];
  if (strcmp(cmd, "pi") == 0) {
    return pi();
  }
  if (strcmp(cmd, "euler") == 0 || strcmp(cmd, "e") == 0) {
    return euler();
  }
  if (strcmp(cmd, "add") == 0 || strcmp(cmd, "sum") == 0) {
    return addition(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "sub") == 0 || strcmp(cmd, "subtract") == 0 ||
      strcmp(cmd, "difference") == 0) {
    return subtraction(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "mul") == 0 || strcmp(cmd, "multiply") == 0 ||
      strcmp(cmd, "product") == 0) {
    return multiplication(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "div") == 0 || strcmp(cmd, "divide") == 0) {
    return division(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "sqrt") == 0 || strcmp(cmd, "square_root") == 0) {
    return square_root(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "cbrt") == 0 || strcmp(cmd, "cube_root") == 0) {
    return cube_root(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "ln") == 0 || strcmp(cmd, "nat_log") == 0 ||
      strcmp(cmd, "natural_logarithm") == 0 || strcmp(cmd, "log_e") == 0) {
    return natural_logarithm(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "log2") == 0 || strcmp(cmd, "log_base_2") == 0 ||
      strcmp(cmd, "logarithm_base_2") == 0) {
    return base_2_logarithm(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "log10") == 0 || strcmp(cmd, "log") == 0 ||
      strcmp(cmd, "log_base_10") == 0 ||
      strcmp(cmd, "logarithm_base_10") == 0 ||
      strcmp(cmd, "common_logarithm") == 0) {
    return common_logarithm(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "sin") == 0 || strcmp(cmd, "sine") == 0) {
    return sine(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "sinh") == 0 || strcmp(cmd, "hyperbolic_sine") == 0) {
    return hyperbolic_sine(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "asin") == 0 || strcmp(cmd, "arc_sine") == 0) {
    return arc_sine(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "cos") == 0 || strcmp(cmd, "cosine") == 0) {
    return cosine(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "cosh") == 0 || strcmp(cmd, "hyperbolic_cosine") == 0) {
    return hyperbolic_cosine(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "acos") == 0 || strcmp(cmd, "arc_cosine") == 0) {
    return arc_cosine(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "tan") == 0 || strcmp(cmd, "tangent") == 0) {
    return tangent(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "tanh") == 0 || strcmp(cmd, "hyperbolic_tangent") == 0) {
    return hyperbolic_tangent(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "atan") == 0 || strcmp(cmd, "arc_tangent") == 0) {
    return arc_tangent(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "cot") == 0 || strcmp(cmd, "cotangent") == 0) {
    return cotangent(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "coth") == 0 || strcmp(cmd, "hyperbolic_cotangent") == 0) {
    return hyperbolic_cotangent(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "acot") == 0 || strcmp(cmd, "arc_cotangent") == 0) {
    return arc_cotangent(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "sec") == 0 || strcmp(cmd, "secant") == 0) {
    return secant(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "sech") == 0 || strcmp(cmd, "hyperbolic_secant") == 0) {
    return hyperbolic_secant(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "asec") == 0 || strcmp(cmd, "arc_secant") == 0) {
    return arc_secant(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "prime") == 0 || strcmp(cmd, "is_prime") == 0) {
    return is_prime(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "fact") == 0 || strcmp(cmd, "factorial") == 0) {
    return factorial(convert_arguments_to_floats(argc, argv));
  }

  if (argc == 2) {
    printf("its an expression\n");
    return 0;
  }

  printf("ERROR: could not parse arguments\n");
  printf("expected expression but found too many arguments\n");
  printf("either you are trying to execute a command which does not exist or "
         "your expression has invalid syntax\n");
  printf("expressions must be encapsulated with quotes: qm '632 * 7 - 23'\n");

  return 1;
}

FloatArguments convert_arguments_to_floats(int argc, char **argv) {
  FloatArguments result;
  result.length = argc - 2;
  result.args = malloc(result.length);
  for (int i = 2; i < argc; ++i) {
    result.args[i - 2] = strtod(argv[i], NULL);
  }

  return result;
}

void print_manual() {
  printf("-- quickmaths --\n");
  printf("usage:\n");
  printf("qm EXPRESSION -- or -- qm COMMAND ARGUMENT_1 ... ARGUMENT_N\n");
  printf("example:\n");
  printf("qm '5 * 5 - 19'\n");
  printf("qm sum 6 7 8 9 10\n");
  printf("qm help for more information\n");
}

// commands
//
// TODO input: mode + number
// root (2, ...)
// log (10, ...)
//
// input: vector <1, 2, 3>
//
// input: vector list <1, 2> <3, 4> OR 2 <1, 4> => <2, 8>
//
// input: matrix {<1, 2, 3>, <2, 4, 6>}
//
// input: matrix list
//
// TODO statistics:
// mean
// std / standard_deviation
// var / variance
//
// TODO functions:
// roots / zeros / zeroes
// integral
// derivative
//
// TODO
// lim / limes
// derivative
// anti_derivative

int pi() {
  printf("Result: %f\n", M_PI);
  return 0;
}

int euler() {
  printf("Result: %f\n", M_E);
  return 0;
}

int addition(FloatArguments args) {
  float result = 0;
  for (int i = 0; i < args.length; ++i) {
    result = result + args.args[i];
  }
  printf("Result: %f\n", result);
  return 0;
}

int subtraction(FloatArguments args) {
  if (args.length == 0) {
    printf("Result: %d\n", 0);
    return 0;
  }

  float result = args.args[0];
  for (int i = 1; i < args.length; ++i) {
    result = result - args.args[i];
  }
  printf("Result: %f\n", result);
  return 0;
}

int multiplication(FloatArguments args) {
  float result = 1;
  for (int i = 0; i < args.length; ++i) {
    result = result * args.args[i];
  }
  printf("Result: %f\n", result);
  return 0;
}

int division(FloatArguments args) {
  if (args.length != 2) {
    printf("ERROR: division expects 2 arguments but got %d\n", args.length);
    return 1;
  }

  if (args.args[1] == 0) {
    printf("ERROR: cannot divide by zero\n");
    return 1;
  }

  float result = 0;
  result = (args.args[0] / args.args[1]);
  printf("Result: %f\n", result);
  return 0;
}

int square_root(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: square_root expects 1 argument but got %d\n", args.length);
    return 1;
  }

  printf("Result: %f\n", sqrt(args.args[0]));
  return 0;
}

int cube_root(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: qube_root expects 1 argument but got %d\n", args.length);
    return 1;
  }

  printf("Result: %f\n", cbrt(args.args[0]));
  return 0;
}

int natural_logarithm(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: natural_logarithm expects 1 argument but got %d\n",
           args.length);
    return 1;
  }

  printf("Result: %f\n", log(args.args[0]));
  return 0;
}

int base_2_logarithm(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: base_2_logarithm expects 1 argument but got %d\n",
           args.length);
    return 1;
  }

  printf("Result: %f\n", log2(args.args[0]));
  return 0;
}

int common_logarithm(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: common_logarithm expects 1 argument but got %d\n",
           args.length);
    return 1;
  }

  printf("Result: %f\n", log10(args.args[0]));
  return 0;
}

int sine(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: sine expects 1 argument but got %d\n", args.length);
    return 1;
  }

  printf("Result: %f\n", sin(args.args[0]));
  return 0;
}

int hyperbolic_sine(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: hyperbolic_sine expects 1 argument but got %d\n",
           args.length);
    return 1;
  }

  printf("Result: %f\n", sinh(args.args[0]));
  return 0;
}

int arc_sine(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: arc_sine expects 1 argument but got %d\n", args.length);
    return 1;
  }

  printf("Result: %f\n", asin(args.args[0]));
  return 0;
}

int cosine(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: cosine expects 1 argument but got %d\n", args.length);
    return 1;
  }

  printf("Result: %f\n", cos(args.args[0]));
  return 0;
}

int hyperbolic_cosine(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: hyperbolic_cosine expects 1 argument but got %d\n",
           args.length);
    return 1;
  }

  printf("Result: %f\n", cosh(args.args[0]));
  return 0;
}

int arc_cosine(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: arc_cosine expects 1 argument but got %d\n", args.length);
    return 1;
  }

  printf("Result: %f\n", acos(args.args[0]));
  return 0;
}

int tangent(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: tangent expects 1 argument but got %d\n", args.length);
    return 1;
  }

  printf("Result: %f\n", tan(args.args[0]));
  return 0;
}

int hyperbolic_tangent(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: hyperbolic_tangent expects 1 argument but got %d\n",
           args.length);
    return 1;
  }

  printf("Result: %f\n", tanh(args.args[0]));
  return 0;
}

int arc_tangent(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: arc_tangent expects 1 argument but got %d\n", args.length);
    return 1;
  }

  printf("Result: %f\n", atan(args.args[0]));
  return 0;
}

int cotangent(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: cotangent expects 1 argument but got %d\n", args.length);
    return 1;
  }

  printf("Result: %f\n", cos(args.args[0]) / sin(args.args[0]));
  return 0;
}

int hyperbolic_cotangent(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: hyperbolic_cotangent expects 1 argument but got %d\n",
           args.length);
    return 1;
  }

  printf("Result: %f\n", cosh(args.args[0]) / sinh(args.args[0]));
  return 0;
}

int arc_cotangent(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: arc_cotangent expects 1 argument but got %d\n", args.length);
    return 1;
  }

  printf("Result: %f\n", atan(1 / args.args[0]));
  return 0;
}

int secant(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: secant expects 1 argument but got %d\n", args.length);
    return 1;
  }

  // TODO wrong
  printf("Result: %f\n", 1 / cos(args.args[0]));
  return 0;
}

int hyperbolic_secant(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: hyperbolic_secant expects 1 argument but got %d\n",
           args.length);
    return 1;
  }

  // TODO wrong
  printf("Result: %f\n", 1 / cosh(args.args[0]));
  return 0;
}

int arc_secant(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: arc_secant expects 1 argument but got %d\n", args.length);
    return 1;
  }

  printf("Result: %f\n", acos(1 / args.args[0]));
  return 0;
}

// source for (O(sqrt(n))) algorithm:
// https://www.rookieslab.com/posts/fastest-way-to-check-if-a-number-is-prime-or-not
int is_prime(FloatArguments args) {
  if (args.length != 1) {
    printf("ERROR: is_prime expects 1 argument but got %d\n", args.length);
    return 1;
  }

  // TODO check if argument is natural number
  int number = (int)args.args[0];

  if (number < 0) {
    printf("Result: %d is not prime. Negative numbers are never prime.\n", number);
    return 0;
  }

  if (number == 1) {
    printf("Result: %d is not prime\n", number);
    return 0;
  }

  int counter = 2;
  while (counter * counter <= number) {
    if (number % counter == 0) {
      printf("Result: %d is not prime\n", number);
      return 0;
    }
    counter++;
  }

  printf("Result: %d is prime\n", number);

  return 0;
}

int factorial(FloatArguments args) {
  // TODO not working for non-integers
  if (args.length != 1) {
    printf("ERROR: factorial expects 1 argument but got %d\n", args.length);
    return 1;
  }

  if (args.args[0] < 0) {
    printf("ERROR: factorial is not defined for negative numbers");
    return 1;
  }

  if (args.args[0] == 0) {
    printf("Result: %f\n", 1.0f);
    return 0;
  }

  float counter = args.args[0] - 1;
  float result = args.args[0];

  for (int i = counter; i > 1; --i) {
    result = result * i;
  }

  printf("Result: %f\n", result);
  return 0;
}

// expressions
// basic math 7 * 4 (-2 / 3) AND 4^2 - 3
