#include <iostream>
#include <boost/asio.hpp>

std::string readFromSocket(boost::asio::ip::tcp::socket& sock){
    const unsigned char MESSAGE_SIZE = 7;
    char buf[MESSAGE_SIZE] ;
    std::size_t total_bytes_read = 0;
    while (total_bytes_read!= MESSAGE_SIZE)
    {
        total_bytes_read += sock.read_some(boost::asio::buffer(buf + total_bytes_read,
        MESSAGE_SIZE - total_bytes_read));
    }
    return std::string(buf, total_bytes_read);
}

int main()
{
    std::string raw_ip_address ="127.0.0.1";
    unsigned short port_num = 3333;
    try
    {
        boost::asio::ip::tcp::endpoint
        ep(boost::asio::ip::address::from_string(raw_ip_address),
        port_num);
        boost::asio::io_service ios;
        boost::asio::ip::tcp::socket sock(ios, ep.protocol());
        sock.connect(ep);
        readFromSocket(sock);
    }
    catch(const boost::system::system_error& e)
    {
<<<<<<< HEAD
        std::cout << "Error-occured !"
=======
        std::cout << "Il y a un problème ici"
>>>>>>> test-conflict
                  << "Error code = "<< e.code()
                  <<". Message: " << e.what();
        return e.code().value();
    }
    return 0;
    
}