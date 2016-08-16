#include "Controller.h"
#include <unistd.h>

void Controller::delay(int milsec){
	usleep(100 * milsec);
}