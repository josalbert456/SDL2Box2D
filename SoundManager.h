#ifndef __SOUNDMANAGER__
#define __SOUNDMANAGER__
#include <ao/ao.h>
#include <iostream>
#include <string.h>
#include <sndfile.h>
class SoundManager{
public:
	SoundManager(){
		ao_initialize();
		int driverId = ao_default_driver_id();
		if(driverId<0){
			std::cout << "No Default Device\n" << std::endl;			
		}
		bufferIndex = 0;
		readSoundInfo();
		ad = ao_open_live(driverId, &soundInfo, NULL);
		if(ad==NULL){
			printf("Open Live\n");
			return;
		}
	}
	~SoundManager(){}
	int loadSound(char *fileName);
	void playSound(int index);
	void readSoundInfo();
	void close();
	
	char *buffer[100];
	int bufferIndex;
	long fileLength[100];
	ao_sample_format soundInfo;
	ao_device *ad;
};

#endif