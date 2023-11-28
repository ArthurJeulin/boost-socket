#include <iostream>
#include <boost/asio.hpp>
/*
    Learning Network programming with Boost/asio
    Client application.
*/
int main()
{
    //Step 1. Assume that the client application has already
    //        obtained the IP-address and the protocol port number.
    std::string raw_ip_raddress = "127.0.0.1";
    unsigned short port_num = 3333;

    //Used to store information about error that happens
    // while parsing the raw IP-address.
    boost::system::error_code ec;

    //Step 2. Using IP protocol version independant address
    //        representation.
    //Here we can work with IPv4 and IPv6 addresses
    //We are creating an Boost::Asio::IP::Address Object
    boost::asio::ip::address ip_address = boost::asio::ip::address::from_string(raw_ip_raddress,ec);
    if(ec.value()!= 0)
    {
        //Provided IP address is invalid. Breaking execution.
        std::cout 
            <<"Failed to parse the IP address. Error code ="
            <<ec.value() <<". Message: "<<ec.message();
            return ec.value();
    }

    //Step 3.
    //Here we instanciate a boost::asio::ip::tcp::endpoint class
    boost::asio::ip::tcp::endpoint ep(ip_address,port_num);

    //Step 4. The endpoint is ready and can be used to specify a
    //        particular server in the network the client wants to
    //        communicate with.

    return 0;
}
