#ifndef __UNZIP_NOHEADER_H__
#define __UNZIP_NOHEADER_H__

#include <sstream>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/zlib.hpp>

namespace ZipNoHeader {
    namespace bio = boost::iostreams;

    std::string decompress(const std::string& data)
    {
        bio::zlib_params params(bio::zlib::default_compression, bio::zlib::deflated,
                 bio::zlib::default_window_bits, bio::zlib::default_mem_level, 
                 bio::zlib::default_strategy, true, false);
	std::stringstream compressed(data);
	std::stringstream decompressed;

	bio::filtering_streambuf<bio::input> out;
	out.push(bio::zlib_decompressor(params));
	out.push(compressed);
	bio::copy(out, decompressed);

	return decompressed.str();
    }
};

#endif // __UNZIP_NOHEADER_H__
