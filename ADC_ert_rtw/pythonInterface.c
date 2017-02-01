#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/select.h>

//typedef float real_T;

typedef struct Inputs {
  real_T arg_Magnetic_Measure[3];
  real_T arg_Euler_Angle_Measure[3];
  real_T arg_Sun_Measure[3];
  real_T arg_epoch[6];
  real_T arg_lla[3];
  real_T local_arg_S_flag;
} INPUT_ARGS;


int inputAvailable() {
  struct timeval tv;
  fd_set fds;
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);
  select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
  return (FD_ISSET(0, &fds));
}

double *getfloats(int count, double *values)
{
  char *linebuf;
  ssize_t size, n = 256;
  char *saveptr, *token, *str1, *endptr;
  int j;

  linebuf = malloc(256);
  size = getline(&linebuf, &n, stdin);
  //printf("Size = %ld, contents = \"%s\"\n", size, linebuf);

  if (count <= 0) return NULL;

  for (j = 0, str1 = linebuf; j < count; j++, str1 = NULL) {
    token = strtok_r(str1, ",", &saveptr);
    if (token == NULL) return NULL;
    //printf("Field %d: %s\n", j + 1, token);
    values[j] = strtod(token, &endptr);
    if (errno != 0) return NULL;
    //printf("values[%d] = %lf\n", j, values[j]);
  }
  return values;
}
#define VALUE_COUNT 19

double *valueBuffer = NULL;

INPUT_ARGS *pageForValues(INPUT_ARGS *input)
{
  int gotValidInput = 0;
  int i;
  double *retval;
  if (valueBuffer == NULL) valueBuffer = malloc(sizeof(double) * VALUE_COUNT);
  while (1) {
    gotValidInput = 0;
    if (inputAvailable()) {
      //printf("Input is available, reading stdin...\n");
      retval = getfloats(VALUE_COUNT, valueBuffer);
      if (retval == NULL) {
        //printf("getfloats() returned NULL\n");
        return NULL;
      }
      else {
        gotValidInput = 1;
      }
    }
    // Call the existing function somewhere in here, not sure how to handle new args vs. no new args...
    if (gotValidInput) {
      input->arg_Magnetic_Measure[0] = (float)valueBuffer[0];
      input->arg_Magnetic_Measure[1] = (float)valueBuffer[1];
      input->arg_Magnetic_Measure[2] = (float)valueBuffer[2];

      input->arg_Euler_Angle_Measure[0] = (float)valueBuffer[3];
      input->arg_Euler_Angle_Measure[1] = (float)valueBuffer[4];
      input->arg_Euler_Angle_Measure[2] = (float)valueBuffer[5];

      input->arg_Sun_Measure[0] = (float)valueBuffer[6];
      input->arg_Sun_Measure[1] = (float)valueBuffer[7];
      input->arg_Sun_Measure[2] = (float)valueBuffer[8];

      input->arg_epoch[0] = (float)valueBuffer[9];
      input->arg_epoch[1] = (float)valueBuffer[10];
      input->arg_epoch[2] = (float)valueBuffer[11];
      input->arg_epoch[3] = (float)valueBuffer[12];
      input->arg_epoch[4] = (float)valueBuffer[13];
      input->arg_epoch[5] = (float)valueBuffer[14];

      input->arg_lla[0] = (float)valueBuffer[15];
      input->arg_lla[1] = (float)valueBuffer[16];
      input->arg_lla[2] = (float)valueBuffer[17];

      input->local_arg_S_flag = (float)valueBuffer[18];

      return input;
    }
    return NULL;
  }
}
/*
int main(int argc, char *argv[]){
  INPUT_ARGS *args = malloc(sizeof(INPUT_ARGS));
  INPUT_ARGS *result = NULL;
  while (1) {
    result = pageForValues(args);
    if (result != NULL) {
      printf("   Magnetic: [%f, %f, %f]\n", result->arg_Magnetic_Measure[0], args->arg_Magnetic_Measure[1], result->arg_Magnetic_Measure[2]);
      printf("Euler Angle: [%f, %f, %f]\n", result->arg_Euler_Angle_Measure[0], result->arg_Euler_Angle_Measure[1], result->arg_Euler_Angle_Measure[2]);
      printf("        Sun: [%f, %f, %f]\n", result->arg_Sun_Measure[0],f result->arg_Sun_Measure[1], result->arg_Sun_Measure[2]);
      printf("      Epoch: [%f, %f, %f, %f, %f, %f]\n", result->arg_epoch[0], result->arg_epoch[1], result->arg_epoch[2], result->arg_epoch[3], result->arg_epoch[4], result->arg_epoch[5]);
      printf("        LLA: [%f, %f, %f]\n", result->arg_lla[0], result->arg_lla[1], result->arg_lla[2]);
      printf("     S Flag: [%f]\n", result->local_arg_S_flag);
    }
  }
  
}
*/