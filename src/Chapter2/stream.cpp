#include <iostream>
#include <boost/asio.hpp>

int main()
{
    boost::asio::streambuf buf;
    std::ostream output(&buf);

    //Writing the message to the stream-based buffer.
    output << "Message1\nMessage2";
    
    //Now we want to read all data from a streambuf
    //until '\n' delilmiter.
    //Instantiate an nput stream wichi uses our
    //stream buffer.
    std::istream input(&buf);

    //We'll read data into this string.
    std::string message1;
    std::getline(input,message1);

    //Now message1 string contains 'Message1'.
    std::cout <<message1<<"\n";
    return 0;
}