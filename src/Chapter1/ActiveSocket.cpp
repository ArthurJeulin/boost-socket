#include <iostream>
#include <boost/asio.hpp>

int main()
{
    // Step 1. An instance of'io_service' class is required by
    //        socket constructor.
    // This class is a central component in the Boost.asio I/O i
    // infrastructure. It provides access to the network I/O services
    // of the underlying operating system.
    boost::asio::io_service ios;
    
    // Step 2. Creating an object of 'tcp' class representing
    //         a TCP protocol with IPv4 as underlying protocol.
    boost::asio::ip::tcp protocol = boost::asio::ip::tcp::v4();

    // Step 3. Instantiating an active TCP socket object.
    boost::asio::ip::tcp::socket sock(ios);

    // Used to store information error that happens
    // while opening the socket.
    boost::system::error_code ec;

    // Step 4. Opening the socket.
    //socket is allocated when we call the open() method
    sock.open(protocol,ec);

    if(ec.value()!=0)
    {
        //Failed to open the socket.
        std::cout 
            << "Failed to open the socket! Error code ="
            << ec.value() << ". Message: " << ec.message();
            return ec.value();
    } 
    return 0;
}