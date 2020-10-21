#include <stdio.h>
#include <string>
#include <thrift/transport/TSocket.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <vector>
#include "THBaseService.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::hadoop::hbase::thrift;

int main(int argc, char** argv)
{
	std::shared_ptr<TTransport> socket(new TSocket("10.130.161.120", 9090));
	std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	try
	{
		transport->open();
		
		THBaseServiceClient client(protocol);

		TResult tresult;
		TGet get;
		std::vector<TColumnValue> cvs;
		const std::string table("swift");
		const std::string thisrow = "1";

		get.__set_row(thisrow);

		bool be = client.exists(table, get);
		printf("exists result value = %d\n", be);

		client.get(tresult, table, get);
		vector<TColumnValue> list = tresult.columnValues;
		std::vector<TColumnValue>::const_iterator iter;
		for (iter = list.begin(); iter != list.end(); iter++)
		{
			printf("%s, %s, %s\n", (*iter).family.c_str(), (*iter).qualifier.c_str(), (*iter).value.c_str());
		}

// 		TPut put;
// 		std::vector<TPut> puts;
// 		put.__set_row("1");
// 
// 		TColumnValue tcv;
// 		tcv.__set_family("info");
// 		tcv.__set_qualifier("age1");
// 		tcv.__set_value("30");
// 		tcv.__set_tags("1");
// 		cvs.insert(cvs.end(), tcv);
// 		put.__set_columnValues(cvs);
// 		puts.insert(puts.end(), put);
// 
// 		TColumnValue tcv1;
// 		tcv1.__set_family("info");
// 		tcv1.__set_qualifier("age2");
// 		tcv1.__set_value("20");
// 		tcv1.__set_tags("2");
// 		cvs.insert(cvs.end(), tcv1);
// 		put.__set_columnValues(cvs);
// 		puts.insert(puts.end(), put);
// 
// 		client.putMultiple(table, puts);
// 		puts.clear();

		transport->close();
	}
	catch (TException& tx)
	{
		printf("ERROR:%s\n", tx.what());
	}
}