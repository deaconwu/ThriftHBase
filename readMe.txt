1.boost库
   从官网下载安装 https://dl.bintray.com/boostorg/release/1.64.0/binaries/ ，配置环境变量
   
2.openssl库
   从官网下载安装 http://downloads.datastax.com/cpp-driver/windows/，静态库文件libeay32.lib和ssleay32.lib
   
3.thrift库
   从官网下载安装 https://thrift.apache.org/download，用VS打开lib/cpp/thrift.sln，编译生成libthrift
   
4.VS工程“thrift_hello_client”和“thrift_hello_server”分别为本地客户端和服务端通信Demo

5.VS工程“thrift_hbase_putget”为客户端通过thrift接口对HBase服务器数据库进行访问和读写
   