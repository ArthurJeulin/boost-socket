#include <iostream>
#include <boost/asio.hpp>

void writeToSocket(boost::asio::ip::tcp::socket& sock){
    //Step2. allocation and filling the buffer.
    std::string buf;
    buf = "Hello";

    std::size_t total_bytes_written = 0;

    //Step 3. Run the loop until all data is written
    //to the socket.
    while(total_bytes_written!= buf.length())
    {
        total_bytes_written += sock.write_some(
            boost::asio::buffer(buf.c_str() +
             total_bytes_written,
             buf.length()-total_bytes_written));    
    }
}

int main()
{
    std::string raw_ip_address = "127.0.0.1";
    unsigned short port_num = 3333;
    try
    {
        boost::asio::ip::tcp::endpoint
          ep(boost::asio::ip::address::from_string(raw_ip_address),
          port_num);
          boost::asio::io_service ios;

          //Step 1. Allocating and opening the socket.
          boost::asio::ip::tcp::socket sock(ios,ep.protocol());

          sock.connect(ep);
          writeToSocket(sock);
    }
    catch(const boost::system::system_error& e)
    {
        std::cout 
        <<"Error occured! Error code =" << e.code()
        << ". Message: " <<e.what();
        return e.code().value(); 
    }
    
    return 0;
}