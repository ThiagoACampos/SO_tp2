#include "types.h"
#include "user.h"
#include "date.h"

int stdout = 1;
int stderr = 2;

int
main(int argc, char *argv[])
{
  
  // Testar tempo de usuário e tempo de sistema equilibrados
  if(strcmp("1",argv[2]) == 0){
    float x = 0.0;
    float pi = 3.141573;

    for (int i = 0; i < 150; i++){
        sleep(1);
    }

    for (int i = 0; i < 99999; i++){
        for (int j = 0; j < 1000; j++){
        x += pi*pi;
        }
    }

    printf(1, "%d\n", x);
  // Testar tempo de sistema 
  }else if(strcmp("2",argv[2]) == 0){

      for (int i = 0; i < 100; i++){
          sleep(2);
      }
  // Testar tempo de usuário 
  }else if(strcmp("3",argv[2]) == 0){
      float j = 0;
      for (int i = 0; i < 10000; i++){
          for(int k=0; k < 60000; k++){
              j += k+i*i*k;
          }
      }

      printf(1,"%d\n", j);
  }

  exit();
}