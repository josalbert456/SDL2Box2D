#include "SoundManager.h"

int SoundManager::loadSound(char *fileName){
		FILE *file = fopen(fileName, "r");
		fseek(file, 0, SEEK_END);
		fileLength[bufferIndex] = ftell(file);
		rewind(file);
		buffer[bufferIndex] = (char *)malloc(sizeof(char) * fileLength[bufferIndex]);
		memset(buffer[bufferIndex], 0, fileLength[bufferIndex]);
		fread(buffer[bufferIndex], fileLength[bufferIndex], 1, file);			
		bufferIndex++;
		fclose(file);

		SF_INFO si;
		SNDFILE *sf = sf_open(fileName, SFM_READ, &si);
		soundInfo.rate = si.samplerate;
		soundInfo.channels = si.channels;
		
		return bufferIndex - 1;
	}
void SoundManager::playSound(int index){		
	ao_play(ad, buffer[index], fileLength[index]);		
}
void SoundManager::readSoundInfo(){
	soundInfo.bits = 16;
	soundInfo.rate = 44100;
	soundInfo.channels = 2;
	soundInfo.byte_format = AO_FMT_NATIVE;
	soundInfo.matrix = "L,R";		
}
void SoundManager::close(){
	ao_close(ad);
	for(int i=0; i<bufferIndex; i++){
		if(buffer[i]!=NULL){
			free(buffer[i]);
		}
	}
}