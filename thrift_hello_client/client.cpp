#include <stdio.h>
#include <string>
#include <thrift/transport/TSocket.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include "Hello_types.h"
#include "HelloService.h"
#include "Hello_constants.h"
using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace HelloThrift::Interface;
using std::shared_ptr;

int main(int argc, char** argv)
{
	std::shared_ptr<TTransport> socket(new TSocket("10.130.161.120", 9090));
	std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
	HelloServiceClient client(protocol);
	try
	{
		transport->open();
		std::string para = "cpper.info";
		std::string _return;
		client.HelloString(_return,para);
		printf("%s\n", _return.c_str());
		client.HelloVoid();
		client.HelloBoolean(true);
		transport->close();
	}
	catch (TException& tx)
	{
		printf("ERROR:%s\n", tx.what());
	}
}