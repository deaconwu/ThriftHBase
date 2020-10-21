1.下载thrift
   http://thrift.apache.org/download

2.下载的thrift-0.13.0.exe重新命名为thrift.exe后放到Thrift文件夹下

3. 配置环境变量Path

4. 检查是否安装成功
   cmd-->thrift -version

5. 下载hbase.thrift
    https://github.com/apache/hbase/blob/master/hbase-thrift/src/main/resources/org/apache/hadoop/hbase/thrift2/hbase.thrift
	
6. 生成供客户端使用的文件
    执行命令“thrift --gen cpp hbase.thrift”，生成以下文件
	THBaseService.h THBaseService.cpp hbase_types.h hbase_types.cpp hbase_constants.h hbase_constants.cpp