# framework common files, always required
vpath %.cpp z_framework/zf_common/
# framework sfml code. also required.
vpath %.cpp z_framework/zf_sfml/
# framework sfml animation code.
vpath %.cpp z_framework/zf_sfml/animations
# game code.
vpath %.cpp game/
# game screen code
vpath %.cpp game/screens/
vpath %.cpp game/world/
vpath %.cpp game/world/entity/
vpath %.cpp game/world/terrain/
vpath %.cpp game/world/states/
vpath %.cpp game/world/items/
vpath %.cpp game/world/items/itemtypecomps/
vpath %.cpp game/world/items/iteminstancecomps/
vpath %.o obj/

WARNING= -Wextra -Wno-switch -Wno-sign-compare -Wno-missing-braces -Wno-unused-parameter
OPTIMIZE= -fno-exceptions
BIN=treasurecrawl
BINFDR=bin/
CXX=clang++ #${WARNING}
SFML=-framework sfml-graphics -framework sfml-window -framework sfml-system -framework sfml-network
OBJDIR=obj

#zf framework 
zf_common = $(shell cd z_framework/zf_common ; ls *.cpp)
zf_commonobjs = $(patsubst %, $(OBJDIR)/%, $(zf_common:.cpp=.o))

zf_sfml = $(shell cd z_framework/zf_sfml ; ls *.cpp)
zf_sfmlobjs = $(patsubst %, $(OBJDIR)/%, $(zf_sfml:.cpp=.o))

zf_sfmlsub = $(shell cd z_framework/zf_sfml ; for F in `ls -d */`; do cd $$F ; ls *.cpp ; cd .. ; done)
zf_sfmlsubobjs = $(patsubst %, $(OBJDIR)/%, $(zf_sfmlsub:.cpp=.o))
# game code
game = $(shell cd game; ls *.cpp; for F in `ls -d */` ; do cd $$F; ls *.cpp; for E in `ls -d */`; do cd $$E; ls *.cpp; for G in `ls -d */` ; do cd $$G; ls *.cpp; cd ..; done; cd ..; done ; cd ..; done)
gameobjs = $(patsubst %,$(OBJDIR)/%,$(game:.cpp=.o))

main=obj/main.o

all: $(BIN)

$(BIN) : $(main) $(zf_commonobjs) $(zf_sfmlobjs) $(zf_sfmlsubobjs) $(zf_platformerobjs) $(zf_networkobjs) $(zf_networksubobjs) $(gameobjs)
	$(CXX) -o $(BIN) $(OBJDIR)/* $(SFML)

$(OBJDIR)/%.o : %.cpp
	$(CXX) -c -o $@ $^

obj/main.o : main.cpp 
	$(CXX) -c -o $@ $^

clean:
	rm obj/*.o
	rm $(BIN)

remake:
	make clean
	make all

debug:
	@echo $(zf_sfml)

.PHONY: clean remake debug
