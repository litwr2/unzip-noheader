# unzip-noheader
Such messages are used, for example, by bittrex exchange market.  This program uses standard input channel.

Usage examples:

   * unzip-header <message.txt
   * cat message.txt | unzip-header
             
Indeed it can be used with the message stream.

## Compilation
Edit CMakeLists.txt file at first - write a proper path for the boost library include files installed at your system. Run **cmake .** and then **make**.  Make sure that you have C++ and boost, ssl, and zlib libraries installed.
