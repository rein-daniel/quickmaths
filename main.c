#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int length;
  float *args;
} Arguments;

void print_manual();
Arguments convert_arguments_to_floats(int argc, char **argv);

int add(Arguments args);

// argc -> number of arguments
// argv -> arguments, first one being the path
int main(int argc, char **argv) {
  if (argc < 2) {
    print_manual();
    return 0;
  }

  // commands
  char *cmd = argv[1];
  if (strcmp(cmd, "add") == 0 || strcpy(cmd, "sum") == 0) {
    return add(convert_arguments_to_floats(argc, argv));
  }
  if (strcmp(cmd, "sub") == 0) {
    printf("its sub\n");
    return 0;
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

Arguments convert_arguments_to_floats(int argc, char **argv) {
  Arguments result;
  // qm command -> 0 and 1
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

int add(Arguments args) {
  printf("ADD\n");
  float result = 0;
  for (int i = 0; i < args.length; ++i) {
    result = result + args.args[i];
  }
  printf("Result: %f\n", result);
  return 0;
}

// expressions
