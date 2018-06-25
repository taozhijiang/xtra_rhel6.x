
### boost 
##### debug:
./b2 threading=multi link=static runtime-link=static variant=debug
##### release:
./b2 threading=multi link=static runtime-link=static variant=release

### libevent & libevent2
##### debug:
bash autogen.sh
CFLAGS=-DUSE_DEBUG ./configure --disable-shared && make && make install
##### release
bash autogen.sh
./configure --disable-debug-mode --disable-shared && make && make install

### thrift 
./configure --enable-shared=no --with-boost=/home/nicol/workDir/Incubator/xtra_rhel6.x/ --with-boost-libdir=/home/nicol/workDir/Incubator/xtra_rhel6.x/libs/debug/boost/ --without-php  --without-python --without-erlang


