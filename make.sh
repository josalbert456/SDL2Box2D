rm SmallProject
g++ -o SmallProject -I ../lib/ ../lib/*.cpp \
	-lSDL2 -lSDL2_image -lBox2D -lao -lsndfile \
	SteelChain.cpp Main.cpp