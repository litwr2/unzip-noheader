#ifndef BASE64_STRING_H
#define BASE64_STRING_H

#include <string>
#include <sstream>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/insert_linebreaks.hpp>
#include <boost/archive/iterators/remove_whitespace.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <boost/archive/iterators/ostream_iterator.hpp>
#include <boost/algorithm/string.hpp>
#include <bits/stl_algo.h>

namespace base64 {

const std::string base64_padding[] = {"", "==", "="};

namespace bai = boost::archive::iterators;

std::string encode(std::string s)
{
    std::stringstream os;

    // convert binary values to base64 characters
    typedef bai::base64_from_binary

    // retrieve 6 bit integers from a sequence of 8 bit bytes
    <bai::transform_width<char *, 6, 8> > base64_enc; // compose all the above operations in to a new iterator

    std::copy(base64_enc(s.c_str()), base64_enc(s.c_str() + s.size()), std::ostream_iterator<char>(os));
    os << base64_padding[s.size() % 3];
    return os.str();
}

std::string decode(std::string s)
{
    std::stringstream os;

    typedef bai::transform_width<bai::binary_from_base64<char * >, 8, 6>
      base64_dec;

    unsigned int size = s.size();

    while (size && s[size - 1] == '=')
        --size;

    if (size == 0) return std::string();

    std::string decoded_token(base64_dec(s.c_str()), base64_dec(s.c_str() + size));
    return decoded_token;

}

}
#endif
