#include <iostream>
#include <boost/asio.hpp>
/*
    The following code xample demonstrates possible 
    implementation of the algorithm. Note that it is
    assumed that the server application is going to 
    coomunicate over the IPv6 protocoll.
*/
int main()
{
    //Step1. Here we assume that the server applicatio has
    //       already obtained the protocol port number.
    unsigned short port_number = 3333;
    //Step2. Create special object of boost::asio::ip::address class
    //       that specifies all IP-addressses available on the host.
    //       Note that here we assume that server works onver IPv6 protocol.
    boost::asio::ip::address ip_address = boost::asio::ip::address_v6::any();
    //Step3. 
    boost::asio::ip::tcp::endpoint ep(ip_address,port_number);
    //Step4. Then endpoint is created and can be used to
    //       specify the IP addresses and a port number
    //       on which the server application wants to 
    //       listen for incoming connections.
    return 0;
}