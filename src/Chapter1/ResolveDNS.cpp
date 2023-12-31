#include <iostream>
#include <boost/asio.hpp>
#include <string>

int main()
{
    //Step 1. Assume that the client application has already
    //        obtained the DNS name and protocol port number and
    //        represented them as strings
    std::string host = "samplehost.com";
    std::string port_number ="3333";

    //Step 2.
    boost::asio::io_service ios;

    //Step 3. Creating a query
    boost::asio::ip::tcp::resolver::query resolver_query(host,
    port_number, boost::asio::ip::tcp::resolver::query::numeric_service);

    //Step 4. Creating a resolver
    boost::asio::ip::tcp::resolver resolver(ios);

    //used to store information about error that happends
    // during resolution process.
    boost::system::error_code ec;

    //Step 5. 
    boost::asio::ip::tcp::resolver::iterator it = 
        resolver.resolve(resolver_query,ec);
    
    //Handling errors if any
    if(ec.value()!=0)
    {
        //Failed to resolve the DNS name. Breaking execution.
        std::cout
            <<"Failed to resolve a DNS name."
            <<"Error code = "<<ec.value()
            <<". Massage = "<< ec.message();
            return ec.value();
    }
    boost::asio::ip::tcp::resolver::iterator it_end;
    for(;it!= it_end;++it)
    {
        //Here we can access the endpoint like this.
        boost::asio::ip::tcp::endpoint ep = it->endpoint();
    }

    return 0;
}