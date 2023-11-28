#include <iostream>
#include <string>
#include <boost/asio.hpp>

int main()
{
    //Step 1. Assume that the client application has already
    //        obtained the DNS name and protocol port number and
    //        reprenseted them as strings.
    std::string host ="samplehost.book";
    std::string port_num ="3333";

    //Used by 'resolver' and a 'socket'
    boost::asio::io_service ios;

    //Creaating a resolver's query
    boost::asio::ip::tcp::resolver::query resolver_query(host, port_num, 
    boost::asio::ip::tcp::resolver::query::numeric_service);
    //Creating a resolver.
    boost::asio::ip::tcp::resolver resolver(ios);
    try
    {
        boost::asio::ip::tcp::resolver::iterator it = resolver.resolve(resolver_query);
        //Step 3. Creating a socket.
        boost::asio::ip::tcp::socket sock(ios);
        //Step 4. boost::asio::conect() method iterates over
        //        each endpoint until successfully connects to one
        //        of them. It will throuw an exception if it fails
        //        to connect to all the endpoints or if other
        //        erro occurs.
        boost::asio::connect(sock,it);
        //At this point socket'sock' is connected to 
        //the server application and can be used
        //to send data to or receive data from it.
    }
    //Overloads of boost::asio::ip::tcp::resolver::resolve and
    // boost::asio::conect() used here condition.
    catch(boost::system::system_error &e)
    {
        std::cout << "Error occured!"
                  << "Error code ="<< e.code()
                  << ". Message: "<< e.what();
        //return e.code().what();
    }
    
    return 0;
}