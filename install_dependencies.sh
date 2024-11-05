
mkdir dependencies
curl -L https://github.com/OUIsolutions/CTextEngine/releases/download/v2.002/CTextEngine.h -o dependencies/CTextEngine.h
curl -L https://github.com/OUIsolutions/DoTheWorld/releases/download/v7.004/doTheWorld.h -o dependencies/doTheWorld.h
curl -L https://github.com/OUIsolutions/Universal-Garbage-Colector/releases/download/v2.003/UniversalGarbage.h -o dependencies/UniversalGarbage.h
rm -rf SilverChain
git clone -b v0.06 https://github.com/OUIsolutions/SilverChain.git
gcc  SilverChain/src/main.c -o silverchain.o
